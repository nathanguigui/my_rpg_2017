/*
** EPITECH PROJECT, 2017
** game_event.c
** File description:
**
*/

#include "my_rpg.h"

sfIntRect zombie_coordright(void)
{
	sfIntRect result;

	result.top = 10;
	result.left = 0;
	result.width = 65;
	result.height = 62;

	return (result);
}