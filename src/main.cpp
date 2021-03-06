#include <mbed.h>
#include <USBSerial.h>
#include "shell.h"

#define ADXL345_ADDR  0xA6
#define ADXL345_DEVID 0x00

// L'I2C2 (Broches 0 et 1)
       // SDA  SCL
I2C i2c(PB_11, PB_10);

DigitalOut usbDisconnect(PB_9);

uint8_t adxl345_read_byte(uint8_t register_addr)
{
  char cmd[1];
  cmd[0] = register_addr;
  i2c.write(ADXL345_ADDR, cmd, 1); // On écrit l'adresse du registre à lire (0x00 = DEVID)
  i2c.read(ADXL345_ADDR, cmd, 1); // On lit un octet (l'esclave parle et remplit le tableau)

  return cmd[0];
}

SHELL_COMMAND(devid, "Lis DEVID")
{
  shell_println((int)adxl345_read_byte(ADXL345_DEVID)); // 229
}

// SHELL_COMMAND(devid, "Valeurs")
// {
//   char cmd[1];
//   while(1) {
//     cmd[0] = 0x01;
//     cmd[1] = ADXL345_DEVID;
//     i2c.write(ADXL345_ADDR, cmd, 2);

//     ThisThread::sleep_for(500ms);

//     cmd[0] = 0x00
//     i2c.write(ADXL345_ADDR, cmd, 1);
//     i2C.read(ADXL345_ADDR, cmd, 2);

//     float tmp = (float((cmd[0]<<8)|cmd[1]));
//     shell_println(tmp);
//   }
// }


int main()
{
    shell_init_usb();
    usbDisconnect = 0;

    while (true) {
        ThisThread::sleep_for(10);
    }
}
