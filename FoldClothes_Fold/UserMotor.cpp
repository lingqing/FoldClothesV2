/************************************************
*
*  UserMotor Driver for fold clothes
*  Author: Andy
*  Date  : 2016-6-17
***********************************************/
#include <avr/io.h>
#include "UserMotor.h"
#include <Arduino.h>

/**
* 电机初始化： 引脚初始化
*/
UserMotor::UserMotor(uint8_t num)
{
	motornum = num;
}
/**
* [UserMotor description]
* @type {[type]}
*/
void UserMotor::attach(uint8_t pinA, uint8_t pinB, uint8_t pinC)
{
	pinRunA = pinA;
	pinDirB = pinB;
	pinLimitC = pinC;

	pinMode(pinRunA, OUTPUT);
	pinMode(pinDirB, OUTPUT);
	digitalWrite(pinRunA, LOW);
	digitalWrite(pinDirB, LOW);  // 停止电机
	pinMode(pinLimitC, INPUT);
}

/**
* [UserMotor description]
* @type {[type]}
*/
void UserMotor::run(uint8_t cmd)
{
	switch (cmd) {  //设置电机运行状态
	case FORWARD:
		digitalWrite(pinRunA, HIGH);
		digitalWrite(pinDirB, LOW);
		// if(pinRunA != pinDirB)  digitalWrite(pinDirB, LOW); // 鐢垫満3  
		break;
	case BACKWARD:
		digitalWrite(pinRunA, HIGH);
		digitalWrite(pinDirB, HIGH);
		// if(pinRunA != pinDirB)  digitalWrite(pinDirB, HIGH); // 鐢垫満3
		break;
	case BRAKE:
		digitalWrite(pinRunA, LOW);
		digitalWrite(pinDirB, LOW);
		// if(dirPinA != pinDirB)  digitalWrite(dirPinB, 0); // 鐢垫満3
		break;
	}
}
/**
* [UserMotor description]
* @type {[type]}
*/
void UserMotor::runToLimit(uint8_t cmd, unsigned long mSec)
{
	unsigned long _time = millis();

	uint8_t sensorState = 0;  // 0 -- open
							  // 1 -- wait to confirm
							  // 2 -- confirm close
	unsigned int _waitTime;
	while ((millis() - _time) <= mSec)
	{
		switch (sensorState)
		{
		case 0:
			if (HIGH == digitalRead(pinLimitC))
			{
				_waitTime = millis();
				sensorState = 1;
			}
			else run(cmd);
			break;
		case 1:
			if (HIGH == digitalRead(pinLimitC))  // 继续高位
			{
				if (millis() - _waitTime >= 20)
				{
					sensorState = 2;
				}
			}
			else sensorState = 0;
			break;
		case 2:
			break;
		default:
			return;
		}
		if (2 == sensorState) break; // break of while    
	}
	run(BRAKE);
}
/**
* [UserMotor description]
* @type {[type]}
*/
void UserMotor::runToTime(uint8_t cmd, unsigned long mSec)
{
	run(cmd);
	delay(mSec);
	run(BRAKE);
}
/******************************************
MOTORS
******************************************/
// inline void initPWM3(uint8_t freq) {
// #if defined(__AVR_ATmega8__) || \
//     defined(__AVR_ATmega48__) || \
//     defined(__AVR_ATmega88__) || \
//     defined(__AVR_ATmega168__) || \
//     defined(__AVR_ATmega328P__)
//     // use PWM from timer2B (pin 3)
//     TCCR2A |= _BV(COM2B1) | _BV(WGM20) | _BV(WGM21); // fast PWM, turn on oc2b
//     TCCR2B = freq & 0x7;
//     OCR2B = 0;
// #elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
//     // on arduino mega, pin 3 is now PE5 (OC3C)
//     TCCR3A |= _BV(COM1C1) | _BV(WGM10); // fast PWM, turn on oc3c
//     TCCR3B = (freq & 0x7) | _BV(WGM12);
//     OCR3C = 0;
// #else
//    #error "This chip is not supported!"
// #endif

//     pinMode(3, OUTPUT);
// }

// inline void setPWM3(uint8_t s) {
// #if defined(__AVR_ATmega8__) || \
//     defined(__AVR_ATmega48__) || \
//     defined(__AVR_ATmega88__) || \
//     defined(__AVR_ATmega168__) || \
//     defined(__AVR_ATmega328P__)
//     // use PWM from timer2A on PB3 (Arduino pin #11)
//     OCR2B = s;
// #elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
//     // on arduino mega, pin 11 is now PB5 (OC1A)
//     OCR3C = s;
// #else
//    #error "This chip is not supported!"
// #endif
// }
/**
*
*/
// void UserMotor::setSpeed(uint8_t speed)
// {
// //  float speedVol = (speed * 5.0 / 255);
//   switch (motornum) {
//   case 1:
//     analogWrite(MOTOR1_PWM, speed); break;
//   case 2:
//     analogWrite(MOTOR2_PWM, speed); break;
//   case 3:
//     analogWrite(MOTOR3_PWM, speed); break;
//   default:
//     return;
//   }
// }


