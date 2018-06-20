/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

char *add_char(char *str, char content)
{
	char *result = malloc(sizeof(char) * my_strlen(str) + 2);
	int i = 0;

	while (str[i]) {
		result[i] = str[i];
		i = i + 1;
	}
	result[i] = content;
	result[i + 1] = '\0';
	return (result);
}

sfRectangleShape *textuchar(sfRectangleShape *sprite, char content)
{
	char *path = add_char("ressources/ARVANA/TEXTURE/", content);
	path = my_strcat(path, ".png");
	sfTexture *texture = sfTexture_createFromFile(path, NULL);
	sfRectangleShape_setTexture(sprite, texture, sfFalse);
	return (sprite);
}

void create_spritemap(int x, int y, rpgcore_t *GAME, char content)
{
	sfRectangleShape *result = sfRectangleShape_create();
	sfVector2f size;
	sfVector2f pos;
	size.x = 100;
	size.y = 100;
	pos.x = 100 * x;
	pos.y = 100 * y;

	sfRectangleShape_setPosition(result, pos);
	sfRectangleShape_setSize(result, size);
	result = textuchar(result, GAME->map[y][x]);
	GAME->rmap[y][x] = result;
}
