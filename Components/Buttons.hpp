#pragma once

#include <EasyButton.h>
EasyButton button_calibra(SWITCH_CALIBRA_PIN);
EasyButton button_inicio(SWITCH_INICIO_PIN);


void salida()
{
  Serial.println("Button2 pressed");
}


void stop()
{
  Serial.println("Button2 pressed");
}


void inicia_buttons()
{
  button_calibra.begin();
  button_inicio.begin();
  button_calibra.onPressed(calibracion);
  button_inicio.onPressedFor(duration_pressed, stop);
  button_inicio.onPressed(salida);
}
