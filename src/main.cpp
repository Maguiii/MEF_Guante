#include <Arduino.h>
/*
   Arreglar este programa que esta horrible

   La parte de contar pulsaciones esta mal asi no funciona el bluetooth

   (Solo envia mensajes si se esta pulsando, no avisa si se deja de pulsar)

   FUNCIONA CON EL PROGRAMA MEF_SuperGuanti

   Los pines ya estan declarados para usar con la plaqueta
*/
#define menique A0
#define anular A1
#define indice A2
#define mayor A3
#define pulgar A4

int menique = 0;
int anular = 0;
int mayor = 0;
int indice = 0;
int pulgar = 0;

int estadoPrograma = 0;
int estadoMenique = 0;
int estadoIndice = 0;
int estadoMayor = 0;
int estadoAnular = 0;
int estadoPulgar = 0;

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
      delay(100);

      switch(estadoMenique){
         /*Cuando se deja de pulsar el touch del menique se aumenta en uno la variable menique y se envia esa variable 
           Esto no esta probado, hay que revisar si el serial funciona asi (es decir si se pueden mandar dos datos al mismo tiempo y como)
         */
         case 0:
            if(digitalRead(menique) == LOW) //Mientras no este pulsado
               estadoMenique = 0;
            else
               estadoMenique = 1;
         break;
         case 1: 
            if(digitalRead(menique) == HIGH) //Mientras este pulsado
               estadoMenique = 1;
            else{
               menique++;
               Serial.write(menique);
               estadoMenique = 0;
            }
         break;
      }
   }
   if(digitalRead(indice)== HIGH){
      Serial.write('3');
      delay(100);

      switch(estadoIndice){
         /*Cuando se deja de pulsar el touch del menique se aumenta en uno la variable menique y se envia esa variable 
           Esto no esta probado, hay que revisar si el serial funciona asi (es decir si se pueden mandar dos datos al mismo tiempo y como)
         */
         case 0:
            if(digitalRead(indice) == LOW) //Mientras no este pulsado
               estadoIndice = 0;
            else
               estadoIndice = 1;
         break;
         case 1: 
            if(digitalRead(indice) == HIGH) //Mientras este pulsado
               estadoIndice = 1;
            else{
               indice++;
               Serial.write(indice);
               estadoIndice = 0;
            }
         break;
      }
   }
   if(digitalRead(mayor)== HIGH){
      Serial.write('5');
      delay(100);

      switch(estadoMayor){
         /*Cuando se deja de pulsar el touch del menique se aumenta en uno la variable menique y se envia esa variable 
           Esto no esta probado, hay que revisar si el serial funciona asi (es decir si se pueden mandar dos datos al mismo tiempo y como)
         */
         case 0:
            if(digitalRead(mayor) == LOW) //Mientras no este pulsado
               estadoMayor = 0;
            else
               estadoMayor = 1;
         break;
         case 1: 
            if(digitalRead(mayor) == HIGH) //Mientras este pulsado
               estadoMayor = 1;
            else{
               mayor++;
               Serial.write(mayor);
               estadoMayor = 0;
            }
         break;
      }
   }
   if(digitalRead(anular)== HIGH){
      Serial.write('7');
      delay(100);

      switch(anular){
         /*Cuando se deja de pulsar el touch del menique se aumenta en uno la variable menique y se envia esa variable 
           Esto no esta probado, hay que revisar si el serial funciona asi (es decir si se pueden mandar dos datos al mismo tiempo y como)
         */
         case 0:
            if(digitalRead(anular) == LOW) //Mientras no este pulsado
               estadoAnular = 0;
            else
               estadoAnular = 1;
         break;
         case 1: 
            if(digitalRead(anular) == HIGH) //Mientras este pulsado
               estadoAnular = 1;
            else{
               anular++;
               Serial.write(anular);
               estadoAnular = 0;
            }
         break;
      }
   }
   if(digitalRead(pulgar)== HIGH){
      Serial.write('9');
      delay(100);

      switch(estadoPulgar){
         /*Cuando se deja de pulsar el touch del menique se aumenta en uno la variable menique y se envia esa variable 
           Esto no esta probado, hay que revisar si el serial funciona asi (es decir si se pueden mandar dos datos al mismo tiempo y como)
         */
         case 0:
            if(digitalRead(pulgar) == LOW) //Mientras no este pulsado
               estadoPulgar = 0;
            else
               estadoPulgar = 1;
         break;
         case 1: 
            if(digitalRead(pulgar) == HIGH) //Mientras este pulsado
               estadoPulgar = 1;
            else{
               pulgar++;
               Serial.write(pulgar);
               estadoPulgar = 0;
            }
         break;
      }
   }
}