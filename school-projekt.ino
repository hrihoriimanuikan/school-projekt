#include <dht11.h>

dht11 dht11;

const int dht11_pin = 2;
const int pin3 = 3;
const int pin4 = 4;
const int pin5 = 5;

void setup() {
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  dht11.read(dht11_pin); // Читаем данные, игнорируя результат

  if (dht11.humidity <= 40) {
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin5, LOW);
  } else if (dht11.humidity >= 60) {
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, HIGH);
  } else {
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
  }

  delay(2000);
}
