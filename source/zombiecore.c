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
#include "my_rpg.h"

void init_zombie2(rpgcore_t *GAME)
{
	GAME->zombie1->sprite = sfSprite_create();
	sfTexture *zombie_tx = sfTexture_createFromFile("zombie7.png", NULL);
	sfSprite_setTexture(GAME->zombie1->sprite, zombie_tx, sfTrue);
	GAME->zombie1->skin = zombie_coordright();
	GAME->zombie1->clock = sfClock_create();
	GAME->zombie1->vec.x = 200;
	GAME->zombie1->vec.y = 200;

	GAME->zombie2->sprite = sfSprite_create();
	zombie_tx = sfTexture_createFromFile("zombie7.png", NULL);
	sfSprite_setTexture(GAME->zombie2->sprite, zombie_tx, sfTrue);
	GAME->zombie2->skin = zombie_coordright();
	GAME->zombie2->clock = sfClock_create();
	GAME->zombie2->vec.x = 250;
	GAME->zombie2->vec.y = 200;

	GAME->zombie3->sprite = sfSprite_create();
	zombie_tx = sfTexture_createFromFile("zombie7.png", NULL);
	sfSprite_setTexture(GAME->zombie3->sprite, zombie_tx, sfTrue);
	GAME->zombie3->skin = zombie_coordright();
	GAME->zombie3->clock = sfClock_create();
	GAME->zombie3->vec.x = 350;
	GAME->zombie3->vec.y = 200;

	GAME->zombie4->sprite = sfSprite_create();
	zombie_tx = sfTexture_createFromFile("zombie7.png", NULL);
	sfSprite_setTexture(GAME->zombie4->sprite, zombie_tx, sfTrue);
	GAME->zombie4->skin = zombie_coordright();
	GAME->zombie4->clock = sfClock_create();
	GAME->zombie4->vec.x = 150;
	GAME->zombie4->vec.y = 250;

	GAME->zombie5->sprite = sfSprite_create();
	zombie_tx = sfTexture_createFromFile("zombie7.png", NULL);
	sfSprite_setTexture(GAME->zombie5->sprite, zombie_tx, sfTrue);
	GAME->zombie5->skin = zombie_coordright();
	GAME->zombie5->clock = sfClock_create();
	GAME->zombie5->vec.x = 250;
	GAME->zombie5->vec.y = 150;
}