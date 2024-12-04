#include "cub3d.h"

void	mouse_move(t_game *game)
{
	int 		current_mouse_x; 
	int			current_mouse_y;

	mlx_mouse_get_pos(game->mlx, game->win, &current_mouse_x, &current_mouse_y);
	game->mouse_delta_x = current_mouse_x - game->last_mouse_x;
	game->player.angle += game->mouse_delta_x * MOUSE_SEN;
	if (game->player.angle < 0)
		game->player.angle += 2 * PI;
	else if (game->player.angle > 2 * PI)
		game->player.angle -= 2 * PI;
	game->last_mouse_x = current_mouse_x;
	mlx_mouse_hide(game->mlx, game->win);
}
