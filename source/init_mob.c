/*
** EPITECH PROJECT, 2017
** init_mob.c
** File description:
** mob
*/

#include "my_rpg.h"

sfIntRect mob_coordright(void)
{
	sfIntRect result;

	result.top = 0;
	result.left = 0;
	result.width = 100;
	result.height = 100;

	return (result);
}

sfIntRect mob_coorddown(void)
{
	sfIntRect result;

	result.top = 100;
	result.left = 0;
	result.width = 100;
	result.height = 100;

	return (result);
}

sfIntRect mob_coordup(void)
{
	sfIntRect result;

	result.top = 200;
	result.left = 0;
	result.width = 100;
	result.height = 95;

	return (result);

}