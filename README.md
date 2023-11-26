# Roboline
🔗Creado por [Jordi Rodriguez](https://github.com/jordirdp)  

👨🏻‍💻Programación de **Seguidor de Línea** en Arduino  
    
### Software  
- Programado en lenguaje [Arduino](https://www.arduino.cc/en/software)  
- Se han incluido las siguientes librerías:  
-- [Qtr-sensors](https://github.com/pololu/qtr-sensors-arduino)  
-- [EasyButton](https://easybtn.earias.me/)  
  
- Este código realiza las siguientes funciones simples:  
-- Temporizador de 5 segundos al inicio  
-- Lectura de sensores de línea  
-- Actúa sobre los motores  
  
### Hardware  
- Arduino NANO  
- Sensores de línea Pololu QTR-8A  
- Controlador de motores TB6612FNG  
- 2 x Motores Pololu 
- 2 x Pulsadores
- 2 x resistencias 10KΩ  
- 2 x Leds  
- 2 x resistencias 220Ω  
- Batería LIPO 2S 7.4V 370mAh 25-40C
  
### Montaje  
![Imagen](/Images/Imagen.jpeg)  
  
🔧Conexiones a pines Arduino UNO:  
- A00 = QTR-8A pin 1  
- A01 = QTR-8A pin 2  
- A02 = QTR-8A pin 3  
- A03 = QTR-8A pin 4  
- A04 = QTR-8A pin 5  
- A05 = QTR-8A pin 6  
- A06 = QTR-8A pin 7  
- A07 = QTR-8A pin 8  
- D00 = (RX)  
- D01 = (TX)  
- D02 = (INT0) Switch 1  
- D03-= (INT1) Switch 2  
- D04 = TB6612FNG STBY  
- D05-= TB6612FNG PWM_A  
- D06-= TB6612FNG PWM_B  
- D07 = TB6612FNG AIN2  
- D08 = TB6612FNG AIN1  
- D09-= TB6612FNG BIN1  
- D10-= TB6612FNG BIN2  
- D11-= Led rojo  
- D12 = Led verde  
- D13 = QTR-8A ledon  
  
### Licencia  
⚖️Todo el contenido distribuido bajo [licencia GPL-3.0](https://www.gnu.org/licenses/gpl-3.0), salvo indicación expresa.  
Las referencias y librerías empleadas, estarán sujetas a sus propia licencia, y no se incluyen en este repositorio.  
