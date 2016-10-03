// StarFighterV2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Engine.h"
#include "World.h"
#include "InputManager.h"
#include "rapidxml\rapidxml.hpp"

using namespace rapidxml;
using namespace std;

int main(int argc, char *argv[]) 
{
	Engine *g_engine = Engine::GetInstance();
	World* World = World::GetInstance();

	if(World != NULL && g_engine != NULL)
	{
		
		if(g_engine->Init() == 0) {
			fprintf(stderr,"Falid to Init Engine !!! \n");
			return -1;
	 	}

		if(World->WorldInit() == 0)
		{
			fprintf(stderr,"Falid to Init Game !!! \n");
			return -1;
		}

		bool redraw = false;
		while(!g_engine->Running())
		{
		
			if( !redraw)
			{ 
				World->Update(g_engine->GetDeltaTime());
				redraw = true;
			}

			if(redraw )
			{
				redraw = false;
				g_engine->UpdateEngine();	
			}
		}
	}
	delete World;
	delete g_engine;

	return 0;
}

