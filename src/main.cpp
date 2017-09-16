#include "Arduino.h"
#include <LiquidCrystal.h>

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define btnUNKNOWN 6

#define isDebug 0

int readkeypad(){
      int adc_key_in = analogRead(0); //

	if (isDebug)
	{
		Serial.print(adc_key_in);
		Serial.print(" - ");
	}


      int ret = btnUNKNOWN;

      if (adc_key_in < 50) ret = btnRIGHT;
      if ((adc_key_in > 500) && (adc_key_in < 1150)) ret = btnNONE;
      if ( (adc_key_in > 50) && (adc_key_in < 120) ) ret = btnUP;
      if ( (adc_key_in > 250) && (adc_key_in < 350) ) ret = btnDOWN;
      if ( (adc_key_in > 400) && (adc_key_in < 450) ) ret = btnLEFT;
      if ( (adc_key_in > 630) && (adc_key_in < 650) ) ret = btnSELECT;

	Serial.print(ret);

      return ret;
}

// Just for ease of displaying
const char *button[7] ={"Right ", "Up ", "Down ", "Left ", "Select ", "       ", "??????"};

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
	Serial.begin(9600);
	lcd.begin(16, 2);
}

void loop() {
      lcd.setCursor(0, 0);
      lcd.print("Button Pressed:");
      lcd.setCursor(0, 1);
      lcd.print(button[readkeypad()]);

//        Serial.print(" - ");

	Serial.println(button[readkeypad()]);
}
