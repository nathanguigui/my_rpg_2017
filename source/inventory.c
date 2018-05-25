/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

sfRectangleShape *inv_base(void)
{
	sfVector2f size;
	sfVector2f pos;
	size.x = 400;
	size.y = 500;
	pos.x = 790;
	pos.y = 290;
	sfRectangleShape *inv_base = sfRectangleShape_create();

	sfRectangleShape_setPosition(inv_base, pos);
	sfRectangleShape_setSize(inv_base, size);
	sfRectangleShape_setFillColor(inv_base, sfGreen);
	return (inv_base);
}

sfRectangleShape *inv_slot_l1(int nbr)
{
	sfVector2f size;
	sfVector2f pos;
	size.x = 50;
	size.y = 50;
	pos.x = 790 + 25 * nbr + (nbr - 1) * 50;
	pos.y = 290 + 350;
	sfRectangleShape *inv_slot = sfRectangleShape_create();

	sfRectangleShape_setPosition(inv_slot, pos);
	sfRectangleShape_setSize(inv_slot, size);
	sfRectangleShape_setFillColor(inv_slot, sfBlack);
	return (inv_slot);
}

sfRectangleShape *stuff_slot(int nbr)
{
	sfVector2f size;
	sfVector2f pos;
	size.x = 50;
	size.y = 50;
	pos.x = 790 + 325;
	pos.y = 290 + 25 + (nbr - 1) * 75;
	sfRectangleShape *inv_slot = sfRectangleShape_create();

	sfRectangleShape_setPosition(inv_slot, pos);
	sfRectangleShape_setSize(inv_slot, size);
	sfRectangleShape_setFillColor(inv_slot, sfBlack);
	return (inv_slot);
}

sfRectangleShape *inv_slot_l2(int nbr)
{
	sfVector2f size;
	sfVector2f pos;
	size.x = 50;
	size.y = 50;
	pos.x = 790 + 25 * nbr + (nbr - 1) * 50;
	pos.y = 290 + 350 + 75;
	sfRectangleShape *inv_slot = sfRectangleShape_create();

	sfRectangleShape_setPosition(inv_slot, pos);
	sfRectangleShape_setSize(inv_slot, size);
	sfRectangleShape_setFillColor(inv_slot, sfBlack);
	return (inv_slot);
}

void open_inventory(rpgcore_t *GAME)
{
	sfRenderWindow_drawRectangleShape(GAME->window, inv_base(), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l1(1), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l1(2), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l1(3), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l1(4), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l1(5), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l2(1), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l2(2), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l2(3), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l2(4), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, inv_slot_l2(5), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, stuff_slot(1), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, stuff_slot(2), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, stuff_slot(3), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, stuff_slot(4), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, player_slot(), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, stat_bar(1), NULL);
	sfRenderWindow_drawRectangleShape(GAME->window, stat_bar(2), NULL);
}
