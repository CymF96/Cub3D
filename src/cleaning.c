/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:26 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 11:23:14 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
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

void	destroy_img(t_game *game)
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
}

void	free_textures(t_game *game)
{
	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	if (game->ea)
		free(game->ea);
}

void	free_game_struct(t_game *game)
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
