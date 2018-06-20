/*
** EPITECH PROJECT, 2017
** game_event.c
** File description:
**
*/

#include "my_rpg.h"

void change_pos(rpgcore_t *GAME)
{
	if (GAME->player->vec.x < 0) {
		GAME->mapnb = GAME->mapnb + 1;
		GAME->map_x = GAME->map_x - 1;
		GAME->player->vec.x = 900;
		update_map(GAME);
	}
	if (GAME->player->vec.x >= 1000) {
		GAME->mapnb = GAME->mapnb + 1;
		GAME->map_x = GAME->map_x + 1;
		GAME->player->vec.x = 0;
		update_map(GAME);
	}
	if (GAME->player->vec.y < 0) {
		GAME->mapnb = GAME->mapnb + 1;
		GAME->map_y = GAME->map_y + 1;
		GAME->player->vec.y = 600;
		update_map(GAME);
	}
	if (GAME->player->vec.y > 600) {
		GAME->mapnb = GAME->mapnb + 1;
		GAME->map_y = GAME->map_y - 1;
		GAME->player->vec.y = 0;
		update_map(GAME);
	}
}

int collision_map(rpgcore_t *GAME)
{
	if (GAME->player->vec.x < 0 || GAME->player->vec.x >= 1200 ||
	GAME->player->vec.y < 0 || GAME->player->vec.y >= 700) {
		my_putnbr(GAME->player->vec.x);
		my_putchar('\n');
		my_putnbr(GAME->player->vec.y);
		my_putchar('\n');
		change_pos(GAME);

	}
	can_player_left(GAME);
	can_player_right(GAME);
	can_player_top(GAME);
	can_player_bottom(GAME);
}

int colision(rpgcore_t *GAME)
{
	sfVector2f hitbox_p = sfSprite_getPosition(GAME->player->sprite);
	sfVector2f hitbox_ia = sfSprite_getPosition(GAME->ia->sprite);
	if (((hitbox_p.y <= (hitbox_ia.y + 20) &&
	hitbox_p.y >= (hitbox_ia.y - 20)) &&
	((hitbox_p.x <= hitbox_ia.x + 100) &&
	hitbox_p.x >= (hitbox_ia.x - 100)))) {
		if (((GAME->event.type == sfEvtKeyPressed) &&
		(GAME->event.key.code == sfKeyRight)) &&
		(hitbox_p.x < hitbox_ia.x)) {
			return (1);
		}
		if (((GAME->event.type == sfEvtKeyPressed) &&
		(GAME->event.key.code == sfKeyLeft)) &&
		(hitbox_p.x > (hitbox_ia.x))) {
			return (2);
		}
		if ((GAME->event.type == sfEvtKeyPressed) &&
		(GAME->event.key.code == sfKeyUp) &&
		hitbox_p.y < (hitbox_ia.y)) {
			return (4);
		}
		if (((GAME->event.type == sfEvtKeyPressed) &&
		(GAME->event.key.code == sfKeyDown))) {
			return (3);
		}
	}
	return (0);
}

void skin_tex(rpgcore_t *GAME)
{
	play_walksound(GAME);
	sfSprite_setTextureRect(GAME->player->sprite, GAME->player->skin);
	sfSprite_setPosition(GAME->player->sprite, GAME->player->vec);
}

void inventory(rpgcore_t *GAME)
{
	if (GAME->event.type == sfEvtKeyPressed &&
	(GAME->event.key.code == sfKeyI) &&
	GAME->player->inventory == 0) {
		GAME->player->inventory = 1;
	} else if (GAME->event.type == sfEvtKeyPressed &&
	(GAME->event.key.code == sfKeyI) &&
	GAME->player->inventory == 1) {
		GAME->player->inventory = 0;
	}
}

void map_out(player_t *player, rpgcore_t *GAME) {
	if (player->vec.y > 600) {
		GAME->map_coord.y = GAME->map_coord.y + 1;
		update_map(GAME);
	}
	if (player->vec.y < 0) {
		GAME->map_coord.y = GAME->map_coord.y - 1;
		update_map(GAME);
	}
	if (player->vec.x > 1100) {
		GAME->map_coord.x = GAME->map_coord.x + 1;
		update_map(GAME);
	}
	if (player->vec.x < 0) {
		GAME->map_coord.x = GAME->map_coord.x - 1;
		update_map(GAME);
	}
}

void pause_event(rpgcore_t *GAME)
{
	if (GAME->event.type == sfEvtKeyPressed &&
		(GAME->event.key.code == sfKeyEscape) &&
		GAME->pause== 0) {
		GAME->pause= 1;
	} else if (GAME->event.type == sfEvtKeyPressed &&
		(GAME->event.key.code == sfKeyEscape) &&
		GAME->pause== 1) {
		GAME->pause= 0;
	}
}

void player_move(player_t *player, rpgcore_t *GAME)
{
	sfVector2f player_pos = sfSprite_getPosition(GAME->player->sprite);
	sfFloatRect hit_b = sfSprite_getGlobalBounds (GAME->ia->sprite);

	map_out(player,GAME);
	if (GAME->event.type == sfEvtKeyPressed &&
	(GAME->event.key.code == sfKeyRight)) {
		if(GAME->player->can_right != 0)
			player->vec.x = player->vec.x + 100;
		player->skin = player_coordright();
		player->boul = 1;
		skin_tex(GAME);
		move_leg(GAME);
		collision_map(GAME);
	}
	if (GAME->event.type == sfEvtKeyPressed &&
	(GAME->event.key.code == sfKeyLeft)) {
		if(GAME->player->can_left != 0)
			player->vec.x = player->vec.x - 100;
		player->skin = player_coordleft();
		player->boul = 2;
		skin_tex(GAME);
		move_leg(GAME);
		collision_map(GAME);
	}
	if (GAME->event.type == sfEvtKeyPressed &&
	(GAME->event.key.code == sfKeyDown)) {
		if(GAME->player->can_bottom != 0)
			player->vec.y = player->vec.y + 100;
		player->skin = player_coorddown();
		player->boul = 3;
		skin_tex(GAME);
		move_leg(GAME);
		collision_map(GAME);
	}
	if (GAME->event.type == sfEvtKeyPressed &&
	(GAME->event.key.code == sfKeyUp)) {
		if(GAME->player->can_top != 0)
			player->vec.y = player->vec.y - 100;
		player->skin = player_coordup();
		player->boul = 4;
		skin_tex(GAME);
		move_leg(GAME);
		collision_map(GAME);
	}
}

void detect_evnt(rpgcore_t *GAME)
{
	if (GAME->event.type == sfEvtClosed)
		sfRenderWindow_close(GAME->window);
	power_event(GAME);
	inventory(GAME);
	pause_event(GAME);
	player_move(GAME->player, GAME);
}
