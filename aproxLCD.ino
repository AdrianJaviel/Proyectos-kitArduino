#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TRIG 9
#define ECHO 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

long duracion;
int distancia;

void setup() {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Iniciando...");
  delay(2000);

}

void loop() {

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duracion = pulseIn(ECHO, HIGH);

  distancia = duracion * 0.034 / 2;

  // SOLO borrar una vez por ciclo
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Dist:");
  lcd.print(distancia);
  lcd.print(" cm");

  lcd.setCursor(0,1);

  if(distancia <= 3) {

    lcd.print("CERCA");

  }
  else if(distancia >= 10) {

    lcd.print("LEJOS");

  }
  else {

    lcd.print("MEDIO");

  }

  delay(1000);

}