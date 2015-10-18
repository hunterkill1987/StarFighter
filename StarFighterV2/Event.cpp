#include "StdAfx.h"
#include "Event.h"

Event::Event():
	event_queue(NULL),
	timer(NULL),
	done(false),
	b_input(0)
{
}

int Event::Init()
{
	fprintf(stderr, "init event \n");
	

	if(!al_install_keyboard()) 
	{
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 /FPS);
	if(!event_queue) 
	{
		fprintf(stderr, "failed to create event_queue!\n");
		return -1;
	}

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	return 0;
}


int Event::UpdateInput()
{
	ALLEGRO_KEYBOARD_STATE	key_state;

	al_wait_for_event(event_queue,&events);
	al_get_keyboard_state(&key_state);

	if(events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(events.keyboard.keycode)
		{
			case ALLEGRO_KEY_UP:
							b_input =  b_input | ( 1 << UP ); 
							fprintf(stderr, "UpdatePlayer %i !\n",b_input);
							break;
			case ALLEGRO_KEY_DOWN:
							b_input = b_input | ( 1 << DOWN ); 
							fprintf(stderr, "UpdatePlayer %i !\n",b_input);
							break;
			case ALLEGRO_KEY_LEFT:
							b_input =  b_input | ( 1 << LEFT ); 
							fprintf(stderr, "UpdatePlayer %i !\n",b_input);
							break;
			case ALLEGRO_KEY_RIGHT:
							b_input =  b_input | ( 1 << RIGHT ); 
							fprintf(stderr, "UpdatePlayer %i !\n",b_input);
							break;
			case ALLEGRO_KEY_SPACE:
							b_input =  b_input | ( 1 << FIRE ); 
							fprintf(stderr, "UpdatePlayer %i !\n",b_input);
							break;

			default:		b_input = 0x00 ;
							break;
		}
	}
	else if (events.type ==ALLEGRO_EVENT_KEY_UP)
	{
		switch(events.keyboard.keycode)
		{
			case ALLEGRO_KEY_UP:				
							b_input =  b_input & ( ~ ( 1 << UP ));
							break;
			case ALLEGRO_KEY_DOWN:		
							b_input =  b_input & ( ~ ( 1 << DOWN )); 
							break;
			case ALLEGRO_KEY_LEFT:		
							b_input =  b_input & ( ~ ( 1 << LEFT )); 

							break;
			case ALLEGRO_KEY_RIGHT:						
							b_input =  b_input & ( ~ ( 1 << RIGHT )); 
							break;
			case ALLEGRO_KEY_SPACE:
							b_input =  b_input & ( ~ ( 1 << FIRE )); 
							break;
			default: break;
		}
	}

	return 0;
}


int Event::GetInput()
{
	return b_input;
}

int Event::GetInputState()
{
	return 1;
}

bool Event::Tick()
{
	//if(events.type == ALLEGRO_EVENT_TIMER )
	//{
		return true;
	//}
	//return false;
}

bool Event::IsQueue()
{
	if (al_is_event_queue_empty(event_queue))
	{
		return true;	
	}
	return false;
}

Event::~Event(void)
{
}
