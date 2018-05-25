/*
** EPITECH PROJECT, 2017
** create_mainmenu.c
** File description:
**
*/

#include "my_rpg.h"

void create_back(rpgcore_t *GAME)
{
	sfVector2f size;
	sfVector2f pos;
	sfTexture *texture = sfTexture_createFromFile("background.jpg", NULL);
	pos.x = 0;
	pos.y = 0;
	size.x = 1100;
	size.y = 600;
	sfRectangleShape *back = sfRectangleShape_create();
	sfRectangleShape_setPosition(back, pos);
	sfRectangleShape_setTexture(back, texture, sfFalse);
	sfRectangleShape_setSize(back, size);

	GAME->rmenu[0] = back;
}

void create_about(rpgcore_t *GAME)
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
	sfRectangleShape_setTexture(about, texture, sfFalse);
	sfRectangleShape_setSize(about, size);

	GAME->rmenu[1] = about;
}

void create_play(rpgcore_t *GAME)
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
	sfRectangleShape_setTexture(play, texture, sfFalse);
	sfRectangleShape_setSize(play, size);

	GAME->rmenu[2] = play;
}

void create_exit(rpgcore_t *GAME)
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
	sfRectangleShape_setTexture(exit, texture, sfFalse);
	sfRectangleShape_setSize(exit, size);

	GAME->rmenu[3] = exit;
}

void main_menu(rpgcore_t *GAME)
{
	create_back(GAME);
	create_about(GAME);
	create_play(GAME);
	create_exit(GAME);
	(*GAME->drawr)(GAME->window, GAME->rmenu[0], NULL);
	(*GAME->drawr)(GAME->window, GAME->rmenu[1], NULL);
	(*GAME->drawr)(GAME->window, GAME->rmenu[2], NULL);
	(*GAME->drawr)(GAME->window, GAME->rmenu[3], NULL);
	menu_event(GAME);
}
