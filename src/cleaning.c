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

void	free_textures(t_game *cub)
{
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
