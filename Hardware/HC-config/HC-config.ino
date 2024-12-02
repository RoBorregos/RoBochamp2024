//   HC-05 AT Commands
//   Function                | Command                  | Response         | Parameter
//   Test                    | AT                       | OK               | None
//   Name                    | AT+NAME?                 | +NAME:HC-05, OK  | HC-05 (Default)
//   Password                | AT+PSWD?                 | +PSWD:1234, OK   | 1234 (Default)
//   Change Name             | AT+NAME = <name>         | OK               | None
//   Change Password         | AT+PSWD=<pswd>           | OK               | None
//   UART                    | AT+UART?                 | +UART:38400,0,0  | 38400 (Default
//   Connection mode         | AT+CMODE?                | +CMOD:<cmod>     | 0 (Default)<br>
//   Connection mode set     | AT+CMODE=<cmode>         | Ok               | (0 (Connect to a specified 
//   address)) >> (1 (Connect to any available address))
//   Find Address            | AT+ADDR?                 | +ADDR:<addr>, OK | None
//   Connect to Address      | AT+BIND=<addr>           | OK               | Replace the : with ,
//   Reset Device            | AT+RESET                 | OK               | None
//   Restore Factory Default | AT+ORGL                  | OK               | None


#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(10,11);                         // Definimos los pines RX y TX del Arduino conectados al Bluetooth
 
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(115200);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}