/*
** EPITECH PROJECT, 2017
** create_core.c
** File description:
**
*/

#include "my_rpg.h"

/*
rpgcore_t *struct_malloc(rpgcore_t *GAME)
{
	rpgcore_t *GAME = malloc(sizeof(rpgcore_t));
	GAME->player = malloc(sizeof(player_t));
	GAME->ia = malloc(sizeof(player_t));
	sfVideoMode mode = {1920, 1080, 32};

}
*/
void init_entity(rpgcore_t *GAME)
{
	GAME->player->sprite = sfSprite_create();
	sfTexture *player_tx = sfTexture_createFromFile("skin.png", NULL);
	GAME->power->sprite = sfSprite_create();
	GAME->ia->sprite = sfSprite_create(); 
	GAME->mob->sprite = sfSprite_create();
	sfTexture *power_tx = sfTexture_createFromFile("ressources/EFFECT/EFFECT.png", NULL);
	sfTexture *ia_tx = sfTexture_createFromFile("skin.png", NULL);
	sfTexture *mob_tx = sfTexture_createFromFile("mob.png", NULL);
	sfSprite_setTexture(GAME->power->sprite, power_tx, sfTrue);
	sfSprite_setTexture(GAME->player->sprite, player_tx, sfTrue);
	sfSprite_setTexture(GAME->ia->sprite, ia_tx, sfTrue);
	sfSprite_setTexture(GAME->mob->sprite, mob_tx, sfTrue);
	sfSprite_setTextureRect(GAME->mob->sprite, GAME->mob->skin);
	sfSprite_setPosition(GAME->mob->sprite, GAME->mob->vec);
	GAME->mob->clock = sfClock_create();
	GAME->power->clock = sfClock_create();
	GAME->player->clock = sfClock_create();
	GAME->ia->clock = sfClock_create();
}

rpgcore_t *create_core(void)
{
	char *title = "My RPG solo";
	
	rpgcore_t *GAME = malloc(sizeof(rpgcore_t));
	GAME->menu = 1;
	GAME->player = malloc(sizeof(player_t));
	GAME->ia = malloc(sizeof(player_t));
	GAME->mob = malloc(sizeof(player_t));
	GAME->power = malloc(sizeof(power_t));
	sfVideoMode mode = {1100, 600, 32};
	GAME->draws = sfRenderWindow_drawSprite;
	GAME->drawr = sfRenderWindow_drawRectangleShape;
	GAME->player->life = 100;
	GAME->player->vec.y = 500;
	GAME->player->vec.x = 500;
	GAME->ia->vec.x = 783;
	GAME->ia->vec.y = 500;
	GAME->mob->vec.x = 200;
	GAME->mob->vec.y = 200;
	GAME->power->save = 0;
	GAME->mapnb = 1;
	GAME->mob->life = 10;
	GAME->map_coord.x = 0;
	GAME->map_coord.y = 0;
	int map_x = 0;
	int map_y = 0;
	GAME->world = "ARVANA";
	GAME->window = sfRenderWindow_create(mode, title, sfClose , NULL);
	init_entity(GAME);
	return (GAME);
}
