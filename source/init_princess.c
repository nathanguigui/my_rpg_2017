/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

sfIntRect princess_coordup(void)
{
	sfIntRect result;

	result.top = 290;
	result.left = 5;
	result.width = 90;
	result.height = 95;

	return (result);
}

sfIntRect princess_coordleft(void)
{
	sfIntRect result;

	result.top = 100;
	result.left = 5;
	result.width = 90;
	result.height = 90;

	return (result);
}

sfIntRect princess_coordright(void)
{
	sfIntRect result;

	result.top = 200;
	result.left = 5;
	result.width = 90;
	result.height = 90;
	
	return (result);
}

sfIntRect princess_coorddown(void)
{
	sfIntRect result;

	result.top = 0;
	result.left = 5;
	result.width = 90;
	result.height = 90;

	return (result);
}