#pragma once

// Pines sensor QTR-8A
// A0 - A7 reservados para sensores
// D13 reservado para control

// Pines Bluetooth
// D0 + D1 reservados para comunicaciones

// Pines con interrupciones
const int SWITCH_CALIBRA_PIN = 2;
const int SWITCH_INICIO_PIN = 3;

// Pines controlador motores
const int STBY_PIN = 4;
const int PWM_I_PIN = 5; //~
const int PWM_D_PIN = 6; //~
const int IZQ_2_PIN = 7;
const int IZQ_1_PIN = 8;
const int DER_1_PIN = 9;
const int DER_2_PIN = 10;

// Pines leds
const int LED_RED_PIN = 11;
const int LED_GREEN_PIN = 12;
