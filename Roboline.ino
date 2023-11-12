// Head
#include "Pinout.h"
#include "Config.h"

// EasyButton
#include <EasyButton.h>
EasyButton button_calibra(SWITCH_CALIBRA_PIN);
EasyButton button_inicio(SWITCH_INICIO_PIN);

// QTRSensors-8A
#include <QTRSensors.h>
QTRSensors qtr;
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];



void setup() 
{
  Serial.begin(9600);

  // Inicializa leds
  pinMode(RED, OUTPUT);
  TurnOff(RED);
  pinMode(GREEN, OUTPUT);
  TurnOff(GREEN);

  // Inicializa buttons
  button_calibra.begin();
  button_inicio.begin();
  button_calibra.onPressed(calibracion);
  button_inicio.onPressedFor(duration_pressed, stop);
  button_inicio.onPressed(salida);

  // Inicializa QTR
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, SensorCount);
  qtr.setEmitterPin(13);
  delay(500);
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
  // reflectance and 1000 means minimum reflectance, followed by the line
  // position
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position);

  delay(250);
}


// FUNCIONES PARA LEDS ****************************************************************

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


// FUNCIONES PARA SENSOR QTR-8A ********************************************************

void calibracion()
{
  for (byte i = 0; i < 3; i++) 
  {
    Blink(RED);
  }
  // analogRead() takes about 0.1 ms on an AVR.
  // 0.1 ms per sensor * 4 samples per sensor read (default) * 8 sensors
  // * 10 reads per calibrate() call = ~24 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  for (byte i = 0; i < 3; i++) 
  {
    Blink(GREEN);
  }
  
  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
}


// FUNCIONES PRINCIPALES START-STOP ****************************************************

void salida()
{
  Serial.println("Button2 pressed");
}

void stop()
{
  Serial.println("Button2 pressed");
}