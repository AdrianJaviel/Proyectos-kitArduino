#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  lcd.init();
  lcd.backlight();

}

void loop() {

  // Primer texto
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("...");

  lcd.setCursor(0,1);
  lcd.print(" ");
  delay(1300);

  // Segundo texto
  lcd.clear();

  String texto1 = "Aqui";
  
  for(int i = 0; i < texto1.length(); i++) {

    lcd.print(texto1[i]);
    delay(400);

  }

  delay(2200);

  // Tercer texto
  lcd.clear();

  String texto2 = "Sentado";
  
  for(int i = 0; i < texto2.length(); i++) {

    lcd.print(texto2[i]);
    delay(200);

  }

  delay(2000);

  // Cuarto texto
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Esperandote");
   delay(3600);

  lcd.setCursor(0,1);
  lcd.print("Esperandote");
  delay(3000);

}