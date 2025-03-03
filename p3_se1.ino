//AV3 - SISTEMAS EMBARCADOS

// BIBLIOTECAS
#include <Servo.h> 

// PINO
#define sensor 0

// VALORES SENSOR TEMPERATURA (V) [TMP36]
#define MINOUT 0.5 
// Em 0 graus Celsius, o sensor registra 500mV (0.5V)
#define SCALE 0.01
// Fator de Escala: 10mV por grau (0.01V)

// SERVO
Servo Servo1;

// VARIÁVEIS
int temp; // temperatura
float volt_s; // voltagem lida do sensor
int servo_pos; // posição do servo

void setup()
{
  //teste
  //Serial.begin(9600);
  
  // CONFIGURAÇÃO DO SERVO
  Servo1.attach(5);
}

void loop()
{
  
 // LEITURA DO SENSOR 
 volt_s = (5*analogRead(sensor))/1023.00; 
 temp = arredonda((volt_s-MINOUT) / SCALE) ; // cálculo da temperatura
  
 // MOVIMENTAÇÃO DO SERVO
 servo_pos = 180 - ( (temp + 40)* 1.0909 );
 // 180 / ( 40 + 125 ) = 1.0909...
 Servo1.write(servo_pos);
  
 /*
 //teste
 Serial.println("TEMP:");
 Serial.println(temp);
 Serial.println("SERVO_POS:");
 Serial.println(servo_pos);
 Serial.println("");
*/ 
  
 delay(10);
 
}


// Função para arredondar número
int arredonda(double number)
{
  return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}