#include "cub3d.h"

void	generate_window(t_game *cub)
{
	cub->win_w = 1200;
	cub->win_h = 800;
	cub->mlx_win = mlx_new_window(cub->mlx, cub->win_w,
			cub->win_h, "Cub3D");
	if (cub->mlx_win == NULL)
		ft_exit("mlx_window failed", cub, 1);
}


void	start_game(t_game *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		ft_exit("mlx_init failed", cub, 1);
	generate_window(cub);
	// draw_map(game);
	load_textures(cub);
	set_up_color(cub);
	mlx_hook(cub->mlx_win, 17, 0, cross_close_window, cub);
	mlx_key_hook(cub->mlx_win, esc_close_window, cub);
	raycasting(cub);
	// mlx_key_hook(cub->mlx_win, game_mv, cub);
	mlx_loop(cub->mlx);
}
