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

void	destroy_img(t_game *cub)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (cub->img.bpp[i] != NULL)
			free(cub->img.bpp[i]);
		if (cub->img.line_lenght[i] != NULL)
			free(cub->img.line_lenght[i]);
		if (cub->img.endian[i] != NULL)
			free(cub->img.endian[i]);
	}
	i = -1;
	while (++i < 4)
	{
		if (cub->img.tex[i] != NULL)
			mlx_destroy_image(cub->mlx, cub->img.tex[i]);
	}
}

void	free_textures(t_game *cub)
{
	destroy_img(cub);
	if (cub->mlx_img != NULL)
		mlx_destroy_image(cub->mlx, cub->mlx_img);
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
	if (cub->mlx_win != NULL)
	{
		mlx_destroy_window(cub->mlx, cub->mlx_win);
		cub->mlx_win = NULL;
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
