#include "cub3d.h"

void	clean_map(t_game *cub)
{
	int	i;

	i = 0;
	while (cub->map[i] != NULL)
		free(cub->map[i++]);
	free(cub->map);
	cub->map = NULL;
}

void	clear_image(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, 0, game);
	}
}

void	destroy_img(t_game *cub)
{
	if (cub->north->img != NULL)
		mlx_destroy_image(cub->mlx, cub->north->img);
	if (cub->north != NULL)
		free(cub->north);
	if (cub->south->img != NULL)
		mlx_destroy_image(cub->mlx, cub->south->img);
	if (cub->south != NULL)
		free(cub->south);
	if (cub->west->img != NULL)
		mlx_destroy_image(cub->mlx, cub->west->img);
	if (cub->west != NULL)
		free(cub->west);
	if (cub->east->img != NULL)
		mlx_destroy_image(cub->mlx, cub->east->img);
	if (cub->east != NULL)
		free(cub->east);
}

void	free_textures(t_game *cub)
{
	destroy_img(cub);
	if (cub->img != NULL)
		mlx_destroy_image(cub->mlx, cub->img);
	if (cub->no)
		free(cub->no);
	if (cub->so)
		free(cub->so);
	if (cub->we)
		free(cub->we);
	if (cub->ea)
		free(cub->ea);
}

void	free_game_struct(t_game *cub)
{
	if (cub->win != NULL)
	{
		mlx_destroy_window(cub->mlx, cub->win);
		cub->win = NULL;
	}
	if (cub->mlx != NULL)
	{
		mlx_destroy_display(cub->mlx);
		if (cub->mlx != NULL)
		{
			free(cub->mlx);
			cub->mlx = NULL;
		}
	}
}

void	clean_game(t_game *cub)
{
	if (cub->map != NULL)
		clean_map(cub);
	free_textures(cub);
	free_game_struct(cub);
	cub = NULL;
}
