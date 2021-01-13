#include <mbed.h>
#include <USBSerial.h>

/*
  Digital out : créer un port (une broche de sortie)

    - DigitalOut nomvariable(port);
*/
DigitalOut led(PA_7);//Ici il y a une led branchée sur le pin 4 de la mapple mini

DigitalOut usbDisconnect(PB_9);

int main()
{
    //USBSerial usbSerial;
    usbDisconnect = 0;//Pour que l'usb soit reconnu avec la mapple mini

    while (true) {
         led = 1;//Allumage de la led
        ThisThread::sleep_for(200);//Attente de 200 millisecondes
         led = 0;//Extinction de la led
        ThisThread::sleep_for(200);
    }
}
