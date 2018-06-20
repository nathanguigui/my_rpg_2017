/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

int is_solid_block(char block)
{
	int ret_value = 0;
	ret_value = (block == 'L') ? 1 : 0;
	ret_value = (block == 'M') ? 1 : 0;

	return (ret_value);
}

int my_round(float nbr)
{
	int result = 0;
	nbr = nbr / 100;
	result = (int)(nbr);
	return (result);
}

void can_player_left(rpgcore_t *GAME)
{
	int x_pos = my_round(GAME->player->vec.x);
	int y_pos = my_round(GAME->player->vec.y);
	if (is_solid_block(GAME->map[y_pos][x_pos - 1]))
		GAME->player->can_left = 0;
	else
		GAME->player->can_left = 1;
}

void can_player_right(rpgcore_t *GAME)
{
	int x_pos = my_round(GAME->player->vec.x);
	int y_pos = my_round(GAME->player->vec.y);
	if (is_solid_block(GAME->map[y_pos][x_pos + 1]))
		GAME->player->can_right = 0;
	else
		GAME->player->can_right = 1;
}

void can_player_top(rpgcore_t *GAME)
{
	int x_pos = my_round(GAME->player->vec.x);
	int y_pos = my_round(GAME->player->vec.y - 110);
	if (is_solid_block(GAME->map[y_pos + 1][x_pos]))
		GAME->player->can_top = 0;
	else
		GAME->player->can_top = 1;
}

void can_player_bottom(rpgcore_t *GAME)
{
	int x_pos = my_round(GAME->player->vec.x);
	int y_pos = my_round(GAME->player->vec.y + 100);
	if (is_solid_block(GAME->map[y_pos][x_pos]))
		GAME->player->can_bottom = 0;
	else
		GAME->player->can_bottom = 1;
}