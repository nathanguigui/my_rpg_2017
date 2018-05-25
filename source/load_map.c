/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
**
*/

#include "my_rpg.h"

void file_to_map(rpgcore_t *GAME, char *name)
{
	char *line = NULL;
	int fd = open(name, O_RDONLY);
	int x = 0;
	int y = 0;

	while (line = get_next_line(fd)) {
		x = 0;
		while (x != 11) {
			GAME->map[y][x] = line[x];
			x = x + 1 ;
		}
		GAME->map[y][x] = '\0';
		y = y + 1;
	}
}

void load_map(rpgcore_t *GAME, char *name)
{
	int y = 0;
	int x = 0;

	while (y != 6) {
		while (x != 11) {
			create_spritemap(x, y, GAME, GAME->map[y][x]);
			x = x + 1;
		}
		x = 0;
		y = y + 1;
	}
}