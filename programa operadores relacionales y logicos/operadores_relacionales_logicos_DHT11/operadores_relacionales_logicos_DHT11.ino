/* Programa de ejemplos del uso de operadores relacionales y logicos 
 * Por: Jose Manuel Cartas
 * Fecha: 20 de abril de 2022
 * 
 * Simulador de refrigeracion de servidores
 *  
 * Este programa ejemplifica el uso de operadores relacionales y operadores
 * logicos:
 * 
 * Condiciones Iniciales
 * Sensor de temperatura y humedad
 * Boton1: Manual. Activa la refrigeración al ser presionado
 * Boton2: Alta demanda
 * Boton3: Sobre carga de funcionamiento
 * 
 * Led1: Refrigeracion manual
 * Led2: Refrigeración automática
 * 
 * -Que se encienda la refrigeracion manual cada que se presione el boton de manual
 * -La refrigeracion manual tiene prioridad a la refrigeracion automática.
 * -Si la termperatura es alta (mayor a 28, por ejemplo), se activa la refrigeracion automática
 * -Si tengo alta demanda o sobre carga, se activa la refrigeración automática
 * -Si tengo alta demanda o sobrecarga de funcionamiento y ademas temperatura alta, se activan ambas refrigeraciones
 * 
 * Conexiones 
 * Botones 14, 15, 13    
 * Leds 4, 2    
 * DHT11 12
 * 
 */

// Bibliotecas
#include "DHT.h"

// Constantes
#define DHTPIN 12
#define DHTTYPE DHT11

//Constantes de botones
const int BOTON1 = 14;
const int BOTON2 = 15;
const int BOTON3 = 13;
//Constantes de leds
const int LED1 = 4;
const int LED2 = 2;
//Nivel de temperatura
const int TEMP_H = 28;

// Variables

int boton1_dato;
int boton2_dato;
int boton3_dato;
float t;
long timenow, timelast;
int wait = 2000;
float lecturaDHT (float t);
//int lecturaBotones
//int ComparacionAND

// Definición de objetos
DHT dht(DHTPIN, DHTTYPE);

// Condiciones iniciales - Se ejecuta sólo una vez al energizar

void setup() {// Inicio de void setup ()
  // Aquí va tu código
  
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  //Configurar botones
  pinMode (BOTON1, INPUT_PULLUP);
  pinMode (BOTON2, INPUT_PULLUP);
  pinMode (BOTON3, INPUT_PULLUP);
  //Configurar Leds
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);

  dht.begin();//Iniciar comunicacion con el sensor DHT
  timelast=millis();

}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente

void loop() 
{// Inicio de void loop
  // put your main code here, to run repeatedly:
  //delay(2000);
  timenow = millis();

  if (timenow - timelast > wait)
  {
    timelast = timenow;
    lecturaDHT;
  }

 // lecturabotones();
 // logica();
  

  //*******Lectura del sensor*********
  // Read temperature as Celsius (the default)
 /* float t = dht.readTemperature();
   // Check if any reads failed and exit early (to try again).
  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.println(t);*/
  lecturaDHT(t);
/*
  //********Lectura del boton1********
  boton1_dato = digitalRead (BOTON1);
  if (boton1_dato == 1) {
    digitalWrite (LED1, LOW);
  } else {
    digitalWrite (LED1, HIGH);
  }

  //********Automático por temperatura, sobrecarga y alta demanda**********
  boton2_dato = digitalRead (BOTON2);
  boton3_dato = digitalRead (BOTON3);
  if (t > TEMP_H || boton2_dato == 1 || boton3_dato == 1) {
    digitalWrite (LED2, HIGH);
  } else {
    digitalWrite (LED2, LOW);
  }

*/

// comienza mi logica
//void lecturaDHT ();
boton1_dato = digitalRead (BOTON1);
boton2_dato = digitalRead (BOTON2);
boton3_dato = digitalRead (BOTON3);
    if (t<=TEMP_H )
    {
        
        if (boton1_dato==0)
            {
                digitalWrite (LED1, LOW);//Led manual=0;
                boton2_dato = digitalRead (BOTON2);
                boton3_dato = digitalRead (BOTON3);
                if (boton2_dato==0&&boton3_dato==0)
                    {   
                    digitalWrite (LED2, LOW); // Led auto=0;
                    }
                else
                    {
                    digitalWrite (LED2, HIGH); // led auto=1;
                    }
            }
        else
            {
                digitalWrite (LED1, HIGH);//Led manual=1;
                boton2_dato = digitalRead (BOTON2);
                boton3_dato = digitalRead (BOTON3);
                if (boton2_dato==0&&boton3_dato==0)
                    {
                    digitalWrite (LED2, LOW); //Led automatico=0
                    }
                else
                    {
                    digitalWrite (LED2, HIGH); //Led automatico=1
                    }
            }
    }
    else
    {
        digitalWrite (LED2, HIGH); //Led automatico=1
        boton1_dato = digitalRead (BOTON1);
        boton2_dato = digitalRead (BOTON2);
        boton3_dato = digitalRead (BOTON3);
        if (boton1_dato==0&&boton2_dato==0&&boton3_dato==0)
            {
            digitalWrite (LED1, LOW); //Led manual=0;
            }
        else
            {
            digitalWrite (LED2, HIGH); //Led automatico=1
            }
    }




  

}// Fin de void loop

// Funciones del usuario
float lecturaDHT(float t)
{
  float tempe = dht.readTemperature();
   // Check if any reads failed and exit early (to try again).
  if (isnan(t)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    //return;
  }
  Serial.println(t);
  return tempe;
}




// mi codigo en c
/*#include <stdio.h>



int
main ()
{
  int temp, b1, b2, b3, L1, L2;
  for (int i = 0; i < 16; i++)
    {
        printf("%i",i);
      printf ("temperatura: ");
      scanf ("%i", &temp);
      printf ("boton manual: ");
      scanf ("%d", &b1);
      printf ("boton lata demanda: ");
      scanf ("%d", &b2);
      printf ("boton sobrecarga: ");
      scanf ("%d", &b3);
      if (temp <= 28)
  {
    if (b1 == 0)
      {
        L1 = 0;
        if (b2 == 0 && b3 == 0)
    {
      L2 = 0;
    }
        else
    {
      L2 = 1;
    }
      }
    else
      {
        L1 = 1;
        if (b2 == 0 && b3 == 0)
    {
      L2 = 0;
    }
        else
    {
      L2 = 1;
    }
      }
  }
      else
  {
    L2 = 1;
    if (b1 == 0 && b2 == 0 && b3 == 0)
      {
        L1 = 0;
      }
    else
      {
        L1 = 1;
      }
  }
  if (temp<=28)
  {
      temp=0;
  }
  else
  {
    temp=1;
  }
      printf ("temperatura | ");
      printf ("boton 1 | ");
      printf ("boton 2 | ");
      printf ("boton 3 | ");
      printf ("Led man | ");
      printf ("Led auto | \n");
      printf ("\t %i  | ", temp);
      printf("\t %i    | ", b1);
      printf("    %i   | ", b2);
      printf("    %i   | ", b3);
      printf("    %i   | ", L1);
      printf("    %i    | \n", L2);
}
  return 0;
}
*/
