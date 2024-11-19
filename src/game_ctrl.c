#include "cub3d.h"

// int	game_mv(int	keycode, t_game *cub)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = cub->p_posx;
// 	new_y = cub->p_posy;
// 	if (keycode == KEY_W && cub->map[cub->p_posy - 1][cub->p_posx] != '1')
// 		new_y -= 1;
// 	else if (keycode == KEY_D && cub->map[cub->p_posy][cub->p_posx + 1] != '1')
// 		new_x += 1;
// 	else if (keycode == KEY_A && cub->map[cub->p_posy][cub->p_posx - 1] != '1')
// 		new_x -= 1;
// 	else if (keycode == KEY_S && cub->map[cub->p_posy + 1][cub->p_posx] != '1')
// 		new_y += 1;
// 	cub->map[cub->p_posy][cub->p_posx] = '0';
// 	cub->p_posx = new_x;
// 	cub->p_posy = new_y;
// 	raycasting(cub);
// 	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
// 	return (0);
// }

int	esc_close_window(int keycode, t_game *cub)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(cub->mlx);
		ft_exit(NULL, cub, 0);
	}
	return (0);
}

int	cross_close_window(t_game *cub)
{
	mlx_loop_end(cub->mlx);
	ft_exit(NULL, cub, 0);
	return (0);
}