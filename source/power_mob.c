/*
** EPITECH PROJECT, 2017
** init_power.c
** File description:
** power
*/
#include "my_rpg.h"

void direction_power2(rpgcore_t *GAME)
{
	sfVector2f power_pos = sfSprite_getPosition(GAME->power2->sprite);
	sfFloatRect hit_b = sfSprite_getGlobalBounds (GAME->mob->sprite);
	if (GAME->power2->vec.y != 0 && GAME->power2->vec.x != 0){
		if (GAME->power2->dir == 'Z')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power2->vec.y = GAME->power2->vec.y - 1;
			} else {
				reset_power2(GAME);
			}
		if (GAME->power2->dir == 'S')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power2->vec.y = GAME->power2->vec.y + 1;
			} else {
				reset_power2(GAME);
			}
		if (GAME->power2->dir == 'D')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power2->vec.x = GAME->power2->vec.x + 1;
			} else {
				reset_power(GAME);
			}
		if (GAME->power2->dir == 'Q')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power2->vec.x = GAME->power2->vec.x - 1;
			} else {
				reset_power(GAME);
			}
		}
	
}
void reset_power2(rpgcore_t *GAME)
{
	GAME->power2->vec.y = -1000;
	GAME->power2->vec.x = -1000;
	sfSprite_setPosition(GAME->power2->sprite, GAME->power2->vec);
}

void power_mvm2(rpgcore_t *GAME)
{
	if (GAME->power2->boul == 1) {
		float seconds = 0;

		GAME->power2->time = sfClock_getElapsedTime(GAME->power2->clock);
		seconds = GAME->power2->time.microseconds/10000.0;
		if (GAME->power2->time.microseconds > 1) {
			if (GAME->power2->vec.y <= 0 || GAME->power2->vec.y == 700 
				|| GAME->power2->vec.x <= 0 || 
				GAME->power2->vec.x >= 1200) {
				GAME->power2->boul = 0;
				reset_power2(GAME);
		}
		else {
			direction_power2(GAME);
			sfSprite_setTextureRect(GAME->power2->sprite, GAME->power2->skin);
			sfSprite_setPosition(GAME->power2->sprite, GAME->power2->vec);
			sfClock_restart(GAME->power2->clock);
			}
		}
	}
}

void power_event2(rpgcore_t *GAME)
{
	int val = 0;

		GAME->power2->time = sfClock_getElapsedTime(GAME->power2->clock);
		int seconds = GAME->power2->time.microseconds/10000.0;
	if (GAME->power->time.microseconds > 100)
		val = rand() % 4;

	if (val == 1) {
		GAME->power2->skin = power_coordup();
		GAME->power2->vec.y = GAME->mob->vec.y + 55;
		GAME->power2->vec.x = GAME->mob->vec.x + 47;
		GAME->power2->boul = 1;
		GAME->power2->dir = 'Z';
	}
	if (val == 2) {
		GAME->power2->skin = power_coorddown();
		GAME->power2->vec.y = GAME->mob->vec.y + 55;
		GAME->power2->vec.x = GAME->mob->vec.x + 47;
		GAME->power2->boul = 1;
		GAME->power2->dir = 'S';
	}
	if (val == 3) {
		GAME->power2->skin = power_coordleft();
		GAME->power2->vec.y = GAME->mob->vec.y + 55;
		GAME->power2->vec.x = GAME->mob->vec.x + 47;
		GAME->power2->boul = 1;
		GAME->power2->dir = 'Q';
	}
	if (val == 4) {
		GAME->power2->skin = power_coordright();
		GAME->power2->vec.y = GAME->mob->vec.y + 55;
		GAME->power2->vec.x = GAME->mob->vec.x + 47;
		GAME->power2->boul = 1;
		GAME->power2->dir = 'D';
	}
}