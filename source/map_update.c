/*
** EPITECH PROJECT, 2017
** map_update.c
** File description:
** 
*/

#include "my_rpg.h"

void update_map(rpgcore_t *GAME)
{
	sfVector2i pos = GAME->map_coord;
	char *map_path = my_strcat("ressources/", GAME->world);
	map_path = my_strcat(map_path, "/MAP/map");
	map_path = add_char(map_path, GAME->map_x + 48);
	map_path = add_char(map_path, '.');
	map_path = add_char(map_path, GAME->map_y + 48);
	map_path = my_strcat(map_path, ".txt");
	file_to_map(GAME, map_path);
	load_map(GAME, map_path);
	refresh_map(GAME);

}

void refresh_map(rpgcore_t *GAME)
{
	for (int y = 0; y != 6; y++) {
		for (int x = 0; x != 11; x++)
			(*GAME->drawr)(GAME->window, GAME->rmap[y][x], NULL);
	}
}