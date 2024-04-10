#include <Arduino.h>

int conditionPin = LED_BUILTIN;
HardwareSerial gs(2);
unsigned long setTime;
int flag = 0;
float batvol, temp;

void setup() {
  gs.begin(9600);
  pinMode(conditionPin, OUTPUT);
  gs.println("Desde el satélite: Operación Nominal (Datos HK enviados)");
  setTime = millis();
}

void loop() {
  if (millis() - setTime < 50000) {
    digitalWrite(conditionPin, !digitalRead(conditionPin));
    batvol = 3.7;
    temp = 28.5;
    gs.printf("ASCENDSAT: Condición = %d, Tiempo = %lu [s], batVol = %.2f [V], temp = %.2f [°C]", digitalRead(conditionPin), (millis() - setTime) / 1000, batvol, temp);
    delay(1000);
  } else {
    gs.println("Desde el satélite: Fin operación (Datos HK recibidos)");
    while (1);
  }
}
