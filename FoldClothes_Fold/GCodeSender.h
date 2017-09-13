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
	void homeInit();

private:
	SoftwareSerial *sfSerial;
	bool waitForResp(uint64_t mSec, int);
	void GCodeSender::sendCmdString(const String str, uint64_t wait = 1000, int cmd_lines = 1);
	void movRelative(int x, int y, int z, int e, uint64_t mSec = 3000);
	void movAbsolute(int x, int y, int z, int e, uint64_t mSec = 3000);

};


#endif