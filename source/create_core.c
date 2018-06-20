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
void init_zombie(rpgcore_t *GAME)
{
	GAME->zombie1 = malloc(sizeof(player_t));
	GAME->zombie2 = malloc(sizeof(player_t));
	GAME->zombie3 = malloc(sizeof(player_t));
	GAME->zombie4 = malloc(sizeof(player_t));
	GAME->zombie5 = malloc(sizeof(player_t));
	init_zombie2(GAME);
}

void init_entity(rpgcore_t *GAME)
{
	init_zombie(GAME);
	GAME->player->sprite = sfSprite_create();
	sfTexture *player_tx = sfTexture_createFromFile("skin.png", NULL);
	GAME->power->sprite = sfSprite_create();
	GAME->power2->sprite = sfSprite_create();
	GAME->ia->sprite = sfSprite_create(); 
	GAME->mob->sprite = sfSprite_create();
	GAME->princess->sprite = sfSprite_create();
	sfTexture *power_tx = sfTexture_createFromFile("ressources/EFFECT/EFFECT.png", NULL);
	sfTexture *ia_tx = sfTexture_createFromFile("skin.png", NULL);
	sfTexture *mob_tx = sfTexture_createFromFile("mob.png", NULL);
	sfTexture *princess_tx = sfTexture_createFromFile("skin.png", NULL);
	sfSprite_setTexture(GAME->power->sprite, power_tx, sfTrue);
	sfSprite_setTexture(GAME->power2->sprite, power_tx, sfTrue);
	sfSprite_setTexture(GAME->princess->sprite, princess_tx, sfTrue);
	sfSprite_setTexture(GAME->player->sprite, player_tx, sfTrue);
	sfSprite_setTexture(GAME->ia->sprite, ia_tx, sfTrue);
	sfSprite_setTexture(GAME->mob->sprite, mob_tx, sfTrue);
	sfSprite_setTextureRect(GAME->mob->sprite, GAME->mob->skin);
	sfSprite_setPosition(GAME->mob->sprite, GAME->mob->vec);
	GAME->princess->skin = princess_coordleft();
	GAME->mob->clock = sfClock_create();
	GAME->power->clock = sfClock_create();
	GAME->player->clock = sfClock_create();
	GAME->ia->clock = sfClock_create();
	GAME->princess->clock = sfClock_create();
	GAME->power2->clock = sfClock_create();
}

void init_potion1(rpgcore_t *GAME)
{
	GAME->potion1->vec.x = 470;
	GAME->potion2->vec.x = 560;
	GAME->potion3->vec.x = 650;
	GAME->potion1->vec.y = 500;
	GAME->potion2->vec.y = 500;
	GAME->potion3->vec.y = 500;
}

void init_potion2(rpgcore_t *GAME)
{
	sfVector2f pos;
	pos.x = 2;
	pos.y = 2;

	init_potion1(GAME);
	GAME->potion1->skin = potion1_coord();
	GAME->potion2->skin = potion1_coord();
	GAME->potion3->skin = potion1_coord();
	GAME->potion1->sprite = sfSprite_create();
	GAME->potion2->sprite = sfSprite_create();
	GAME->potion3->sprite = sfSprite_create();
	GAME->potion1->texture = sfTexture_createFromFile("sprite_potion.png", NULL);
	GAME->potion2->texture = sfTexture_createFromFile("sprite_potion.png", NULL);
	GAME->potion3->texture = sfTexture_createFromFile("sprite_potion.png", NULL);
	sfSprite_setTexture(GAME->potion1->sprite, GAME->potion1->texture, sfTrue);
	sfSprite_setTexture(GAME->potion2->sprite, GAME->potion2->texture, sfTrue);
	sfSprite_setTexture(GAME->potion3->sprite, GAME->potion3->texture, sfTrue);
	sfSprite_setPosition(GAME->potion1->sprite, GAME->potion1->vec);
	sfSprite_setPosition(GAME->potion2->sprite, GAME->potion2->vec);
	sfSprite_setPosition(GAME->potion3->sprite, GAME->potion3->vec);
	sfSprite_setTextureRect(GAME->potion1->sprite, GAME->potion1->skin);
	sfSprite_setTextureRect(GAME->potion2->sprite, GAME->potion2->skin);
	sfSprite_setTextureRect(GAME->potion3->sprite, GAME->potion3->skin);
	sfSprite_scale(GAME->potion1->sprite, pos);
	sfSprite_scale(GAME->potion2->sprite, pos);
	sfSprite_scale(GAME->potion3->sprite, pos);
}


void init_life(rpgcore_t *GAME)
{
	GAME->font = sfFont_createFromFile("ressources/font.ttf");
	GAME->player->ltext = sfText_create();
	GAME->mob->ltext = sfText_create();
	sfText_setFont(GAME->player->ltext, GAME->font);
	sfText_setCharacterSize(GAME->player->ltext, 33);
	sfText_setPosition(GAME->player->ltext, GAME->player->vec);
	sfText_setFont(GAME->mob->ltext, GAME->font);
	sfText_setCharacterSize(GAME->mob->ltext, 33);
	sfText_setPosition(GAME->mob->ltext, GAME->mob->vec);

}

void init_sound(rpgcore_t *GAME)
{
	GAME->footstep = sfMusic_createFromFile("music/footstep00");
}

rpgcore_t *create_core(void)
{
	char *title = "My RPG solo";
	
	rpgcore_t *GAME = malloc(sizeof(rpgcore_t));
	GAME->menu = 1;
	GAME->player = malloc(sizeof(player_t));
	GAME->potion1 = malloc(sizeof(potion_t));
	GAME->potion2 = malloc(sizeof(potion_t));
	GAME->potion3 = malloc(sizeof(potion_t));
	GAME->ia = malloc(sizeof(player_t));
	GAME->mob = malloc(sizeof(player_t));
	GAME->power = malloc(sizeof(power_t));
	GAME->power2 = malloc(sizeof(power_t));
	GAME->princess = malloc(sizeof(player_t));
	sfVideoMode mode = {1100, 600, 32};
	GAME->draws = sfRenderWindow_drawSprite;
	GAME->drawr = sfRenderWindow_drawRectangleShape;
	GAME->player->life = 99;
	GAME->player->vec.y = 500;
	GAME->player->vec.x = 500;
	GAME->ia->vec.x = 783;
	GAME->ia->vec.y = 500;
	GAME->mob->vec.x = 200;
	GAME->mob->vec.y = 200;
	GAME->princess->vec.x = 500;
	GAME->princess->vec.y = 200;
	GAME->power->save = 0;
	GAME->power2->save = 0;
	GAME->mapnb = 1;
	GAME->mob->life = 10;
	GAME->map_coord.x = 0;
	GAME->map_coord.y = 0;
	int map_x = 0;
	int map_y = 0;
	GAME->pause = 0;
	GAME->world = "ARVANA";
	GAME->window = sfRenderWindow_create(mode, title, sfClose , NULL);
	init_entity(GAME);
	init_potion2(GAME);
	GAME->player->can_left = 1;
	GAME->player->can_right = 1;
	GAME->player->can_top = 1;
	GAME->player->can_bottom = 1;
	init_life(GAME);
	init_sound(GAME);
	return (GAME);
}
