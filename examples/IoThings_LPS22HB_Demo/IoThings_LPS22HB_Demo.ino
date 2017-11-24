/***************************************************************************
  This is a library for the LPS22HB Absolute Digital Barometer

  Designed to work with all kinds of LPS22HB Breakout Boards

  These sensors use I2C, 2 pins are required to interface, as this :
	VDD to 3.3V DC
	SCL to A5
	SDA to A4
	GND to common groud 

  Written by Adrien Chapelet for IoThings
 ***************************************************************************/

#include <Wire.h>

#include "IO_LPS22HB.h"

IO_LPS22HB lps22hb;

void setup()
{
	Serial.begin(9600);
	Serial.println("IoThings LPS22HB Arduino Test");
	
	lps22hb.begin(0x5D);

	byte who_am_i = lps22hb.whoAmI();
	Serial.print("Who Am I? 0x");
	Serial.print(who_am_i, HEX);
	Serial.println(" (expected: 0xB1)");
	if (who_am_i != LPS22HB_WHO_AM_I_VALUE) {
		Serial.println("Error while retrieving WHO_AM_I byte...");
		while (true) {
		      // loop forever
		}
	}
}

void loop()
{
	Serial.print("P=");
	Serial.print(lps22hb.readPressure());
	Serial.print(" mbar, T=");
	Serial.print(lps22hb.readTemperature());
	Serial.println("C");
	delay(300);
}

