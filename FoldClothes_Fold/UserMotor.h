/************************************************
*
*  UserMotor Driver for fold clothes
*  Author: Andy
*  Date  : 2016-6-17
***********************************************/

#ifndef _UserMotor_h_
#define _UserMotor_h_
#include <Arduino.h>
#include <inttypes.h>

/* -------------- state define ---------- */
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
// #define RELEASE 4

class UserMotor
{
public:
	UserMotor(uint8_t motornum);
	void run(uint8_t);
	// void setSpeed(uint8_t);
	void attach(uint8_t pinDirA, uint8_t pinDirB, uint8_t pinLimitC);
	void runToLimit(uint8_t cmd, unsigned long mSec);
	void runToTime(uint8_t cmd, unsigned long mSec);
private:
	uint8_t motornum, pinRunA, pinDirB, pinLimitC;
};

#endif

