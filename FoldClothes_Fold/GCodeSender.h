#ifndef _GCODESENDER_H_
#define _GCODESENDER_H_

/***************************************************
* Gcoder Sender
*
* 2017-09-07
***************************************************/
/* ---------------------- define -------------------*/

#define  SSRX	A4
#define	 SSTX	A5

#include <Arduino.h>
#include <SoftwareSerial.h>

class GCodeSender
{
public:
	GCodeSender();
	bool mvToPosIndex(int);

private:
	SoftwareSerial *sfSerial;
	bool waitForResp(uint64_t mSec);
	void sendCmdString(const String, uint64_t wait);
	void sendCmdString(const String);
};


#endif