#include "StdAfx.h"
#include "Engine.h"
#include "Event.h"
#include "Player.h"
#include <math.h>

Engine::Engine():
	path(NULL),
	display(NULL),
	mActor(NULL),
	mEngine(NULL)
{
	mEngine = this;
	aEvent  = new Event();
}

int Engine::Init()
{
	if(!al_init()) {
	   fprintf(stderr, "failed to initialize allegro!\n");
	   return 0;
	}

    display = al_create_display(800, 600);

    if(!display) {
       fprintf(stderr, "failed to create display!\n");
	   al_destroy_display(display);
       return 0;
    }

	al_init_image_addon();
	al_clear_to_color(al_map_rgb(0,0,0));

	if(InitPath()==0)
	{
		fprintf(stderr,"Falid to Init Asset Path !!! \n");
		return -1;
	}
	
	if(aEvent)
	{
		aEvent->Init();
		
	}
	al_set_target_bitmap(al_get_backbuffer(display));
	return 1;
}

int Engine::InitPath()
{
	if(!path)
	{
		path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
		al_append_path_component(path, "Assets");
		al_change_directory(al_path_cstr(path, '/'));
		return 1;
	}
	else
	{
		return 0;
	} 
}

void Engine::AddDrawActor(IActor* actor)
{	
	ALLEGRO_BITMAP *loadbitmap;
	if( actor!= NULL)
	{
		if(path)
		{
			al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);

			loadbitmap = al_load_bitmap(actor->GetSurface());
			if(!loadbitmap)
			{
				al_destroy_bitmap(loadbitmap);
				return;
			}

			mapActor.insert(std::pair<int,ALLEGRO_BITMAP*>(pGame->GetActorId(actor), loadbitmap));

		}
	}
}

void Engine::DeInit()
{
	al_destroy_path(path);
	al_destroy_display(display);
	delete aEvent;
}

void Engine::UpdateEngine(float deltaTime)
{
	IActor* actor;

	ALLEGRO_BITMAP* buffer = al_create_bitmap(800,600);

	al_set_target_bitmap(buffer);
	al_clear_to_color(al_map_rgb(0,0,0));

	if( aEvent != NULL)
	{
		TActorMap::iterator it;
		for(it=mapActor.begin(); it!=mapActor.end(); ++it)
		{	
			actor = pGame->GetActorById(it->first);

			if(actor != NULL)
			{
				if( path)
				{
					al_convert_mask_to_alpha(it->second,(al_map_rgb(255,0,255)));

					IEmiter* emiter = dynamic_cast<IEmiter*>(actor);
					if(emiter == 0 )
					{
						Vector2 pos = actor->GetPosition();
						Vector2 rot = actor->GetRotation();

						float width = al_get_bitmap_width(it->second);
						float height = al_get_bitmap_height(it->second);

						double angle = atan2(rot.GetY(),rot.GetX());
						//fprintf(stderr,"engine angle %lf \n", angle * 180/ PI); 
						al_draw_rotated_bitmap(it->second,width/2,height/2,pos.GetX(),pos.GetY(),angle,0);
					}
					else
					if(emiter != 0)
					{
						if(emiter->IsActive())
						{
							emiter->DrawParticle(it->second);
						}
					}
				}
			}
		}
		aEvent->UpdateInput();
	}
	al_set_target_backbuffer(display);
	al_draw_bitmap(buffer,0,0,0);
	al_destroy_bitmap(buffer);
	al_flip_display();
}

Vector2 Engine::GetActorSize(int OwnerId)
{
	float w,h;
	Vector2 size(0,0);

	IActor* actor= pGame->GetActorById(OwnerId);

	TActorMap::iterator it;
	if(actor != NULL)
	{
		it  = mapActor.find(OwnerId);
		if (it != mapActor.end())
		{
			w = al_get_bitmap_width(it->second);
			h = al_get_bitmap_height(it->second);
			return size= Vector2(w,h);
		}
		else
		{

			fprintf(stderr, "Field too find actor !\n");
		}
	}
	return Vector2(0,0);
}

ALLEGRO_PATH* Engine::GetPath()
{
		return path;
}

Vector2 Engine::GetScreenSize()
{
	return Vector2 (al_get_display_height(display),al_get_display_width(display));
}

IEngine* Engine::GetEgnine()
{
	return mEngine;
}

IEvent* Engine::GetEvent()
{
		return aEvent;
}

float Engine::GetCurrentTime()
{
	return (float)al_get_time();
}

float Engine::RandToFloat(float min,float max)
{
	std::mt19937		gen(random());
	std::uniform_real_distribution<float> dis(min,max);

	return dis(gen);
}

long long int Engine::Uniq_ID()
{
	static unsigned long long int n = 0;
	return ++n;
}

Engine::~Engine(void)
{
}
