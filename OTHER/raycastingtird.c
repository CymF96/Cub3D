/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:26:58 by cofische          #+#    #+#             */
/*   Updated: 2024/11/27 10:35:59 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray_direction(t_game *cub, int x)
{
	cub->ray.cam_x = 2 * x / (double)WIN_W - 1;
	cub->ray.ray_dir_x = cub->ray.dir_x + cub->ray.plane_x * cub->ray.cam_x;
	cub->ray.ray_dir_y = cub->ray.dir_y + cub->ray.plane_y * cub->ray.cam_x;
}

void	get_side_distance(t_game *cub)
{
	if (cub->ray.ray_dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->ray.pos_x - cub->ray.map_x) * cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.side_dist_x = (cub->ray.map_x + 1.0 - cub->ray.pos_x) * cub->ray.delta_dist_x;
	}
	if (cub->ray.ray_dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->ray.pos_y - cub->ray.map_y) * cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.side_dist_y = (cub->ray.map_y + 1.0 - cub->ray.pos_y) * cub->ray.delta_dist_y;
	}
}

void	get_delta_distance(t_game *cub)
{ 
	if (cub->ray.ray_dir_x == 0)
		cub->ray.delta_dist_x = FLT_MAX;
	else
		cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	if (cub->ray.ray_dir_y == 0)
		cub->ray.delta_dist_y = FLT_MAX;
	else
		cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
}

void	wall_distance(t_game *cub)
{
	while (cub->map[cub->ray.map_y][cub->ray.map_x] != '1')
	{
		if (cub->ray.side_dist_x < cub->ray.side_dist_y)
		{
			cub->ray.map_x += cub->ray.step_x;
			cub->ray.side_dist_x += cub->ray.delta_dist_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.map_y += cub->ray.step_y;
			cub->ray.side_dist_y += cub->ray.delta_dist_y;
			cub->ray.side = 1;
		}
	}
	if (cub->ray.side == 0)
		cub->ray.wall_dist = cub->ray.side_dist_x - cub->ray.delta_dist_x;
	else
		cub->ray.wall_dist = cub->ray.side_dist_y - cub->ray.delta_dist_y;
}

void	draw_wall2(t_game *cub)
{
	cub->ray.draw_s = -cub->ray.line_h / 2 + WIN_H / 2;
	if (cub->ray.draw_s < 0)
		cub->ray.draw_s = 0;
	cub->ray.draw_e = cub->ray.line_h / 2 + WIN_H / 2;
	if (cub->ray.draw_e >= WIN_H)
		cub->ray.draw_e = WIN_H - 1;
}

void	get_textures(t_game *cub)
{
	if (cub->ray.side == 0)
		cub->ray.wall_x = cub->ray.pos_y + cub->ray.wall_dist * cub->ray.ray_dir_y;
	else
		cub->ray.wall_x = cub->ray.pos_x + cub->ray.wall_dist * cub->ray.ray_dir_x;
	cub->ray.wall_x -= floor(cub->ray.wall_x);
	if ((cub->ray.side == 0 && cub->ray.ray_dir_x < 0) \
		|| (cub->ray.side == 1 && cub->ray.ray_dir_y > 0))
    cub->img.tex_x = cub->img.tex_size - cub->img.tex_x - 1;
	if (cub->ray.side == 0) 
	{
		if (cub->ray.ray_dir_x > 0)
			cub->img.tex_i = 0;
		else
			cub->img.tex_i = 1;
	}
	else
	{
		if (cub->ray.ray_dir_y > 0)
			cub->img.tex_i = 2;
		else
			cub->img.tex_i = 3;
	}
}


void	render_textures(t_game *cub, int x)
{
	int	y;
	
	y = -1;
	cub->img.tex_x = (int)cub->ray.wall_x * cub->img.tex_size % cub->img.tex_size;
	while (++y < WIN_H)
	{
		if (y < cub->ray.draw_s)
			cub->img_buf[y][x] = cub->img.c_color;
		else if (y > cub->ray.draw_e)
			cub->img_buf[y][x] = cub->img.f_color;
		else
		{
   			cub->img.tex_y = (int)((y - cub->ray.draw_s) * cub->img.tex_size / cub->ray.line_h);
			cub->img.color = cub->img.tex_add[cub->img.tex_i][cub->img.tex_y * cub->img.tex_size + cub->img.tex_x];
			cub->img_buf[y][x] = cub->img.color;
		}
	}
	
}

void	debug_print(t_game *cub, int x)
{
	printf("x: %d, cub->win_h = %.2f, cub->win_w = %.2f\ncub->ray.cam_x = %.2f\ncub->ray.cam_y = %.2f\ncub->ray.ray_dir_x = %.2f\n \
	cub->ray.ray_dir_y = %.2f\ncub->ray.pos_x = %.2f\ncub->ray.pos_y = %.2f\ncub->ray.map_x = %.2f\ncub->ray.map_y = %.2f\n \
	cub->ray.delta_dist_x = %.2f\ncub->ray.delta_dist_y = %.2f\ncub->ray.step_x = %.2f\ncub->ray.step_y = %.2f\n \
	cub->ray.side_dist_x = %.2f\ncub->ray.side_dist_y = %.2f\ncub->ray.wall_dist = %.2f\ncub->ray.wall_x = %.2f\n \
	cub->ray.line_h = %.2f\ncub->ray.draw_s = %.2f\ncub->ray.draw_e = %.2f\ncub->ray.side = %.2f\n", \
	x, (double)cub->win_h, (double)cub->win_w, (double)cub->ray.cam_x, (double)cub->ray.cam_y, (double)cub->ray.ray_dir_x, \
	(double)cub->ray.ray_dir_y, (double)cub->ray.pos_x, (double)cub->ray.pos_y, (double)cub->ray.map_x, (double)cub->ray.map_y, \
	(double)cub->ray.delta_dist_x, (double)cub->ray.delta_dist_y, (double)cub->ray.step_x, (double)cub->ray.step_y, \
	(double)cub->ray.side_dist_x, (double)cub->ray.side_dist_y, (double)cub->ray.wall_dist, (double)cub->ray.wall_x, \
	(double)cub->ray.line_h, (double)cub->ray.draw_s, (double)cub->ray.draw_e, (double)cub->ray.side);

	printf("line_h: %d\n", cub->ray.line_h);

}

void	buffer_to_address(t_game *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			cub->img_add[y * WIN_W + x] = cub->img_buf[y][x];
	}
}

void	raycasting(t_game *cub)
{
	int	x;

	x = 0;
	cub->ray.map_x = (int)cub->ray.pos_x; 
	cub->ray.map_y = (int)cub->ray.pos_y;
	while (x < WIN_W)
	{
		get_ray_direction(cub, x);
		get_side_distance(cub);
		get_delta_distance(cub);
		wall_distance(cub);
		cub->ray.line_h = (int)WIN_H / cub->ray.wall_dist;
		draw_wall(cub);
		get_textures(cub);
		render_textures(cub, x);
		x++;
	}
	buffer_to_address(cub);
	debug_print(cub, x);
	printf("\n --------------------------------------------- \n");
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
}

