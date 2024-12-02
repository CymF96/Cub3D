#include "cub3d.h"

void center_mouse(t_game *game)
{
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
}

int mouse_move(int x, int y, t_player *player)
{
	int center_x;
	float dx;
	float sensitivity;
	(void)y;

	center_x = WIDTH / 2;
	dx = x - center_x;
	sensitivity = 0.003;
	player->angle += dx * sensitivity;
	if (player->angle < 0)
		player->angle += 2 * PI;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	center_mouse(player->game);
	return (0);
}
