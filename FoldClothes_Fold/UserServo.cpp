
#include "UserServo.h"

/**
* [UserServo description]
* @type {[type]}
*/
UserServo::UserServo()
{

}
/**
* [UserServo description]
* @type {[type]}
*/
void UserServo::attach(uint8_t pin)
{
	pulsePin = pin;
	pinMode(pulsePin, OUTPUT);//设定舵机接口为输出接口
}
/**
* [UserServo description]
* @type {[type]}
*/
void UserServo::servopulse(int pulsewidth)
{
	if (pulsewidth <= 500) pulsewidth = 500;
	if (pulsewidth >= 2480) pulsewidth = 2480;  	//将角度转化为500-2480的脉宽值
	digitalWrite(pulsePin, HIGH);    	//将舵机接口电平至高
	delayMicroseconds(pulsewidth);  	//延时脉宽值的微秒数
	digitalWrite(pulsePin, LOW);     	//将舵机接口电平至低
	delayMicroseconds(20000 - pulsewidth);
}
/**
* [UserServo description]
* @type {[type]}
*/
void UserServo::write(int pulsewidth)
{
	for (int i = 0; i<100; i++) {
		servopulse(pulsewidth);
	}
}
