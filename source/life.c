/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

void update_life(rpgcore_t *GAME)
{
	sfVector2f pos = GAME->player->vec;
	pos.y = pos.y - 42;
	sfText_setPosition(GAME->player->ltext, pos);
	sfText_setString(GAME->player->ltext, nb_to_str(GAME->player->life));
	sfRenderWindow_drawText(GAME->window, GAME->player->ltext, NULL);
}

void update_moblife(rpgcore_t *GAME)
{
	sfVector2f pos = GAME->mob->vec;
	pos.y = pos.y - 42;
	sfText_setPosition(GAME->mob->ltext, pos);
	sfText_setString(GAME->mob->ltext, nb_to_str(GAME->mob->life));
	sfRenderWindow_drawText(GAME->window, GAME->mob->ltext, NULL);
}