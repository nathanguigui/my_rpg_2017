/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

sfRectangleShape *player_slot(void)
{
	sfVector2f size;
	sfVector2f pos;
	size.x = 125;
	size.y = 275;
	pos.x = 790 + 175;
	pos.y = 290 + 25;
	sfRectangleShape *inv_slot = sfRectangleShape_create();

	sfRectangleShape_setPosition(inv_slot, pos);
	sfRectangleShape_setSize(inv_slot, size);
	sfRectangleShape_setFillColor(inv_slot, sfBlack);
	return (inv_slot);
}

sfRectangleShape *stat_bar(int nbr)
{
	sfVector2f size;
	sfVector2f pos;
	size.x = 125;
	size.y = 50;
	pos.x = 790 + 25;
	pos.y = 290 + 100 + (nbr - 1) * 75;
	sfRectangleShape *inv_slot = sfRectangleShape_create();

	sfRectangleShape_setPosition(inv_slot, pos);
	sfRectangleShape_setSize(inv_slot, size);
	sfRectangleShape_setFillColor(inv_slot, sfBlack);
	return (inv_slot);
}
