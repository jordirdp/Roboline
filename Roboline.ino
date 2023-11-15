// Head
#include "Pinout.h"
#include "Config.h"

// Components
#include "Components/Leds.hpp"
#include "Components/Qtr8a.hpp"
#include "Components/Buttons.hpp"


void setup() 
{
  Serial.begin(9600);

  // Inicializa
  inicia_leds();
  inicia_qtr();
  inicia_buttons();
}


void loop() 
{
  // Lee estado buttons
  button_calibra.read();
  button_inicio.read();

  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000 (for a white line, use readLineWhite() instead)
  uint16_t position = qtr.readLineBlack(sensorValues);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum
  // reflectance and 1000 means minimum reflectance, followed by the line position
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position);

  delay(250);
}