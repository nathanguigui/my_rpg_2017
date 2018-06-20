/*
** EPITECH PROJECT, 2017
** my_rpg.h
** File description:
**
*/

#ifndef MY_RPG_
#define MY_RPG_

#include "my.h"
#include "get_next_line.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef struct save_s {
	sfVector2i player_pos;
} save_t;

typedef struct power_s {
	sfIntRect skin;
	sfVector2f vec;
	sfSprite *sprite;
	sfClock *clock;
	int save;
	int boul;
	char dir;
	sfTime time;
} power_t;

typedef struct player_s {
	sfIntRect skin;
	sfVector2f vec;
	sfSprite *sprite;
	sfClock *clock;
	sfTime time;
	sfText *ltext;
	int life;
	int exp;
	int boul;
	int inventory;
	int can_left;
	int can_right;
	int can_top;
	int can_bottom;
} player_t;

typedef struct potion_s {
	sfIntRect skin;
	sfVector2f vec;
	sfSprite *sprite;
	sfTexture *texture;
	int boul;
} potion_t;

typedef struct rpgcore_s {
	sfRenderWindow *window;
	sfEvent event;
	int pause;
	player_t *player;
	player_t *ia;
	player_t *mob;
	power_t *power;
	power_t *power2;
	potion_t *potion1;
	potion_t *potion2;
	potion_t *potion3;
	player_t *princess;
	player_t *zombie1;
	player_t *zombie2;
	player_t *zombie3;
	player_t *zombie4;
	player_t *zombie5;
	int map_x;
	int map_y;
	char map[6][11];
	sfRectangleShape *rmap[6][11];
	int menu;
	int mapnb;
	void (*draws)(sfRenderWindow*, sfSprite*, sfRenderStates*);
	void (*drawr)(sfRenderWindow*, sfRectangleShape*, sfRenderStates*);
	sfRectangleShape *rmenu[3];
	sfRectangleShape *rpause[3];
	sfVector2i map_coord;
	char *world;
	sfFont *font;
	sfMusic *footstep;
	sfRectangleShape *quest;
	sfText* text;
	sfText* text2;
	sfText* quest_str;
} rpgcore_t;

typedef struct bouton_s {
	int right;
	int left;
	int up;
	int down;
	int clic; //
} bouton_t;

void main_menu(rpgcore_t *GAME);
rpgcore_t *create_core(void);
int is_collision(sfVector2i pos, sfFloatRect hit_b);
int is_collision2(sfVector2f pos, sfFloatRect hit_b);
void detect_evnt(rpgcore_t *GAME);
int colision_power(rpgcore_t *GAME);
sfIntRect player_coordright(void);
sfIntRect player_coordup(void);
sfIntRect player_coorddown(void);
sfIntRect player_coordleft(void);
void power_clock(rpgcore_t *GAME);
void skin_power(rpgcore_t *GAME);
void power_mvm(rpgcore_t *GAME);
void power_event(rpgcore_t *GAME);
sfIntRect power_coordright(void);
sfIntRect power_coordleft(void);
sfIntRect power_coordup(void);
sfIntRect power_coorddown(void);
sfIntRect mob_coordright(void);
sfIntRect mob_coordleft(void);
sfIntRect mob_coordup(void);
sfIntRect mob_coorddown(void);
sfIntRect zombie_coordright(void);
void zombie_advance(player_t *mob);
void init_zombie2(rpgcore_t *GAME);
void move_zombie(player_t *mob);
void move_legzombie(player_t *mob);
void move_legmob(player_t *mob);
void move_mob(player_t *mob);
void move_legia(rpgcore_t *GAME);
void move_leg(rpgcore_t *GAME);
void power_magic(rpgcore_t *GAME);
void skin_power(rpgcore_t *GAME);
void move_power_clock(rpgcore_t *GAME);
void move_power(rpgcore_t *GAME);
sfRectangleShape *player_slot(void);
sfRectangleShape *stat_bar(int nbr);
void open_inventory(rpgcore_t *GAME);
void file_to_map(rpgcore_t *GAME, char *name);
void create_spritemap(int x, int y, rpgcore_t *GAME, char content);
//void detect_evnt(rpgcore_t *GAME);
sfIntRect princess_coordleft(void);
sfIntRect potion1_coord(void);
sfIntRect princess_coordleft(void);
sfIntRect princess_coordright(void);
sfIntRect princess_coordup(void);
sfIntRect princess_coorddown(void);


#endif
