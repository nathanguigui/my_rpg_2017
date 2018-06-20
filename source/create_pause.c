/*
** EPITECH PROJECT, 2017
** create_mainpause.c
** File description:
**
*/

#include "my_rpg.h"

void create_back1(rpgcore_t *GAME)
{
	sfVector2f size;
	sfVector2f pos;
	sfTexture *texture = sfTexture_createFromFile("pause.jpg", NULL);
	pos.x = 0;
	pos.y = 0;
	size.x = 1100;
	size.y = 600;
	sfRectangleShape *back = sfRectangleShape_create();
	sfRectangleShape_setPosition(back, pos);
	sfRectangleShape_setSize(back, size);
	sfRectangleShape_setTexture(back, texture, sfFalse);

	GAME->rpause[0] = back;
}

void create_about1(rpgcore_t *GAME)
{
	sfVector2f size;
	sfVector2f pos;
	sfTexture *texture = sfTexture_createFromFile("ressources/about.png", NULL);
	pos.x = 350.57;
	pos.y = 244.44;
	size.x = 402.30;
	size.y = 111.11;
	sfRectangleShape *about = sfRectangleShape_create();
	sfRectangleShape_setPosition(about, pos);
	sfRectangleShape_setSize(about, size);
	sfRectangleShape_setTexture(about, texture, sfFalse);

	GAME->rpause[1] = about;
}

void create_play1(rpgcore_t *GAME)
{
	sfVector2f size;
	sfVector2f pos;
	sfTexture *texture = sfTexture_createFromFile("ressources/play.png", NULL);
	pos.x = 393.68;
	pos.y = 0;
	size.x = 316.09;
	size.y = 111.11;
	sfRectangleShape *play = sfRectangleShape_create();
	sfRectangleShape_setPosition(play, pos);
	sfRectangleShape_setSize(play, size);
	sfRectangleShape_setTexture(play, texture, sfFalse);

	GAME->rpause[2] = play;
}

void create_exit1(rpgcore_t *GAME)
{
	sfVector2f size;
	sfVector2f pos;
	sfTexture *texture = sfTexture_createFromFile("ressources/exit.png", NULL);
	pos.x = 422.41;
	pos.y = 444.44;
	size.x = 258.62;
	size.y = 111.11;
	sfRectangleShape *exit = sfRectangleShape_create();
	sfRectangleShape_setPosition(exit, pos);
	sfRectangleShape_setSize(exit, size);
	sfRectangleShape_setTexture(exit, texture, sfFalse);

	GAME->rpause[3] = exit;
}

void main_pause(rpgcore_t *GAME)
{
	create_back1(GAME);
	create_about1(GAME);
	create_play1(GAME);
	create_exit1(GAME);
	(*GAME->drawr)(GAME->window, GAME->rpause[0], NULL);
	(*GAME->drawr)(GAME->window, GAME->rpause[1], NULL);
	(*GAME->drawr)(GAME->window, GAME->rpause[2], NULL);
	(*GAME->drawr)(GAME->window, GAME->rpause[3], NULL);
}
