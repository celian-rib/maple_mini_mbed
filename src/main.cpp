#include "mbed.h"
#include <USBSerial.h>

// Attention : brancher Vcc sur 5V (Vin)

DigitalOut usbDisconnect(PB_9);  // USB

DigitalIn  echo(PA_7);           // pin 4 
DigitalOut trigger(PA_6);        // pin 5

Timer timer;


int main()
{
    USBSerial usbSerial;
    usbDisconnect = 0;

    while(true) {

        timer.reset();//On met à zero le timer

		//Lancement d'un signal de 10us
        trigger = 1;
        wait_us(10);
        trigger = 0;

		//On attend que echo passe sur zero 
        while (echo==0) {}; 
        timer.start();//On lance le timer

        while (echo==1) {};//On attend que echo passe sur 1 
        timer.stop(); //On stop le timer

        int distance = (timer.read_us()*10)/58.0; // calcul de la distance en mm grace au temps final mesuré grace au timer

        usbSerial.printf(" %d mm \r\n",distance); // affichage distance 

        ThisThread::sleep_for(60);
    }
}
