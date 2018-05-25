/*
** EPITECH PROJECT, 2017
** game_event.c
** File description:
**
*/

#include "my_rpg.h"

void move_mob(player_t *mob)
{
	int seconds = 0;
	mob->time = sfClock_getElapsedTime(mob->clock);
	seconds = mob->time.microseconds/10000.0;
	if (seconds > 30) {
		if (mob->skin.left >= 301) {
			mob->skin.left = 0;
			sfClock_restart(mob->clock);
		} else {
			mob->skin.left = mob->skin.left + 100;
			sfClock_restart(mob->clock);
			}
		}
}

void mob_advance(player_t *mob)
{

	int mob1 = random() % 4 + 1;
	int a = 0;

	if (mob1 == 1) {
		mob->skin = mob_coordright();
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_mob(mob);
		mob->vec.x = mob->vec.x + 15;
		}
	if (mob == 2) {
		mob->skin = mob_coordright();
		mob->vec.x = mob->vec.x - 9;
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_mob(mob);
		}
	if (mob1 == 2) {
		mob->skin = mob_coordup();
		mob->vec.y = mob->vec.y + 15;
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_mob(mob);
	}
	if (mob1 == 3) {
		mob->skin = mob_coorddown();
		mob->vec.y = mob->vec.y - 15;
		sfSprite_setTextureRect(mob->sprite, mob->skin);
		sfSprite_setPosition(mob->sprite, mob->vec);
		move_mob(mob);
	}
}

void move_legmob(player_t *mob)
{
	int seconds = 0;
	mob->time = sfClock_getElapsedTime(mob->clock);
	seconds = mob->time.microseconds/10000.0;
	
	if (seconds > 30) {
			mob_advance(mob);
			sfClock_restart(mob->clock);
		}
}