/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:26 by cofische          #+#    #+#             */
/*   Updated: 2024/12/09 10:54:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void clean_map(t_game *game)
{
	int i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
}

void clear_image(t_game *game)
{
	int y;
	int x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, 0, game);
	}
}

void destroy_img(t_game *game)
{
	if (game->north != NULL && game->north->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->north->img);
		free(game->north);
	}
	if (game->south != NULL && game->south->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->south->img);
		free(game->south);
	}
	if (game->west != NULL && game->west->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->west->img);
		free(game->west);
	}
	if (game->east != NULL && game->east->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->east->img);
		free(game->east);
	}
	if (game->door != NULL && game->door->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->door->img);
		free(game->door);
	}
}

void free_textures(t_game *game)
{
	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	if (game->ea)
		free(game->ea);
	if (game->dr)
		free(game->dr);
}

void free_game_struct(t_game *game)
{
	if (game->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
	if (game->win != NULL)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		if (game->mlx != NULL)
		{
			free(game->mlx);
			game->mlx = NULL;
		}
	}
}

void	clean_doors(t_game *game)
{
	int i;

	i = 0;
	while (game->d[i])
		free(game->d[i++]);
	free(game->d);
	game->d = NULL;	
}

void clean_game(t_game *game)
{
	if (game->line != NULL)
		free(game->line);
	if (game->map != NULL)
		clean_map(game);
	if (game->d != NULL)
		clean_doors(game);
	if (game->north || game->south \
		|| game->west || game->east)
		destroy_img(game);
	free_textures(game);
	free_game_struct(game);
	game = NULL;
}
