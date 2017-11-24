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

#ifndef _IO_LPS22HB_h

#define _IO_LPS22HB_h
#include <Arduino.h>

#define LPS22HB_WHO_AM_I	0X0F //Who am I
#define LPS22HB_RES_CONF	0X1A //Resolution
#define LPS22HB_CTRL_REG1	0X10
#define LPS22HB_CTRL_REG2	0X11
#define LPS22HB_STATUS_REG	0X27
#define LPS22HB_PRES_OUT_XL	0X28 //LSB
#define LPS22HB_PRES_OUT_L	0X29
#define LPS22HB_PRES_OUT_H	0X2A //MSB
#define LPS22HB_TEMP_OUT_L	0X2B //LSB
#define LPS22HB_TEMP_OUT_H	0X2C //MSB

#define LPS22HB_WHO_AM_I_VALUE	0xB1 // Expected return value of WHO_AM_I register



class IO_LPS22HB {
public:
	IO_LPS22HB();

	void begin(uint8_t address);

	uint8_t whoAmI();
	float readTemperature();

	float readPressure();
	uint32_t readPressureUI();
	uint32_t readPressureRAW();

private:
	uint8_t _address;
	uint8_t read(uint8_t reg);
	void write(uint8_t reg, uint8_t data);
	uint8_t status(uint8_t data);
};

#endif
