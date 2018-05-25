/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

sfIntRect player_coordup(void)
{
	sfIntRect result;

	result.top = 673;
	result.left = 10;
	result.width = 70;
	result.height = 97;

	return (result);
}

sfIntRect player_coordleft(void)
{
	sfIntRect result;

	result.top = 480;
	result.left = 10;
	result.width = 70;
	result.height = 97;

	return (result);
}

 sfIntRect player_coordright(void)
{
	sfIntRect result;

	result.top = 576;
	result.left = 10;
	result.width = 70;
	result.height = 97;
	
	return (result);
}



sfIntRect player_coorddown(void)
{
	sfIntRect result;

	result.top = 385;
	result.left = 10;
	result.width = 75;
	result.height = 95;

	return (result);
}

