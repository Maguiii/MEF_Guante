#include <Arduino.h>
/*
  No esta probado que funcione la cuenta ni el envio de datos sobre las pulsaciones de cada dedo
*/
#define indice  A0
#define mayor   A1 
#define anular  A2
#define menique A3
#define pulgar  A4

int contIndice = 0;
int contMayor = 0;
int contAnular = 0;
int contMenique = 0;
int contPulgar = 0;

int estadoPrograma = 0;

int estadoIndice = 0;
int estadoMayor = 0;
int estadoAnular = 0;
int estadoMenique = 0;
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

   switch (estadoPrograma)
   {
      case 0:
         if(digitalRead(indice) == HIGH || digitalRead(mayor) == HIGH || digitalRead(anular) == HIGH || digitalRead(menique) == HIGH || digitalRead(pulgar) == HIGH){
            estadoPrograma = 0;
         }
         else{
            estadoPrograma = 1;
         }

         if(digitalRead(indice)== HIGH){
            Serial.println("derecha");
            delay(100);

            switch (estadoIndice){
               case 0:
                  if(digitalRead(indice) == HIGH){
                     estadoIndice = 1;
                  }
               break;
               case 1:
                  if(digitalRead(indice) == LOW){
                     contIndice++;
                     estadoIndice = 0;
                  }
               break;
            }
         }
         if(digitalRead(mayor)== HIGH){
            Serial.println("izquierda");
            delay(100);

            switch (estadoMayor)
            {
               case 0:
                  if(digitalRead(mayor) == HIGH){
                     estadoMayor = 1;
                  }
               break;
               case 1:
                  if(digitalRead(mayor) == LOW){
                     contMayor++;
                     estadoMayor = 0;
                  }
               break;
            }
         }
         if(digitalRead(anular)== HIGH){
            Serial.println("adelante");
            delay(100);

            switch (estadoAnular)
            {
               case 0:
                  if(digitalRead(anular) == HIGH){
                     estadoAnular = 1;
                  }
               break;
               case 1:
                  if(digitalRead(anular) == LOW){
                     contAnular++;
                     estadoAnular = 0;
                  }
               break;
            }
         }
         if(digitalRead(menique)== HIGH){
            Serial.println("atras");
            delay(100);

            switch (estadoMenique)
            {
               case 0:
                  if(digitalRead(menique) == HIGH){
                     estadoMenique = 1;
                  }
               break;
               case 1:
                  if(digitalRead(menique) == LOW){
                     contMenique++;
                     estadoMenique = 0;
                  }
               break;
            }
         }         
         if(digitalRead(pulgar)== HIGH){
            Serial.println("abajo");
            delay(100);

            switch (estadoPulgar)
            {
               case 0:
                  if(digitalRead(pulgar) == HIGH){
                     estadoPulgar = 1;
                  }
               break;
               case 1:
                  if(digitalRead(pulgar) == LOW){
                     contPulgar++;
                     estadoPulgar = 0;
                  }
               break;
            }
         }
      break;
      case 1:
         String cadenaIndice = String(contIndice);
         String cadenaMayor= String(contMayor);
         String cadenaAnular = String(contAnular);
         String cadenaMenique = String(contMenique);
         String cadenaPulgar = String(contPulgar);

         Serial.print(contIndice);
         Serial.print(contMayor);
         Serial.print(contAnular);
         Serial.print(contMenique);
         Serial.print(contPulgar);

         if(digitalRead(indice) == HIGH || digitalRead(mayor) == HIGH || digitalRead(anular) == HIGH || digitalRead(menique) == HIGH || digitalRead(pulgar) == HIGH)
            estadoPrograma = 0;
      break;
   }
}