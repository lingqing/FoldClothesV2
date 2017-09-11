/***************************************************
* Music player
*
* 2016-6-20
***************************************************/

#include "MusicPlayer.h"

/* ----------- static cmd -------------- */
static unsigned char cmd_stop[8] = { 0x7e,0x02,0x0E,0xef };	// 4 byte
static unsigned char cmd_play[8] = { 0x7e,0x02,0x01,0xef };	// 4 byte
static unsigned char cmd_pause[8] = { 0x7e,0x02,0x02,0xef };	// 4 byte

static unsigned char cmd_vol_inc[8] = { 0x7e,0x02,0x05,0xef };	// 4 byte
static unsigned char cmd_vol_dec[8] = { 0x7e,0x02,0x06,0xef };	// 4 byte
																/**
																* [MusicPlayer description]
																* @type {[type]}
																*/
MusicPlayer::MusicPlayer()
{
	// Serial.begin(9600);
}
/**
* [MusicPlayer description]
* @type {[type]}
*/
bool MusicPlayer::init()
{
	Serial.begin(9600);
	// Serial.println("Test");
	Serial.write(cmd_stop, 8);
	waitForConfirm(1000);
	setPlayMode(4); // ONE_STOP
}
/**
* 播放序号为 num 的曲目
* @type {[type]}
*/
bool MusicPlayer::play(unsigned char num)
{
	Serial.flush();
	Serial.write(cmd_stop, 8);
	// Serial.println("wait for confirm");
	waitForConfirm(1500);

	unsigned char cmddata[8] = { 0x7e,0x04,0x44,0x01,0x00,0xef };
	cmddata[4] = num;
	Serial.write(cmddata, 8);
	waitForConfirm(1500);

	return true;
}

/**
*
*/
bool MusicPlayer::waitForConfirm(unsigned int _mSec)
{
	Serial.flush();		//
	char readBuf[10];
	unsigned char bufPos = 0;
	unsigned char readPos = 0;
	unsigned char size = 0;
	unsigned long _time = millis();
	memset(readBuf, 0, 10);
	// Serial.println("wait for confirm");
	_time = millis();
	while (millis() - _time <= _mSec) {
		while (Serial.available() > 0) {
			readBuf[bufPos++] = Serial.read();
			if (bufPos > 9) bufPos = 0;
			if (size <= 9) size++;
		}
		if (size > 1) {
			if (readBuf[readPos] == 'O'
				&& readBuf[(readPos >= 9) ? 0 : (readPos + 1)] == 'K')
			{
				return true;
			}
			else
			{
				if (readPos >= 9) readPos = 0;
				else readPos++;
				size--;
			}
		}
	}
	return false;
}
/**
* [MusicPlayer description]
* @type {[type]}
*/
bool MusicPlayer::playToEnd(unsigned char num, unsigned int _mSec)
{
	play(num);
	waitToEnd(_mSec);
	delay(1000);
	return true;
}
/**
* [MusicPlayer description]
* @type {[type]}
*/
bool MusicPlayer::waitToEnd(unsigned int _mSec)
{
	Serial.flush();		//
	char readBuf[20];
	unsigned char bufPos = 0;
	unsigned char readPos = 0;
	unsigned char size = 0;
	unsigned long _time = millis();
	memset(readBuf, 0, 20);
	_time = millis();
	while (millis() - _time <= _mSec) {
		while (Serial.available() > 0) {
			readBuf[bufPos++] = Serial.read();
			if (bufPos > 19) bufPos = 0;
			if (size <= 19) size++;
		}
		if (size > 3) {
			if (readBuf[readPos] == 'S'
				&& readBuf[(readPos >= 19) ? 0 : (readPos + 1)] == 'T'
				&& readBuf[(readPos >= 19) ? 1 : (readPos + 2)] == 'O'
				&& readBuf[(readPos >= 19) ? 2 : (readPos + 3)] == 'P')
			{
				return true;
			}
			else
			{
				if (readPos >= 19) readPos = 0;
				else readPos++;
				size--;
			}
		}
	}
	return false;
}
/**
* [MusicPlayer description]
* @type {[type]}
*/
bool MusicPlayer::setPlayMode(unsigned char mode)
{
	unsigned char cmddata[8] = { 0x7e,0x03,0x33,0x00,0xef };
	cmddata[4] = mode;
	Serial.write(cmddata, 8);
	if (!waitForConfirm(1000)) return false;
	return true;
}
