#include "StdAfx.h"
#include "Engine.h"
#include "World.h"
#include "ActorPool.h"
#include <math.h>

Engine* Engine::Instance = 0;

Engine::Engine():
path(nullptr),
display(nullptr),
OldTime(0.0),
NewTime(0.0),
DeltaTime(0.0)
{
}

Engine* Engine::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new Engine();
	}
	return Instance;
}


int Engine::Init()
{
	Event = EventManager::GetInstance();
	Input = InputManager::GetInstance();

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
	
	if (Event != nullptr && Input != nullptr)
	{
		Event->Init();
		Input->Init(Event->GetEventQueue());
	}

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

void Engine::LoadAsset(IActor* Actor, char* asset)
{	
	ALLEGRO_BITMAP *loadbitmap;
	if (Actor != nullptr)
	{
		if(path)
		{
			al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
			loadbitmap = al_load_bitmap(asset);
			if(!loadbitmap)
			{
				al_destroy_bitmap(loadbitmap);
				return;
			}
			Actor->SetSprite(loadbitmap);
		}
	}
}

void Engine::UpdateEngine(float deltaTime)
{
	World* wWorld = World::GetInstance();

	if (Event != nullptr && Input != nullptr)
	{
		Event->Update(deltaTime);
		Input->UpdateInput();
	}

	al_clear_to_color(al_map_rgb(0,0,0));

	if (wWorld != nullptr)
	{
		ActorPool* Pool = ActorPool::GetInstance();
		if (Pool != nullptr)
		{
			Pool->DrwaActorPool();
		}
	}

	al_flip_display();
}
float Engine::GetDeltaTime()
{
	OldTime = NewTime;
	NewTime = al_get_time();
	return DeltaTime = NewTime - OldTime;
}


Vector2 Engine::GetActorSize(int OwnerId)
{
	float w =0.f,h=0.f;
	Vector2 size(0,0);

	/*TActorMap::iterator it;
	if (actor != nullptr)
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
	}*/
	return Vector2(0,0);
}

ALLEGRO_PATH* Engine::GetPath()
{
		return path;
}

vector<char> Engine::GetFile(const char* xml)
{ 
	char FullPath[64] = "../Actor/";

	if (xml != nullptr)
	{
		strcat(FullPath, xml);
	}

	ifstream theFile(FullPath);

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	return buffer;
}

Vector2 Engine::GetScreenSize()
{
	return Vector2 (al_get_display_height(display),al_get_display_width(display));
}

float Engine::GetCurrentTime()
{
	return (float)al_get_time();
}

EventManager* Engine::GetEventManager()
{
	if (Event != nullptr)
	{
		return  Event;
	}
	return nullptr;
}
float Engine::RandToFloat(float min,float max)
{
	std::mt19937		gen(random());
	std::uniform_real_distribution<float> dis(min,max);

	return dis(gen);
}

Engine::~Engine(void)
{
	al_destroy_path(path);
	al_destroy_display(display);
	delete Event;
}
