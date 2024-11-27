#include "cub3d.h"

void	init_game(t_game *cub)
{
	cub->mlx = mlx_init();
	if (cub->mlx == NULL)
		ft_exit("mlx_init failed", cub, 1);
	cub->win = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "Cub3D");
	if (cub->win == NULL)
		ft_exit("mlx_win failed", cub, 1);
	cub->floor_color = set_up_color(cub->f);
	cub->ceiling_color = set_up_color(cub->c);
	cub->north = load_tex(cub, cub->no);
	cub->south = load_tex(cub, cub->so);
	cub->west = load_tex(cub, cub->we);
	cub->east = load_tex(cub, cub->ea);
}

void	get_facing_direction(t_player *player, char c)
{
	if (c == 'N')
		player->angle = 3 * PI / 2;
	else if (c == 'S')
		player->angle = PI / 2;
	else if (c == 'W')
		player->angle = PI;
	else if (c == 'E')
		player->angle = 0;
	player->angle_direction = player->angle * (180 / PI);
	while (player->angle_direction >= 360)
		player->angle_direction -= 360;
}


void	start_game(t_game *cub)
{
	init_game(cub);
	init_player(&cub->player);
	get_facing_direction(&cub->player, cub->player.direction);
	mlx_hook(cub->win, 2, 1L<<0, key_press, cub);
	mlx_hook(cub->win, 3, 1L<<1, key_release, &cub->player);
	mlx_loop_hook(cub->mlx, draw_game, cub);
	mlx_hook(cub->win, 17, 0, cross_close_window, NULL);
	mlx_loop(cub->mlx);
}
