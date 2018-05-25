/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

void menu_switch(rpgcore_t *GAME)
{
	static int status = 0;
	switch (GAME->menu) {
	case 1:
		main_menu(GAME);
		break;
	case 2:
		break;
	case -1:
		move_legmob(GAME->mob);
		text_sprite(GAME);
		power_mvm(GAME);
		refresh_map(GAME);
		break;
		
	}
	if (status == 0) {
		status = 1;
		sfRenderWindow_display(GAME->window);
	}
}

int main(void)
{
	rpgcore_t *GAME = create_core();

	sfVector2f pos;
	GAME->player->skin = player_coordup();
	GAME->ia->skin = player_coordup();

	sfSprite_setPosition(GAME->player->sprite, GAME->player->vec);
	sfSprite_setPosition(GAME->ia->sprite, GAME->ia->vec);
	sfSprite_setTextureRect(GAME->player->sprite, GAME->player->skin);
	sfSprite_setTextureRect(GAME->ia->sprite, GAME->ia->skin);
	sfSprite_setTextureRect(GAME->power->sprite, GAME->power->skin);
	sfSprite_setPosition(GAME->power->sprite, GAME->power->vec);

	file_to_map(GAME, "ressources/map-tutorial.txt");
	load_map(GAME, "ressources/map-tutorial.txt");
	GAME->power->vec.y = GAME->player->vec.y + 50;
	GAME->power->vec.x = GAME->player->vec.x + 50;

	while (sfRenderWindow_isOpen(GAME->window)) {
		while (sfRenderWindow_pollEvent(GAME->window, &GAME->event))
				detect_evnt(GAME);
			menu_switch(GAME);
	}
	sfRenderWindow_destroy(GAME->window);
	return (0);
}
