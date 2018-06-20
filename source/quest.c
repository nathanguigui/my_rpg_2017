/*
** EPITECH PROJECT, 2017
** quest
** File description:
** header
*/

#include "my_rpg.h"

void experience(rpgcore_t *GAME)
{
	char *str = nb_to_str(GAME->player->exp);
	sfVector2f position = {0, 0};
	sfVector2f position2 = {35, 0};
	GAME->text = sfText_create();
	GAME->text2 = sfText_create();

	sfText_setString(GAME->text, "XP:");
	sfText_setString(GAME->text2, str);
	sfText_setFont(GAME->text, GAME->font);
	sfText_setFont(GAME->text2, GAME->font);
	sfText_setCharacterSize(GAME->text, 20);
	sfText_setCharacterSize(GAME->text2, 20);
	sfText_setPosition(GAME->text,position);
	sfText_setPosition(GAME->text2,position2);
}

void quest(rpgcore_t *GAME, char *str)
{
	GAME->quest_str = sfText_create();
	sfVector2f position2 = {0, 560};

	sfText_setString(GAME->quest_str, str);
	sfText_setFont(GAME->quest_str, GAME->font);
	sfText_setCharacterSize(GAME->quest_str, 20);
	sfText_setPosition(GAME->quest_str,position2);
}