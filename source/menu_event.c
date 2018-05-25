/*
** EPITECH PROJECT, 2017
** menu_event.c
** File description:
** 
*/

#include "my_rpg.h"

int is_collision2(sfVector2f pos, sfFloatRect hit_b)
{
	if (pos.x > hit_b.left && pos.x < hit_b.left + hit_b.width) {
		if (pos.y < hit_b.top - - hit_b.height && pos.y > hit_b.top) {
			return (1);
		}
	}
	return (0);
}

int is_collision(sfVector2i pos, sfFloatRect hit_b)
{
	if (pos.x > hit_b.left && pos.x < hit_b.left + hit_b.width) {
		if (pos.y < hit_b.top - - hit_b.height && pos.y > hit_b.top) {
			return (1);
		}
	}
	return (0);
}

void menu_event(rpgcore_t *GAME)
{
	sfVector2i mouse_pos = sfMouse_getPosition(GAME->window);
	sfFloatRect play_hb = sfRectangleShape_getGlobalBounds(GAME->rmenu[2]);
	sfFloatRect about_hb = sfRectangleShape_getGlobalBounds(GAME->rmenu[1]);
	sfFloatRect exit_hb = sfRectangleShape_getGlobalBounds(GAME->rmenu[3]);
	if (is_collision(mouse_pos, exit_hb) &&
		sfMouse_isButtonPressed(sfMouseLeft))
		exit(84);
	if (is_collision(mouse_pos, play_hb) &&
	sfMouse_isButtonPressed(sfMouseLeft)) {
		sfRectangleShape_destroy(GAME->rmenu[0]);
		sfRectangleShape_destroy(GAME->rmenu[1]);
		sfRectangleShape_destroy(GAME->rmenu[2]);
		sfRectangleShape_destroy(GAME->rmenu[3]);
		GAME->menu = -1;
	}
}