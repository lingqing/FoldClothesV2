#ifndef _MusicPlayer_h_
#define _MusicPlayer_h_
/***************************************************
* Music player
*
* 2016-6-20
***************************************************/
#include <Arduino.h>

class MusicPlayer
{
public:
	MusicPlayer();
	// ~MusicPlayer();

	bool init();
	bool playToEnd(unsigned char num, unsigned int _mSec);
	bool setPlayMode(unsigned char mode);
	bool play(unsigned char num);
private:
	bool waitForConfirm(unsigned int _mSec);
	bool waitToEnd(unsigned int _mSec);
};

#endif
