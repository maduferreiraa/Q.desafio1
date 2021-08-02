// 1º Desafio projeto 1: Alarme de presença
#include "Ultrasonic.h" //INCLUSÃO DA BIBLIOTECA NECESSÁRIA.

const int echoPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 7; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)

const int pinoBuzzer = 2; //PINO DIGITAL EM QUE O BUZZER ESTÁ CONECTADO

Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS

int distancia; //CRIA UMA VARIÁVEL CHAMADA "distancia" DO TIPO INTEIRO

void setup(){
pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAÍDA (ENVIA)
pinMode(pinoBuzzer, OUTPUT); //DECLARA O PINO COMO SENDO SAÍDA
}
void loop(){

hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"

if(distancia <= 30){// SE A DISTÂNCIA ENTRE O OBJETO E O SENSOR ULTRASONICO FOR MENOR QUE 30CM, FAZ
tone(pinoBuzzer,1500);//ACIONA O BUZZER
}else{//SENÃO, FAZ
noTone(pinoBuzzer);//BUZZER PERMANECE DESLIGADO
}
}
//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
void hcsr04(){
digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
delayMicroseconds(2); // DELAY DE 2 MICROSSEGUNDOS
digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
delayMicroseconds(10); // DELAY DE 10 MICROSSEGUNDOS
digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE
// FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
//RESPOSTA DO ECHO EM CENTÍMETROS E ARMAZENA
//NA VARIÁVEL "distancia"
distancia = (ultrasonic.Ranging(CM)); // VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}
