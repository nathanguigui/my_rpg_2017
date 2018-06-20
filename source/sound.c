
#include "my_rpg.h"

void play_walksound(rpgcore_t *GAME)
{
	int max = 4;
	int min = 1;
	int rdm = rand() % max + min;
	char *path = "music/footstep";
	char nb[1];
	nb[0] = rdm + 48;
	nb[1] = 0;
	if ((int)(GAME->player->vec.y) % 12 == 0 ||
	(int)(GAME->player->vec.x) % 12 == 0)
		sfMusic_play(GAME->footstep);
}