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
	sendCmdString("G0", 3000);	// rise arm end a distance to the plane : P1		E0	
	sendCmdString("G0");	// line slide Arm to slide end			 : P1		E1
	switch (pos)		 // mov arm end to box postion			 : P2-1/2/3 E1
	{
	default:
		break;
	}
	sendCmdString("G0"); // line slide Arm to box				 : P2-1/2/3 E2
	sendCmdString("G0"); // down arm end to box base			 : P3-1/2/3 E2
	sendCmdString("G0"); // line slide Arm to slide end			 : P2-1/2/3 E1
	sendCmdString("G0"); // mov arm end a distance to the plane	 : P1		E2
	sendCmdString("G0"); // line slide Arm to init				 : P1		E0
	sendCmdString("G0"); // down arm end to plane				 : P0		E0

	return false;
}
/**
*
*/
bool GCodeSender::waitForResp(uint64_t mSec)
{
	uint64_t _time = millis();
	char _buf[4] = { 0x00, 0x00, 0x00, 0x00 };
	while (millis() - _time <= mSec)
	{
		if (sfSerial->available())
		{
			_buf[1] = sfSerial->read();
			if (_buf[0] == 'o'&& _buf[1] == 'k') return true;
			else _buf[0] = _buf[1];
		}
	}
	return false;
}

/**
*
*/
void GCodeSender::sendCmdString(const String str, uint64_t wait)
{
	do
	{
		sfSerial->println(str);
	} while (waitForResp(wait));
}
/**
*
*/
void GCodeSender::sendCmdString(const String str)
{
	sendCmdString(str, 3000);
}

