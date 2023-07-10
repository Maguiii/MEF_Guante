#include <Arduino.h>

/*Solo envia mensajes si se esta pulsando, no avisa si se deja de pulsar

   FUNCIONA CON EL PROGRAMA MEF_SuperGuanti

   PROBAR SI ANDA MAS RAPIDO LA GRUA AL SACAR EL DELAY
   
*/
#define FALSE 0
#define TRUE 1

#define menique A0 //derecha
#define anular A1

//estos estan conectados
#define indice A2 //izquierda
#define mayor A3
#define pulgar A4 


void setup() {
  
   pinMode(menique, INPUT);
   pinMode(anular, INPUT);
   pinMode(indice, INPUT);
   pinMode(mayor, INPUT);
   pinMode(pulgar, INPUT);

   Serial.begin(57600); // Configura la comunicación serial con el módulo HC-05

}

void loop() {

   if(digitalRead(menique)== HIGH){
      Serial.write('1');
      delay(100)
   }
   if(digitalRead(indice)== HIGH){
      Serial.write('3');
      delay(100);
   }
   if(digitalRead(mayor)== HIGH){
      Serial.write('5');
      delay(100);
   }
   if(digitalRead(anular)== HIGH){
      Serial.write('7');
      delay(100);
   }
   if(digitalRead(pulgar)== LOW){
      Serial.write('9');
      delay(100);
   }
}
