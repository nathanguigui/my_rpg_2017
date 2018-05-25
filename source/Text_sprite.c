/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

void text_sprite(rpgcore_t *GAME)
{
	sfSprite_setTextureRect(GAME->player->sprite, GAME->player->skin);
	(*GAME->draws)(GAME->window, GAME->player->sprite, NULL);
	(*GAME->draws)(GAME->window, GAME->power->sprite, NULL);
	sfSprite_setTextureRect(GAME->ia->sprite, GAME->ia->skin);
	(*GAME->draws)(GAME->window, GAME->ia->sprite, NULL);
	if (GAME->map_x == 2 && GAME->map_y == 1)
		(*GAME->draws)(GAME->window, GAME->mob->sprite, NULL);
	if (GAME->player->vec.y > GAME->ia->vec.y) {
		(*GAME->draws)(GAME->window, GAME->ia->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->player->sprite, NULL);
	} else if (GAME->player->vec.y <= GAME->ia->vec.y){
		(*GAME->draws)(GAME->window, GAME->player->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->ia->sprite, NULL);
	}
	if (GAME->player->inventory == 1)
		open_inventory(GAME);
	sfRenderWindow_display(GAME->window);
}