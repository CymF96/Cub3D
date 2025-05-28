/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:21:27 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:14:49 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_game *game, t_ray *r, int x)
{
	r->step = BLOCK_SIZE / r->height_wall;
	r->start_wall = (HEIGHT - r->height_wall) / 2;
	r->end_wall = r->start_wall + r->height_wall;
	if (r->height_wall > HEIGHT)
		r->start_wall %= HEIGHT;
	r->pos = (r->start_wall - HEIGHT / 2 + r->height_wall / 2) * r->step;
	while (r->start_wall < r->end_wall)
	{
		r->map_x = (int)(r->ray_x / BLOCK_SIZE);
		r->map_y = (int)(r->ray_y / BLOCK_SIZE);
		r->tex_y = (int)r->pos % BLOCK_SIZE;
		if (game->map[r->map_y][r->map_x] == 'D' \
			&& !game->d[game->d_index]->open)
		{
			r->color = get_pixel_image_door(game, &game->ray);
			put_pixel(x, r->start_wall, r->color, game);
		}
		else
		{
			r->color = get_pixel_image(game, &game->ray);
			put_pixel(x, r->start_wall, r->color, game);
		}
		r->pos += r->step;
		r->start_wall++;
	}
}

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

	game->data = mlx_get_data_addr(game->img, &game->bpp, \
		&game->size_line, &game->endian);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, game->ceiling_color, game);
	}
}
