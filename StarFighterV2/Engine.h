#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <map>
#include <random>
#include "IEngine.h"
#include "IActor.h"
#include "Event.h"
#include "Camera.h"
#include "IEmiter.h"
#include "Emiter.h"
#include "IGame.h"

//typedef std::map<IActor* , ALLEGRO_BITMAP*>		TActorMap;
typedef std::map< int , ALLEGRO_BITMAP*>			TActorMap;

class Engine : public IEngine
{
private:

	std::random_device  random;

	ALLEGRO_PATH		*path;
	ALLEGRO_DISPLAY		*display;
	ALLEGRO_BITMAP*		*bitmap;
	ALLEGRO_BITMAP*		backgrund;

	Event				*aEvent;
	Camera				*pCamera;
	IGame				*pGame;

	TActorMap		mapActor;

	int InitPath();
	int DrawSurface();
	
	void Render();
public:

	IActor				*mActor;
	IEngine				*mEngine;

	Engine();
	~Engine();

	virtual int Init();
	
	virtual void DeInit();

	virtual void UpdateEngine(float deltaTime);

	virtual void AddDrawActor(IActor* aActor);

	virtual Vector2 GetScreenSize();
	virtual Vector2 GetActorSize(int OwnerId);
	virtual ALLEGRO_PATH* GetPath();

	virtual IEngine* GetEgnine();

	virtual IEvent* GetEvent();
	virtual float GetCurrentTime();
	virtual float RandToFloat(float a,float b);
	virtual long long int Uniq_ID();

	bool Running() {return aEvent->done; };
	void SetGame(IGame* game) { pGame = game; };
	virtual IGame* GetGame() { return pGame; };
};

