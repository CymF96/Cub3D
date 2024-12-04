/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pixel_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:15:07 by cofische          #+#    #+#             */
/*   Updated: 2024/12/04 11:10:30 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
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

	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel(x, y, game->ceiling_color, game);
	}
}

//setting the 1st angle ray to start drawing from point A to Z on scope of 60 FOV and drawing the wall line on the total screen
void	draw_wall(t_game *game)
{
	int			x;
	float		start_angle;
	float		ray_angle;

	ray_angle = 0;
	start_angle = game->player.angle - (game->ray.fov / 2);
	x = -1;
	while (++x < WIDTH)
	{
		ray_angle = start_angle + (game->ray.fov / WIDTH) * x;
		draw_line(&game->player, game, ray_angle, x);
	}
	
	/*DEBUGGING PRINTING THE PLAYER POSITION AS GREEN SQUARE ON 2D MAP*/
	// game->ray.ray_x = game->player.x;
	// game->ray.ray_y = game->player.y;
	// game->ray.cos_a = cos(game->player.angle);
	// game->ray.sin_a = sin(game->player.angle);

	// while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game))
	// {
	// 	put_pixel(game->ray.ray_x, game->ray.ray_y, 0xFF0000, game);
	// 	game->ray.ray_x += game->ray.cos_a;
	// 	game->ray.ray_y += game->ray.sin_a;
	// }
	/*DEBUGGING PRINTING THE PLAYER POSITION AS GREEN SQUARE ON 2D MAP*/
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	int index;

	if (x >= WIDTH - 1 || y >= HEIGHT - 1 || x < 0 || y < 0)
		return ;
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

int	get_pixel_image(t_game *game, t_ray *ray)
{
	char	*pixel;
	t_tex	*temp;

	if (ray->tex_id == 0)
		temp = game->north;
	else if (ray->tex_id == 1) // this texture is printed in reverse -- can only be seen in small.cub map --
		temp = game->south;
	else if (ray->tex_id == 2) // PROBLEM -- THis west texture is never appearing as west is getting id: 1
		temp = game->west;
	else if (ray->tex_id == 3)
		temp = game->east;
	else
		return (0);
	ray->tex_x = ray->tex_x % temp->width;
	ray->tex_y = ray->tex_y % temp->height;
	if (ray->tex_x >= 0 && ray->tex_x < temp->width && ray->tex_y >= 0 && ray->tex_y < temp->height)
	{
		pixel = temp->data + (ray->tex_y * temp->size_line + ray->tex_x * (temp->bpp / 8));
		return (*(int *)pixel);
	}
	return (0);
}
