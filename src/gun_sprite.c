/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:02:39 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:14:41 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_gun_img(t_game *game)
{
	game->gun1 = safe_malloc(sizeof(t_tex), game);
	init_texture(game->gun1);
	game->gun1->img = mlx_xpm_file_to_image(game->mlx, \
		"../textures/gun/gun_1.xpm", &game->gun1->width, &game->gun1->height);
	game->gun1->data = mlx_get_data_addr(game->gun1->img, \
		&game->gun1->bpp, &game->gun1->size_line, &game->gun1->endian);
	game->gun2 = safe_malloc(sizeof(t_tex), game);
	init_texture(game->gun2);
	game->gun2->img = mlx_xpm_file_to_image(game->mlx, \
		"../textures/gun/gun_2.xpm", &game->gun2->width, &game->gun2->height);
	game->gun2->data = mlx_get_data_addr(game->gun2->img, \
		&game->gun2->bpp, &game->gun2->size_line, &game->gun2->endian);
}

int	get_pixel_image_gun(t_tex *temp, int x, int y)
{
	char	*pixel;

	x = x % temp->width;
	y = y % temp->height;
	if (x >= 0 && x < temp->width && y >= 0 && y < temp->height)
	{
		pixel = temp->data + (y * temp->size_line + x * (temp->bpp / 8));
		return (*(int *)pixel);
	}
	return (0);
}

void	update_gun_frame(t_game *game)
{
	struct timeval	current_time;
	double			elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - game->last_frame_time.tv_sec) + \
				(current_time.tv_usec - game->last_frame_time.tv_usec) / 1e6;
	game->accumulated_time += elapsed_time;
	if (game->accumulated_time >= 0.45)
	{
		game->gun_frame = 1;
		if (game->accumulated_time >= 0.9)
			game->accumulated_time = 0;
	}
	else
		game->gun_frame = 0;
	game->last_frame_time = current_time;
}

void	draw_gun(t_game *game)
{
	t_tex	*temp;
	int		x;
	int		y;

	if (game->player.shot)
	{
		temp = game->shot1;
		game->player.shot = false;
	}
	else if (game->gun_frame == 0)
		temp = game->gun1;
	else
		temp = game->gun2;
	y = -1;
	while (++y < temp->height)
	{
		x = -1;
		while (++x < temp->width)
		{
			game->gun_color = get_pixel_image_gun(temp, x, y);
			if ((unsigned int)game->gun_color != 0xFF000000)
				put_pixel(game->gun_x_start + x, game->gun_y_start + y, \
					game->gun_color, game);
		}
	}
}

	// gun_x_start = (WIDTH - temp->width) / 2;
	// gun_y_start = (HEIGHT - temp->height);