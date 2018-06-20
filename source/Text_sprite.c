/*
** EPITECH PROJECT, 2017
** main.c
** File description:
**
*/

#include "my_rpg.h"

void text_sprite(rpgcore_t *GAME)
{
	sfSprite_setTextureRect(GAME->player->sprite, GAME->player->skin);
	(*GAME->draws)(GAME->window, GAME->player->sprite, NULL);
	(*GAME->draws)(GAME->window, GAME->power->sprite, NULL);
	sfSprite_setTextureRect(GAME->ia->sprite, GAME->ia->skin);
	sfSprite_setTextureRect(GAME->princess->sprite, GAME->princess->skin);
	// (*GAME->draws)(GAME->window, GAME->ia->sprite, NULL);
		//(*GAME->draws)(GAME->window, GAME->princess->sprite, NULL);
	if (GAME->map_x == 2 && GAME->map_y == 1) {
		sfText_setString(GAME->quest_str, "trouvez le chateau");
	}
	if (GAME->map_x == 2 && GAME->map_y == 1) {
		(*GAME->draws)(GAME->window, GAME->mob->sprite, NULL);
		if(GAME->potion1->boul == 0)
			sfText_setString(GAME->quest_str, "sauvez la princess");
		else if(GAME->potion1->boul == 1)
			sfText_setString(GAME->quest_str, "soignez la princesse");
		(*GAME->draws)(GAME->window, GAME->zombie1->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->zombie2->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->zombie3->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->zombie4->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->zombie5->sprite, NULL);
		update_moblife(GAME);
	}
	if (GAME->map_x == 2 && GAME->map_y == 1) {
		(*GAME->draws)(GAME->window, GAME->princess->sprite, NULL);
	}
	if (GAME->player->vec.y > GAME->ia->vec.y) {
		(*GAME->draws)(GAME->window, GAME->ia->sprite, NULL);
		(*GAME->draws)(GAME->window, GAME->player->sprite, NULL);
	} else if (GAME->player->vec.y <= GAME->ia->vec.y){
		(*GAME->draws)(GAME->window, GAME->player->sprite, NULL);
		//(*GAME->draws)(GAME->window, GAME->ia->sprite, NULL);
	}
	if(GAME->potion1->boul > 0)
		(*GAME->draws)(GAME->window, GAME->potion1->sprite, NULL);
	if(GAME->potion1->boul > 1)
	(*GAME->draws)(GAME->window, GAME->potion2->sprite, NULL);
	if(GAME->potion1->boul > 2)
	(*GAME->draws)(GAME->window, GAME->potion3->sprite, NULL);
	if (GAME->player->inventory == 1)
		open_inventory(GAME);
	if (GAME->pause == 1) {
		main_pause(GAME);
		pause_break(GAME);
	}
	sfRenderWindow_drawText(GAME->window,GAME->text, NULL);
	sfRenderWindow_drawText(GAME->window,GAME->text2, NULL);
	sfRenderWindow_drawText(GAME->window,GAME->quest_str, NULL);
	// (*GAME->drawr)(GAME->window, GAME->quest, NULL);
	sfRenderWindow_display(GAME->window);
}