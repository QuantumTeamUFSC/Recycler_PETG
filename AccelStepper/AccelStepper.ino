// Controle de Motor de Passo com Potenciometro 
// Blog Eletrogate - https://blog.eletrogate.com/guia-completo-do-motor-de-passo-28byj-48-driver-uln2003
// Baseado em http://www.airspayce.com/mikem/arduino/AccelStepper/ProportionalControl_8pde-example.html
// Motor 28BYJ48/5V com Modulo ULN20023 - Arduino UNO / IDE 1.8.5
// Uma volta no eixo = 4075 pulsos 
// Gustavo Murta 02/jago/2018

#include <AccelStepper.h>                                          // biblioteca AccelStepper

#define ANALOG_PIN A0                                              // pino A0 para leitura da tensão do Potenciometro

AccelStepper motorPasso (AccelStepper::FULL4WIRE, 8, 10, 9, 11);   // Passo completo 4 fios 

void setup()
{  
  Serial.begin(9600);
  motorPasso.setMaxSpeed(1000);                                    // maxima velocidade = 500 pulsos por segundo 
  motorPasso.setAcceleration(100);
}

void loop()
{
  int analog_in = analogRead(ANALOG_PIN);                          // lendo a tensão do pino A0 do Arduino
  Serial.println(analog_in);
  // motorPasso.setSpeed(500);                                        // velocidade = 100 pulsos por segundo 
  if(analog_in < 250) {motorPasso.setSpeed(-500); motorPasso.runSpeed();}
  if(analog_in > 250 && analog_in < 450) {motorPasso.setSpeed(-300); motorPasso.runSpeed();}
  if(analog_in > 450 && analog_in < 550) {motorPasso.stop();}
  if(analog_in > 550 && analog_in < 750) {motorPasso.setSpeed(300); motorPasso.runSpeed();}
  if(analog_in > 750 && analog_in < 990) {motorPasso.setSpeed(500); motorPasso.runSpeed();}
  // motorPasso.moveTo(analog_in);                                    // gira o eixo do motor X pulsos (0 a 1023 pulsos) 
  // motorPasso.runSpeedToPosition();                                 // gira o eixo para a posição definida
}
