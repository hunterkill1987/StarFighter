// StarFighterV2.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include "Engine.h"
#include "Game.h"
#include "Event.h"

int main(int argc, char *argv[]) 
{
	Engine *g_engine = new Engine();
	Game *g_game = new Game();	

	if(g_game != NULL && g_engine != NULL)
	{
		if(g_engine->Init() == 0) {
			fprintf(stderr,"Falid to Init Engine !!! \n");
			return -1;
		}

		g_engine->SetGame(g_game);

		if(g_game->GameInit(g_engine->GetEgnine()) == 0)
		{
			fprintf(stderr,"Falid to Init Game !!! \n");
			return -1;
		}

		float oldTime = 0.0;
		float newTime = 0.0;
		bool redraw = false;
		while(!g_engine->Running())
		{
			oldTime = newTime;
			newTime = al_get_time();
			float deltaTime = newTime - oldTime;
		
			if( g_engine->GetEvent()->Tick())
			{ 
				g_game->Update(deltaTime);
				redraw = true;
			}

			if(redraw )
			{
				redraw = false;
				g_engine->UpdateEngine(deltaTime);	
			}
		}
	}
	delete g_game;
	g_engine->DeInit();
	delete g_engine;

	return 0;
}

