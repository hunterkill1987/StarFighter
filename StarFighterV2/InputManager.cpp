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
			const char* KeyName = BindingListNode->first_attribute("BindButton")->value();
			for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
			{
				const char* alKeyName = al_keycode_to_name(i);
				if (alKeyName != nullptr )
				{
					if (strcmp(alKeyName,KeyName) == 0)
					{
						SButtonBind Bind;
						char* BindAction = strdup(BindingListNode->first_attribute("BindAction")->value());

						InputEvent->RegisterEvent(BindAction);
						
						Bind.Button = i;
						Bind.EvnetBind = BindAction;
						
						char* BindState = strdup(BindingListNode->first_attribute("BindState")->value());

						if (strcmp(BindState, "Pressed") == 0 )
						{
							Bind.State = EButtonState::EB_Pressed;
						}

						if (strcmp(BindState, "Hold") == 0)
						{
							Bind.State = EButtonState::EB_Hold;
						}

						if (strcmp(BindState, "Released")== 0)
						{
							Bind.State = EButtonState::EB_Released;
						}

						KeyMap.push_back(Bind);
						//KeyMap.insert(std::pair<int, char*>(i, BindAction));
					}
				}
			}
		}
	}

	return 0;
}

int InputManager::UpdateInput()
{
	ALLEGRO_KEYBOARD_STATE	key_state;

	al_wait_for_event(Input_queue, &events);
	al_get_keyboard_state(&key_state);

	for (SButtonBind Bind : KeyMap)
	{
		if (Bind.Button == events.keyboard.keycode)
		{
			if (Bind.State == EButtonState::EB_Pressed)
			{
				if (events.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					InputEvent->FireEvent(Bind.EvnetBind);
				}
			}

			if (Bind.State == EButtonState::EB_Released)
			{
				if (events.type == ALLEGRO_EVENT_KEY_UP)
				{
					InputEvent->FireEvent(Bind.EvnetBind);
				}
			}

			if (Bind.State == EButtonState::EB_Hold)
			{
				InputEvent->FireEvent(Bind.EvnetBind);
			}
		}
	}
	return 0;
}

InputManager::~InputManager(void)
{
}
