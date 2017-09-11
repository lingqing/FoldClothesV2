#ifndef _ColorSensor_H_
#define _ColorSensor_H_

// #include <TimerOne.h>
#include <Arduino.h>

#define S0     A0   // Please notice the Pin's define
#define S1     A1
#define S2     A2
#define S3     A3
#define OUT    2


// void TSC_Callback();
void TSC_Count();
void TSC_WB(int Level0, int Level1);
void TSC_FilterColor(int Level01, int Level02);
void TSC_Init();
void getPara();
uint8_t getColor();
//class ColorSensor
//{
//public:
//	ColorSensor();
//	// ~ColorSensor();
//
//	 void TSC_Init();
//	int getColor();
//
//private:
////	void TSC_FilterColor(int Level01, int Level02);
////	void TSC_Count();
////	void TSC_Callback();
////	void TSC_WB(int Level0, int Level1);
//	
//};

#endif
