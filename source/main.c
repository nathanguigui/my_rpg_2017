/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

void about(rpgcore_t *GAME)
{
	sfRectangleShape_destroy(GAME->rmenu[2]);
	sfRectangleShape_destroy(GAME->rmenu[3]);
}

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
		move_legprinc(GAME->princess);
		move_legzombie(GAME->zombie1);
		move_legzombie(GAME->zombie2);
		move_legzombie(GAME->zombie3);
		move_legzombie(GAME->zombie4);
		move_legzombie(GAME->zombie5);
		power_mvm(GAME);
		power_mvm2(GAME);
		quest(GAME, "la princesse a ete enleve");
		experience(GAME);
		text_sprite(GAME);
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
	srand(time(0));
	int i = 0;

	sfVector2f pos;
	GAME->player->skin = player_coordup();
	GAME->ia->skin = player_coordup();
	GAME->princess->skin = princess_coordleft();
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
			update_life(GAME);
			experience(GAME);
			menu_switch(GAME);
	}
	sfRenderWindow_destroy(GAME->window);
	return (0);
}