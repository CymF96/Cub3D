/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cleaning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:26 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 16:05:12 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

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

void	destroy_img_bis(t_game *game)
{
	if (game->door != NULL && game->door->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->door->img);
		free(game->door);
	}
	if (game->gun1 != NULL && game->gun1->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->gun1->img);
		free(game->gun1);
	}
	if (game->gun2 != NULL && game->gun2->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->gun2->img);
		free(game->gun2);
	}
	if (game->shot1 != NULL && game->shot1->img != NULL)
	{
		mlx_destroy_image(game->mlx, game->shot1->img);
		free(game->shot1);
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
	destroy_img_bis(game);
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
