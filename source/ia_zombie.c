/*
** EPITECH PROJECT, 2017
** game_event.c
** File description:
**
*/

#include "my_rpg.h"

void move_zombie(player_t *mob)
{
	int seconds = 0;
	mob->time = sfClock_getElapsedTime(mob->clock);
	seconds = mob->time.microseconds/10000.0;
	if (seconds > 30) {
		if (mob->skin.left >= 301) {
			mob->skin.left = 0;
			sfClock_restart(mob->clock);
		} else {
			mob->skin.left = mob->skin.left + 110;
			sfClock_restart(mob->clock);
			}
		}
}

void zombie_advance(player_t *mob)
{

	int mob1 = rand() % 4 + 1;
	int a = 0;

	if (mob1 == 1) {
		mob->skin = zombie_coordright();
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_zombie(mob);
		mob->vec.x = mob->vec.x + 7;
		}
	if (mob1 == 2) {
		mob->skin = zombie_coordright();
		mob->vec.x = mob->vec.x - 7;
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_zombie(mob);
		}
	if (mob1 == 3) {
		mob->skin = zombie_coordright();
		mob->vec.y = mob->vec.y + 7;
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_zombie(mob);
	}
	if (mob1 == 3) {
		mob->skin = zombie_coordright();
		mob->vec.y = mob->vec.y - 7;
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_zombie(mob);
	}
}

void move_legzombie(player_t *mob)
{
	int seconds = 0;
	mob->time = sfClock_getElapsedTime(mob->clock);
	seconds = mob->time.microseconds/10000.0;
	
	if (seconds > 30) {
			zombie_advance(mob);
			sfClock_restart(mob->clock);
		}
}