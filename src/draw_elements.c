/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:03:06 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 12:04:23 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	game->data = mlx_get_data_addr(game->img, &game->bpp, \
		&game->size_line, &game->endian);
	y = HEIGHT / 2 - 1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, game->floor_color, game);
	}
}

void	draw_ceiling(t_game *game)
{
	int	y;
	int	x;

	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, \
		&game->endian);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, game->ceiling_color, game);
	}
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int		color;
	float	pos;

	ray->step = BLOCK_SIZE / ray->height_wall;
	ray->start_wall = (HEIGHT - ray->height_wall) / 2;
	ray->end_wall = ray->start_wall + ray->height_wall;
	if (ray->height_wall > HEIGHT)
		ray->start_wall %= HEIGHT;
	pos = (ray->start_wall - HEIGHT / 2 + ray->height_wall / 2) * ray->step;
	while (ray->start_wall < ray->end_wall)
	{
		ray->tex_y = (int)pos % BLOCK_SIZE;
		color = get_pixel_image(game, &game->ray);
		put_pixel(x, ray->start_wall, color, game);
		pos += ray->step;
		ray->start_wall++;
	}
}
