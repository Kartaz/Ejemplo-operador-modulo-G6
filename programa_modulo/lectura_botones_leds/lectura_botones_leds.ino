/*
 * Estructura básica
 * Por: Hugo Vargas
 * Fecha: 28 de junio de 2021
 * 
 * Esto es una muestra de la estructura básica de un programa
 */

// Bibliotecas

// Constantes
const int BOTON1 = 4;
const int LED1 = 2;

// Variables
int dato1;

// Definición de objetos

// Condiciones iniciales - Se ejecuta sólo una vez al energizar
void setup() {// Inicio de void setup ()
  // Aquí va tu código
  pinMode (BOTON1, INPUT_PULLUP); // configurar el pin donde se conecta el 
  pinMode (LED1,OUTPUT); // Confiurar el pin donde se conecta el led como
  digitalWrite (LED1, LOW); // 0, false, LOW, 1, true, HIGH

}// Fin de void setup

// Cuerpo del programa - Se ejecuta constamente
void loop() {// Inicio de void loop
  // put your main code here, to run repeatedly:

  dato1 = digitalRead (BOTON1); // Leer el boton
  digitalWrite (LED1, dato1);
  
}// Fin de void loop

// Funcioes del usuario
