/*
** EPITECH PROJECT, 2017
** move_leg.c
** File description:
**
*/

#include "my_rpg.h"

sfVector2f random_long(sfVector2f hitbox_p, int random)
{
}

void move_leg(rpgcore_t *GAME)
{
	int seconds = 0;
	GAME->player->time = sfClock_getElapsedTime(GAME->player->clock);
	seconds = GAME->player->time.microseconds/10000.0;

	if (seconds > 30) {
		if (GAME->player->skin.left >= 280) {
			GAME->player->skin.left = 10;
			sfClock_restart(GAME->player->clock);
		} else {
			GAME->player->skin.left = GAME->player->skin.left + 100;
			sfClock_restart(GAME->player->clock);
		}
	}
}
