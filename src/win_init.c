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
	cub->north = load_tex(cub, cub->no); //creating of each texture struct
	cub->south = load_tex(cub, cub->so);
	cub->west = load_tex(cub, cub->we);
	cub->east = load_tex(cub, cub->ea);
}

//setting up the player angle according to the facing direction
void	get_facing_direction(t_player *player, char c)
{
	if (c == 'N')
		player->angle = PI / 2;
	else if (c == 'S')
		player->angle = -PI / 2;
	else if (c == 'W')
		player->angle = PI;
	else if (c == 'E')
		player->angle = 0;
}

//intialize the game, window and start rendering
void	start_game(t_game *cub)
{
	init_game(cub);
	init_player(&cub->player, cub);
	get_facing_direction(&cub->player, cub->player.direction);
	//draw the initiale window before player move
	draw_game(cub);
	mlx_hook(cub->win, 17, 0, cross_close_window, cub);
	//start loop with player movement
	mlx_hook(cub->win, 2, 1L<<0, move_player, cub);
	mlx_loop(cub->mlx);
}
