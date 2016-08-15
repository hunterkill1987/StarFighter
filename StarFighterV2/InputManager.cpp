#include "StdAfx.h"
#include "InputManager.h"
#include "Engine.h"

InputManager* InputManager::Instance = 0;

InputManager* InputManager::GetInstance()
{
	if (Instance == 0)
	{
		Instance = new InputManager();
	}
	return Instance;
}

int InputManager::Init(ALLEGRO_EVENT_QUEUE *event_queue)
{
	if (event_queue != nullptr)
	{
		Input_queue = event_queue;
	}
	fprintf(stderr, "Init InputManager \n");
	
	if(!al_install_keyboard()) 
	{
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	InputEvent = EventManager::GetInstance();

	//TODO:Bind buttons to actions
	Engine* GEngine = Engine::GetInstance();
	if (GEngine != nullptr)
	{
		xml_document<> BindingList;
		vector<char> BindingXml = GEngine->GetFile("BindAction.xml");
		BindingList.parse<0>(&BindingXml[0]);
		xml_node<> * BindingListRootNode = BindingList.first_node("Binding");
		for (xml_node<> * BindingListNode = BindingListRootNode->first_node("Bind"); BindingListNode; BindingListNode = BindingListNode->next_sibling())
		{

		}
	}

	//InputEvent->RegisterEvent("MoveRight");
	//InputEvent->RegisterEvent("MoveLeft");
	//InputEvent->RegisterEvent("Move");
	//InputEvent->RegisterEvent("Back");

	return 0;
}

void InputManager::KeyPressed(ALLEGRO_EVENT &Event,int &KeyCode)
{
	//InputEvent->FireEvent("Move");
}

void InputManager::KeyReleased(ALLEGRO_EVENT &Event, int &KeyCode)
{
	//fprintf(stderr, "Init KeyReleased \n");
}

void InputManager::KeyDown(ALLEGRO_EVENT &Event, int &KeyCode)
{
	//InputEvent->FireEvent("Move");
}


int InputManager::UpdateInput()
{
	ALLEGRO_KEYBOARD_STATE	key_state;

	al_wait_for_event(Input_queue, &events);
	al_get_keyboard_state(&key_state);

	if(events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		KeyPressed(events, events.keyboard.keycode);
	}

	if (events.type ==ALLEGRO_EVENT_KEY_UP)
	{
		KeyReleased(events,events.keyboard.keycode);
	}

	if (al_key_down(&key_state, events.keyboard.keycode))
	{
		KeyDown(events, events.keyboard.keycode);
	}

	return 0;
}

InputManager::~InputManager(void)
{
}
