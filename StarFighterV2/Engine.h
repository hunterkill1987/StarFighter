#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <map>
#include <random>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <memory>
#include "rapidxml\rapidxml.hpp"
#include "Event.h"
#include "IActor.h"
#include "Camera.h"
#include "Emiter.h"

#ifndef ENGINE_HEADER
#define ENGINE_HEADER

#define RELAVENT_PATH (( char *)"../Actor/")

using namespace rapidxml;
using namespace std;

class Engine 
{
private:

	std::random_device  random;

	ALLEGRO_PATH		*path;
	ALLEGRO_DISPLAY		*display;
	ALLEGRO_BITMAP*		*bitmap;
	ALLEGRO_BITMAP*		backgrund;

	Event				*aEvent;

	int InitPath();
	
	void Render();

	float OldTime;
	float NewTime;
	float DeltaTime;

	static Engine* Instance;
	Engine();
public:

	static Engine* GetInstance();


	~Engine();

	virtual int Init();
	
	virtual void DeInit();

	virtual void UpdateEngine(float deltaTime);

	virtual void LoadAsset(IActor* Actor, char* asset);  

	virtual Vector2 GetScreenSize();
	virtual Vector2 GetActorSize(int OwnerId);
	virtual ALLEGRO_PATH* GetPath();

	virtual IEvent* GetEvent();
	virtual float GetCurrentTime();
	virtual float RandToFloat(float a,float b);
	virtual float GetDeltaTime();

	bool Running() {return aEvent->done; };

	vector<char> GetFile(const char* xml);
};
#endif
