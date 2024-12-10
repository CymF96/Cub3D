/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:49 by cofische          #+#    #+#             */
/*   Updated: 2024/12/04 11:10:39 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

//set rgb to a color by combining the bits
int	set_up_color(int *rgb)
{
	int	color;
	int	r;
	int g;
	int b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	color = (r << 16 | g << 8 | b);
	return (color);
}

//create a texture structure per facing direction to be easily accessible during rendering
t_tex	*load_tex(t_game *game, char *texture_file)
{
	t_tex	*t_wall;

	if (!texture_file)
		ft_exit("Texture file is incorrect", game, 1);
	t_wall = NULL;
	t_wall = safe_malloc(sizeof(t_tex), game);
	init_texture(t_wall);
	t_wall->img = mlx_xpm_file_to_image(game->mlx, texture_file, &t_wall->width, &t_wall->height);
	t_wall->data = mlx_get_data_addr(t_wall->img, &t_wall->bpp, &t_wall->size_line, &t_wall->endian);
	return (t_wall);
}