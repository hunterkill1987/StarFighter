#include <allegro5\allegro.h>
#ifndef IEVENT_H
#define IEVENT_H

enum InputStat
{
	IS_NONE,
	IS_BLOCKINPUT,
	IS_CLEAR
};

enum Button_Actions
{
	BA_PRESS,
	BA_HOLD,
	BA_RELEASE
};

enum Actions
{
	INVALID_BUTTON	= 0xAA,
	UP				= 0x1,
	DOWN			= 0x2,
	LEFT			= 0x4,
	RIGHT			= 0x5,
	FIRE			= 0x7,
};

class IEvent
{

public:

	virtual bool Tick() = false;
	virtual bool IsQueue() = false;
	virtual int UpdateInput() = 0;

	virtual int GetInput()  = 0 ;
	virtual int GetInputState()  = 0 ;
};

#endif