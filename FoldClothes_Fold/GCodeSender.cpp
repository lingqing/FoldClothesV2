#include "GcodeSender.h"

/**
* [Gcodesender description]
* @type {[type]}
*/
GCodeSender::GCodeSender()
{
	//SoftwareSerial sfSerial();
	sfSerial = new SoftwareSerial(SSRX, SSTX);
	sfSerial->begin(115200);
}

/**

*/
bool GCodeSender::mvToPosIndex(int pos)
{
<<<<<<< HEAD
	 /**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pos define ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                       |____   4                            P (90°)
                       .----   4.5                          |            
                       |                                    |
             O=========.____   3                            |    
            /          |----   3.5                          |        A   C                    B
           /           .____   2                            |        O===O====================O
          /            |----   2.5                          |	(-110)  (-105)               (0)
         /             .____   1           Q ---------------O
        O              |____   0	      (8°) 
		
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	switch (pos)		 // mov arm end to box postion			 : P2-1/2/3 E1
	{
	case 0:						// move To home
		
		break;
	case 1:		
        /**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                       |____   4                            P (90°)
                       .----   4.5                          |            
                       |                                    |
             O=========.____   3                            |    
            /          |----   3.5                          |        A   C                    B
           /           .____   2                            |        O===O====================O
          /            |----   2.5                          |	(-110)  (-105)               (0)
         /             .____   1           Q ---------------O
        O              |____   0	      (8°) 
		
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
		/// ----------------
		//movAbsolute(85, 40, 90, 0, 6000);		// 0 --> 4
		//movAbsolute(85, 40, 90, 110, 5000);		// A --> B
		//movAbsolute(85, 40,  10, 110, 3000);	 	// P --> Q

		//movAbsolute(85, 40, 10, 5, 4000);		// B --> C
		//movAbsolute(90, 20, 10, 5, 2000);			// 4 --> 4.5
		//movAbsolute(90, 20, 10, 110, 5000);		 	// C --> B
		//movAbsolute(90, 40, 10, 110, 2000);		 	// 4.5 --> 4

		//movAbsolute(90, 40, 90, 110, 3000);		// Q --> P
		//movAbsolute(90, 40, 90,/*0*/ -10, 5000);		// B --> A (0->-10)
		//movAbsolute(75, -85, 90, 0, 5000);	    // 4 --> 0
		/// ----------------
		/// RelativeE
		movAbsolute(85, 40, 90, 0, 6000);		// 0 --> 4
		movAbsolute(85, 40, 90, 110, 5000);		// A --> B
		movAbsolute(85, 40,  7, 0, 3000);	 	// P --> Q

		movAbsolute(85, 40, 7, -105, 4000);		// B --> C
		movAbsolute(90, 20, 7, 0, 2000);			// 4 --> 4.5
		movAbsolute(90, 20, 7, 105, 5000);		 	// C --> B
		movAbsolute(90, 40, 7, 0, 2000);		 	// 4.5 --> 4
=======
	//sendCmdString("G0", 3000);	// rise arm end a distance to the plane : P1		E0	
	//sendCmdString("G0");	// line slide Arm to slide end			 : P1		E1
	switch (pos)		 // mov arm end to box postion			 : P2-1/2/3 E1
	{
	case 0:						// move To home
		sendCmdString("G95",100);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z90 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y45 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y45 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y-85 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y45 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z90 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z5 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z5 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z10 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z10 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z10 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z90 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y20 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y-85 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);
		break;
	case 1:
		sendCmdString("G95", 100);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z90 F2000", 300);		
		sendCmdString("G1 X95 Y45 Z90 E-100 F2000", 300);
		sendCmdString("G1 X75 Y45 Z90 E-100 F2000", 300);		
		sendCmdString("G1 X75 Y-75 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X75 Y45 Z90 E-100 F2000", 300);		
		sendCmdString("G1 X95 Y45 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z90 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z8 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y45 Z8 E-100 F2000", 300);		
		sendCmdString("G1 X95 Y45 Z10 E-100 F2000", 300);		
		sendCmdString("G1 X95 Y20 Z10 E-100 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z10 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z90 E10 F2000", 300);
		sendCmdString("M114", 300);

		sendCmdString("G95", 300);
		sendCmdString("G90");
		sendCmdString("G1 X95 Y20 Z90 E-100 F2000", 300);		
		sendCmdString("G1 X75 Y20 Z90 E-100 F2000", 300);		
		sendCmdString("G1 X75 Y-85 Z90 E-100 F2000", 300);
		sendCmdString("M114", 300);
		break;
	case 2:
		
		// 1 -- 2
		sendCmdString("G91", 100);
		sendCmdString("G1 Y40 F2000", 1000);
		sendCmdString("M114", 300);
		// A -- B
		sendCmdString("G91", 300);
		sendCmdString("G1 E110 F2000", 3000);
		sendCmdString("M114", 300);
		// 2 -- 3
		sendCmdString("G91", 300);
		sendCmdString("G1 X10 Y115 F2000", 300);
		sendCmdString("G1 Z-95 F2000", 2500);
		sendCmdString("M114", 300);
		// B -- C
		sendCmdString("G91", 300);
		sendCmdString("G1 E-105 F2000", 3000);
		sendCmdString("M114", 300);
		// 3 -- 3.5
		sendCmdString("G91", 300);
		sendCmdString("G1 Y-27 F2000", 1000);
		sendCmdString("M114", 300);
		// C -- B
		sendCmdString("G91", 300);
		sendCmdString("G1 E105 F2000", 2500);
		sendCmdString("M114", 300);
		// 3.5 -- 3
		sendCmdString("G91", 300);
		sendCmdString("G1 Y27 F2000", 1000);
		sendCmdString("M114", 300);
		// 3 - 2
		sendCmdString("G91", 300);
		sendCmdString("G1 Z95 F2000", 300);
		sendCmdString("G1 X-10 Y-115 F2000", 2500);
		sendCmdString("M114", 300);
		// B -- A
		sendCmdString("G91", 300);
		sendCmdString("G1 E-110 F2000", 2500);
		sendCmdString("M114", 300);
		// 2 -- 1
		sendCmdString("G91", 300);		
		sendCmdString("G1 Y-40 F2000", 2500);
		sendCmdString("M114", 300);
		break;
	default:
		break;
	}
	//sendCmdString("G0"); // line slide Arm to box				 : P2-1/2/3 E2
	//sendCmdString("G0"); // down arm end to box base			 : P3-1/2/3 E2
	//sendCmdString("G0"); // line slide Arm to slide end			 : P2-1/2/3 E1
	//sendCmdString("G0"); // mov arm end a distance to the plane	 : P1		E2
	//sendCmdString("G0"); // line slide Arm to init				 : P1		E0
	//sendCmdString("G0"); // down arm end to plane				 : P0		E0
>>>>>>> modify the arm position to more accurate

		movAbsolute(90, 40, 90, 0, 3000);		// Q --> P
		movAbsolute(90, 40, 90, -120, 5000);		// B --> A
		movAbsolute(65, -85, 90, 0, 5000);	    // 4 --> 0
		break;
	case 2:				
		break;
	case 3:
		movAbsolute(85, 40, 90, 0, 6000);		// 0 --> 4
		movAbsolute(85, 40, 90, 110, 5000);		// A --> B
		movAbsolute(85, 40, 7, 0, 3000);	 	// P --> Q

		movAbsolute(95, 10, 7, 0, 3000);	 	// 4 --> 3

		movAbsolute(95, 10, 7, -105, 4000);		// B --> C
		movAbsolute(85, -14, 7, 0, 2000);			// 3 --> 3.5
		movAbsolute(85, -14, 7, 105, 5000);		 	// C --> B
		movAbsolute(90, 40, 7, 0, 2000);		 	// 3.5 --> 4

		movAbsolute(90, 40, 90, 0, 3000);		// Q --> P
		movAbsolute(90, 40, 90, -120, 5000);		// B --> A
		movAbsolute(65, -85, 90, 0, 5000);	    // 4 --> 0
		break;
	default:
		break;
	}	
	return false;
}

/**

*/
void GCodeSender::homeInit()
{
<<<<<<< HEAD
	sendCmdString("G28", 10000);
	sendCmdString("G95\r\nG90", 500, 2);	
	movAbsolute(95, 45, 0, 130,500);

	movAbsolute(95, 45, 90, 130, 3000); // rezero
	movAbsolute(95, 45, 90, 0, 4000);
	movAbsolute(95, 45, 90, 0, 1000);
	movAbsolute(65, -85, 90, 0, 4000);

	sendCmdString("M83", 300);
=======
	sendCmdString("G28", 5000);
	sendCmdString("G95");
	sendCmdString("G91", 300);
	sendCmdString("G1 Z7 F2000", 300);	
	sendCmdString("G1 E-120 F2000", 300);
	sendCmdString("G90", 300);	
	sendCmdString("M114", 300);
	// 0 -- 1
	sendCmdString("G91", 300);
	sendCmdString("G1 X-25 Y-130 F2000", 3000);
	sendCmdString("M114", 300);
>>>>>>> modify the arm position to more accurate
}
/**
* waitForResp
* wait for a while time for the resps "ok"
*/
bool GCodeSender::waitForResp(uint64_t mSec, int cmd_lines)
{
	uint64_t _time = millis();
	char _buf[4] = { 0x00, 0x00, 0x00, 0x00 };
	int _line = 0;
	while (millis() - _time <= mSec)
	{
		if (sfSerial->available())
		{
			_buf[1] = sfSerial->read();
			if (_buf[0] == 'o'&& _buf[1] == 'k')
			{
<<<<<<< HEAD
				if (++_line >= cmd_lines)
				{
					//while (sfSerial->read() > 0);	 // 清空接收缓存			
					//sfSerial->flush();				// 情况发送缓存
					return true;
				}			
			}			
			_buf[0] = _buf[1];
		}		
	}
	//while (sfSerial->read() > 0);	 // 清空接收缓存			
	//sfSerial->flush();				// 情况发送缓存	
=======
				sfSerial->flush();
				return true;
			}			
			else _buf[0] = _buf[1];
		}		
	}
	sfSerial->flush();
>>>>>>> modify the arm position to more accurate
	return false;
}

/**
* send and wait cmd
*/
void GCodeSender::sendCmdString(const String str, uint64_t wait = 1000, int cmd_lines = 1)
{
	int re_time = 0;
	do
	{
		if (re_time++ >= 1) break;		
		sfSerial->println(str);
	} while (!waitForResp(wait, cmd_lines));
}
/**
* 相对运动
*/
void GCodeSender::movRelative(int x , int y , int z , int e, uint64_t mSec = 3000)
{
	sendCmdString("G95\r\nG91", 300, 2);
	String posStr = (x != 0) ? (String(" X") + x) : "" +
					(y != 0) ? (" Y" + y) : "" +
					(z != 0) ? (" Z" + z) : "" +
					(e != 0) ? (" E" + e) : "";
	sendCmdString("G1" + posStr + " F3000\r\nG90\r\nM114", mSec, 3);
}
/**
* 绝对运动
*/
void GCodeSender::movAbsolute(int x, int y, int z, int e, uint64_t mSec = 3000)
{
	sendCmdString("G95\r\nG90", 300/*, 2*/);
	String posStr = String(" X") + x + " Y" + y + " Z" + z + " E" + e;
	/*if (e == 0) sendCmdString("G1" + posStr + " F3000\r\nM114", mSec, 2);	
	else */sendCmdString("G1" + posStr + " F2000\r\nM114", mSec, 2);	
}


