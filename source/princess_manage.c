/*
** EPITECH PROJECT, 2017
** game_event.c
** File description:
**
*/

#include "my_rpg.h"

void move_princess(player_t *princess)
{
	int seconds = 0;
	princess->time = sfClock_getElapsedTime(princess->clock);
	seconds = princess->time.microseconds/10000.0;
	if (seconds > 30) {
		if (princess->skin.left >= 301) {
			princess->skin.left = 0;
			sfClock_restart(princess->clock);
		} else {
			princess->skin.left = princess->skin.left + 10;
			sfClock_restart(princess->clock);
			}
		}
}

void princess_advance(player_t *princess)
{

	int princess1 = rand() % 4 + 1;
	int a = 0;

	if (princess1 == 1) {
		princess->skin = princess_coordright();
		princess->vec.x = princess->vec.x + 15;
		sfSprite_setTextureRect(princess->sprite, princess->skin);
		sfSprite_setPosition(princess->sprite, princess->vec);
		move_princess(princess);
		}
	if (princess == 2) {
		princess->skin = princess_coordright();
		princess->vec.x = princess->vec.x - 15;
		sfSprite_setTextureRect(princess->sprite, princess->skin);
		sfSprite_setPosition(princess->sprite, princess->vec);
		move_princess(princess);
		}
	if (princess1 == 2) {
		princess->skin = princess_coordup();
		princess->vec.y = princess->vec.y + 15;
		sfSprite_setTextureRect(princess->sprite, princess->skin);
		sfSprite_setPosition(princess->sprite, princess->vec);
		move_princess(princess);
	}
	if (princess1 == 3) {
		princess->skin = princess_coorddown();
		princess->vec.y = princess->vec.y - 15;
		sfSprite_setTextureRect(princess->sprite, princess->skin);
		sfSprite_setPosition(princess->sprite, princess->vec);
		move_princess(princess);
	}
}

void move_legprinc(player_t *princess)
{
	int seconds = 0;
	princess->time = sfClock_getElapsedTime(princess->clock);
	seconds = princess->time.microseconds/10000.0;
	
	if (seconds > 100) {
			princess_advance(princess);
			sfClock_restart(princess->clock);
		}
}