#include <SoftwareSerial.h>

#include "ColorSensor.h"

#define PERIOD_TIME 500    // 500 ms

int   g_count = 0;    // count the frequecy
int   g_array[3];     // store the RGB value
					  // int   g_flag = 0;     // filter of RGB queue
float g_SF[3];        // save the RGB Scale factor
const float g_const_SF[3] = { 0.31, 0.36, 0.37 };


// Init TSC230 and setting Frequency.
void TSC_Init()
{
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(OUT, INPUT);

	digitalWrite(S0, LOW);  // OUTPUT FREQUENCY SCALING 2%
	digitalWrite(S1, HIGH);
	//  Serial.begin(9600);
	// Timer1.initialize();             // defaulte is 1s
	// Timer1.attachInterrupt(TSC_Callback);  
	// attachInterrupt(0, TSC_Count, RISING);  

	// delay(4000); 
	//  for(int i=0; i<3; i++)
	//    Serial.println(g_array[i]);

	// g_SF[0] = 255.0/ g_array[0];     //R Scale factor
	// g_SF[1] = 255.0/ g_array[1] ;    //G Scale factor
	// g_SF[2] = 255.0/ g_array[2] ;    //B Scale factor

	// Serial.println(g_SF[0]);
	// Serial.println(g_SF[1]);
	// Serial.println(g_SF[2]);
}

// Select the filter color 
void TSC_FilterColor(int Level01, int Level02)
{
	if (Level01 != 0)
		Level01 = HIGH;

	if (Level02 != 0)
		Level02 = HIGH;

	digitalWrite(S2, Level01);
	digitalWrite(S3, Level02);
}
/**
*
*/
void TSC_Count()
{
	g_count++;
}
/**
*
*/
// void TSC_Callback()
// {
// //  Serial.println(g_flag);
//   switch(g_flag)
//   {
//     case 0: 
//         // Serial.println("->WB Start");
//          TSC_WB(LOW, LOW);              //Filter without Red
//          break;
//     case 1:
//         // Serial.print("->Frequency R=");
//         // Serial.println(g_count);
//          g_array[0] = g_count;
//          TSC_WB(HIGH, HIGH);            //Filter without Green
//          break;
//     case 2:
//         // Serial.print("->Frequency G=");
//         // Serial.println(g_count);
//          g_array[1] = g_count;
//          TSC_WB(LOW, HIGH);             //Filter without Blue
//          break;

//     case 3:
//         // Serial.print("->Frequency B=");
//         // Serial.println(g_count);
//         // Serial.println("->WB End");
//          g_array[2] = g_count;
//          TSC_WB(HIGH, LOW);             //Clear(no filter)   
//          break;
//    default:
//          g_count = 0;
//          break;
//   }
// }

void TSC_WB(int Level0, int Level1)      //White Balance
{
	g_count = 0;
	// g_flag ++;
	TSC_FilterColor(Level0, Level1);
	// Timer1.setPeriod(PERIOD_TIME);             // set 1s period
}

/**
*
*/
void getPara()
{
	// g_flag = 0;
	// Timer1.initialize(PERIOD_TIME);             // defaulte is 1s, set to 0.5s
	// Timer1.attachInterrupt(TSC_Callback);  
	attachInterrupt(0, TSC_Count, RISING);
	delay(3000);
	for (int i = 0; i<3; i++) {
		g_SF[i] = 255.0 / g_array[i];
		Serial.println(g_SF[i]);
	}
	// Timer1.stop();
	// Timer1.detachInterrupt();
}
/**
*
*/
uint8_t getColor()
{
	//  Serial.println("-> get color");
	int color1 = 0;
	int color2 = 0;

	// g_flag = 0;
	// Timer1.initialize(PERIOD_TIME);             // defaulte is 1s, set to 0.5s
	// Timer1.attachInterrupt(TSC_Callback);  
	// 
	attachInterrupt(0, TSC_Count, RISING);
	delay(1000);
	// user 
	TSC_WB(LOW, LOW);              //Filter without Red
	delay(PERIOD_TIME);
	g_array[0] = g_count;
	TSC_WB(HIGH, HIGH);            //Filter without Green
	delay(PERIOD_TIME);
	g_array[1] = g_count;
	TSC_WB(LOW, HIGH);             //Filter without Blue
	delay(PERIOD_TIME);
	g_array[2] = g_count;
	TSC_WB(HIGH, LOW);             //Clear(no filter) 

	for (int i = 0; i<3; i++) {
		Serial.println(int(g_array[i] * g_const_SF[i]));
	}
	for (int i = 1; i<3; i++)
	{
		if (g_array[color1] * g_const_SF[color1] < g_array[i] * g_const_SF[i]) color1 = i;
	}

	// g_flag = 0;  
	TSC_WB(LOW, LOW);              //Filter without Red
	delay(PERIOD_TIME);
	g_array[0] = g_count;
	TSC_WB(HIGH, HIGH);            //Filter without Green
	delay(PERIOD_TIME);
	g_array[1] = g_count;
	TSC_WB(LOW, HIGH);             //Filter without Blue
	delay(PERIOD_TIME);
	g_array[2] = g_count;
	TSC_WB(HIGH, LOW);             //Clear(no filter) 

	for (int i = 1; i<3; i++)
	{
		if (g_array[color2] * g_const_SF[color2] < g_array[i] * g_const_SF[i]) color2 = i;
	}

	// Stop
	// Timer1.stop();
	// 
	// Timer1.detachInterrupt();
	if (color1 == color2) return color1 + 1;
	else return 4;
	// return 0;
}
