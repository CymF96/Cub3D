/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:15:07 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:13:54 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH - 1 || y >= HEIGHT - 1 || x < 0 || y < 0)
		return ;
	game->data = mlx_get_data_addr(game->img, &game->bpp, \
		&game->size_line, &game->endian);
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
	else if (ray->tex_id == 1)
		temp = game->south;
	else if (ray->tex_id == 2)
		temp = game->west;
	else if (ray->tex_id == 3)
		temp = game->east;
	else
		return (0);
	ray->tex_x = ray->tex_x % temp->width;
	ray->tex_y = ray->tex_y % temp->height;
	if (ray->tex_x >= 0 && ray->tex_x < temp->width && ray->tex_y >= 0 \
		&& ray->tex_y < temp->height)
	{
		pixel = temp->data + (ray->tex_y * temp->size_line + \
			ray->tex_x * (temp->bpp / 8));
		return (*(int *)pixel);
	}
	return (0);
}

int	get_pixel_image_door(t_game *game, t_ray *ray)
{
	char	*pixel;
	t_tex	*temp;

	temp = game->door;
	ray->tex_x = ray->tex_x % temp->width;
	ray->tex_y = ray->tex_y % temp->height;
	if (ray->tex_x >= 0 && ray->tex_x < temp->width && \
		ray->tex_y >= 0 && ray->tex_y < temp->height)
	{
		pixel = temp->data + (ray->tex_y * temp->size_line + \
			ray->tex_x * (temp->bpp / 8));
		return (*(int *)pixel);
	}
	return (0);
}
