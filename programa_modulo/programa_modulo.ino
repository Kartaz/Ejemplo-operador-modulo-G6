/*
   Estructura básica
   Por: Hugo Vargas
   Fecha: 08 de Abril de 2021

   Esto es una muestra de la estructura básica de un programa
*/

// Bibliotecas
//#include <Serial.h>// opcional

// Constantes

// Variables

int dato = 0;
double timeStart, timeFinish;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  Serial.begin (115200);//Iniciar Comunicacion serial
  Serial.println ("comunicacion Serial Iniciada");
  delay (5000);
}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:

  timeStart = micros (); // Inicia el conteo de tiempo

  for (int i = 0; i > 1000; i++) // ejecuta el contador n veces
  {
    dato++; //incremento
    //comparacion
    if (dato > 8)
    {
      dato = 0;
    }
  }

  timeFinish = micros ();
  Serial.print ("Con If ");
  Serial.println (timeFinish - timeStart); //Imprimir el valor del contador
  delay (10000);

  timeStart = micros (); //Inicia el conteo de tiempo

  // ejecuta el contador de anillo 10 mil veces
  for (int i=0; i<1000; i++)
  {
    dato++; //incremento 
    dato%= 8; // modulo
  }

  timeFinish =micros(); // Termina el conteo de tiempo
  
  //reporte en monitor serial
  Serial.print ("Con operadores");
  Serial.println (timeFinish - timeStart); //Imprimir el valor del contador
  
  delay (10000);// Espera antes de la siguiente prueba

}// Fin de void loop

// Funciones del usuario
