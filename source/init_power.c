/*
** EPITECH PROJECT, 2017
** init_power.c
** File description:
** power
*/
#include "my_rpg.h"

sfIntRect power_coordright(void)
{
	sfIntRect result;

	result.top = 125;
	result.left = 0;
	result.width = 30;
	result.height = 30;

	return (result);
}

sfIntRect power_coorddown(void)
{
	sfIntRect result;

	result.top = 125;
	result.left = 90;
	result.width = 30;
	result.height = 30;

	return (result);
}

sfIntRect power_coordup(void)
{
	sfIntRect result;

	result.top = 125;
	result.left = 35;
	result.width = 30;
	result.height = 30;

	return (result);

}

sfIntRect power_coordleft(void)
{
	sfIntRect result;

	result.top = 125;
	result.left = 60;
	result.width = 30;
	result.height = 30;

	return (result);
}

void life(rpgcore_t *GAME)
{
	GAME->mob->life = GAME->mob->life - 1;
	my_putnbr(GAME->ia->life);
	if (GAME->mob->life == 0){
		GAME->mob->vec.x = -1000;
		GAME->mob->vec.y = -1000;
		sfSprite_setPosition(GAME->power->sprite, GAME->power->vec);
		GAME->player->exp = GAME->player->exp + 10;
	}

}

void reset_power(rpgcore_t *GAME)
{
	GAME->power->vec.y = -1000;
	GAME->power->vec.x = -1000;
	sfSprite_setPosition(GAME->power->sprite, GAME->power->vec);
}
void direction_power(rpgcore_t *GAME)
{
	sfVector2f power_pos = sfSprite_getPosition(GAME->power->sprite);
	sfFloatRect hit_b = sfSprite_getGlobalBounds (GAME->mob->sprite);
	if (GAME->power->vec.y != 0 && GAME->power->vec.x != 0){
		if (GAME->power->dir == 'Z')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power->vec.y = GAME->power->vec.y - 1;
			} else {
				reset_power(GAME);
				life(GAME);
			}
		if (GAME->power->dir == 'S')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power->vec.y = GAME->power->vec.y + 1;
			} else {
				reset_power(GAME);
				life(GAME);
			}
		if (GAME->power->dir == 'D')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power->vec.x = GAME->power->vec.x + 1;
			} else {
				reset_power(GAME);
				life(GAME);
			}
		if (GAME->power->dir == 'Q')
			if (is_collision2(power_pos, hit_b) != 1){
				GAME->power->vec.x = GAME->power->vec.x - 1;
			} else {
				reset_power(GAME);
				life(GAME);
			}
		}
	
}

void power_mvm(rpgcore_t *GAME)
{
	if (GAME->power->boul == 1) {
		float seconds = 0;

		GAME->power->time = sfClock_getElapsedTime(GAME->power->clock);
		seconds = GAME->power->time.microseconds/10000.0;
		if (GAME->power->time.microseconds > 1) {
			if (GAME->power->vec.y <= 0 || GAME->power->vec.y == 700 
				|| GAME->power->vec.x <= 0 || 
				GAME->power->vec.x >= 1200) {
				GAME->power->boul = 0;
				reset_power(GAME);
		}
		else {
			direction_power(GAME);
			sfSprite_setTextureRect(GAME->power->sprite, GAME->power->skin);
			sfSprite_setPosition(GAME->power->sprite, GAME->power->vec);
			sfClock_restart(GAME->power->clock);
			}
		}
	}
}

void power_event(rpgcore_t *GAME)
{
	if ((GAME->event.type == sfEvtKeyPressed) && (GAME->event.key.code == sfKeyZ)) {
		GAME->power->skin = power_coordup();
		GAME->power->vec.y = GAME->player->vec.y + 55;
		GAME->power->vec.x = GAME->player->vec.x + 47;
		GAME->power->boul = 1;
		GAME->power->dir = 'Z';
	}
	if ((GAME->event.type == sfEvtKeyPressed) && (GAME->event.key.code == sfKeyS)) {
		GAME->power->skin = power_coorddown();
		GAME->power->vec.y = GAME->player->vec.y + 55;
		GAME->power->vec.x = GAME->player->vec.x + 47;
		GAME->power->boul = 1;
		GAME->power->dir = 'S';
	}
	if ((GAME->event.type == sfEvtKeyPressed) && (GAME->event.key.code == sfKeyQ)) {
		GAME->power->skin = power_coordleft();
		GAME->power->vec.y = GAME->player->vec.y + 55;
		GAME->power->vec.x = GAME->player->vec.x + 47;
		GAME->power->boul = 1;
		GAME->power->dir = 'Q';
	}
	if ((GAME->event.type == sfEvtKeyPressed) && (GAME->event.key.code == sfKeyD)) {
		GAME->power->skin = power_coordright();
		GAME->power->vec.y = GAME->player->vec.y + 55;
		GAME->power->vec.x = GAME->player->vec.x + 47;
		GAME->power->boul = 1;
		GAME->power->dir = 'D';
	}
}