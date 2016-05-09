#include "../inc/include.h"


static GameObject *fish   [ 3 ];
static GameObject *splash [ 3 ];

static u8          nb_fish;
static u16         i;




static void _room_enter ( Room *room )
{
	nb_fish = goManagerFindAllByEntityId ( &waObjects, fish,   55 );   // Fish
	goManagerFindAllByEntityId ( &waObjects, splash, 56 );   // Splash

	for ( i = 0; i < nb_fish;   i++ )
	{
		fish   [ i ]->grabity = false;
		splash [ i ]->grabity = false;

		fish   [ i ]->counter = 0;
		splash [ i ]->counter = 0;

		SPR_setVisible ( fish   [ i ]->sprite, 1 );
		SPR_setVisible ( splash [ i ]->sprite, 0 );
	}
}



static void _room_stay ( Room *room )
{
	for ( i=0; i<nb_fish; i++ )
	{
		enemy_fish ( fish, splash, i );
	}
}



void room_funct_13_all ( Room *room, u8 action )
{
	if ( action == ROOM_ACTION_ENTER ) // enter
	{
		_room_enter ( room );
	}

	else if ( action == ROOM_ACTION_STAY ) // stay
	{
		_room_stay ( room );
	}

	else if ( action == ROOM_ACTION_LEAVE ) // leave
	{
		//_room_leave ( room );
	}
}
