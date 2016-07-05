#include <allegro5\allegro.h>
#ifndef IEVENT_H
#define IEVENT_H

class IEvent
{

public:

	virtual int UpdateInput() = 0;
};

#endif