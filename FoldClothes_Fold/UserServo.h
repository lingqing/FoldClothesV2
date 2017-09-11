
#ifndef _UserServo_h
#define _UserServo_h

#include <Arduino.h>

class UserServo
{
public:
	UserServo();
	// ~UserServo();

	void attach(uint8_t);
	void write(int pulsewidth);

private:
	uint8_t pulsePin;
	void servopulse(int pulsewidth);
};


#endif