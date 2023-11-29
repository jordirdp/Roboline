#pragma once


void TurnOn(int Led_Pin) 
{
  digitalWrite(Led_Pin, HIGH);
}


void TurnOff(int Led_Pin) 
{
  digitalWrite(Led_Pin, LOW);
}


void Blink(int Led_Pin) 
{
  for (byte i = 0; i < 5; i++) 
  {
    TurnOn(Led_Pin);
    delay(500);
    TurnOff(Led_Pin);
    delay(500);
  }
}


void inicia_leds()
{
  pinMode(LED, OUTPUT);
  TurnOff(LED);
  /*
  pinMode(RED, OUTPUT);
  TurnOff(RED);
  pinMode(GREEN, OUTPUT);
  TurnOff(GREEN);
  */
}