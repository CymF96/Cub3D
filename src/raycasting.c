/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:26:58 by cofische          #+#    #+#             */
/*   Updated: 2024/11/21 17:46:24 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ray_init(t_game *cub)
{
    cub->win_h = WIN_H;
	cub->win_w = WIN_W;
	cub->ray.cam_x = 0;
	cub->ray.cam_y = 0;
	cub->ray.ray_dir_x = 0;
	cub->ray.ray_dir_y = 0;
	cub->ray.map_x = (int)cub->ray.pos_x; 
	cub->ray.map_y = (int)cub->ray.pos_y; 
	cub->ray.delta_dist_x = 0;
	cub->ray.delta_dist_y = 0;
	cub->ray.step_x = 0;
	cub->ray.step_y = 0;
	cub->ray.side_dist_x = 0;
	cub->ray.side_dist_y = 0;
	cub->ray.wall_dist = 0;
	cub->ray.wall_x = 0;
	cub->ray.line_h = 0;
	cub->ray.draw_s = 0;
	cub->ray.draw_e = 0;
	cub->ray.side = 0;
}

void	facing_dir2(t_game *cub)
{
	if (cub->p_dir == 'W')
	{
		cub->ray.dir_x = -1;
		cub->ray.dir_y = 0;
		cub->ray.plane_x = 0;
		cub->ray.plane_y = -0.66;
	}
	else if (cub->p_dir == 'E')
	{
		cub->ray.dir_x = 1;
		cub->ray.dir_y = 0;
		cub->ray.plane_x = 0;
		cub->ray.plane_y = 0.66;
	}
	else
		ft_exit("Unknown player facing direction", cub, 1);
}

void	facing_dir(t_game *cub)
{
	if (cub->p_dir == 'N')
	{
		cub->ray.dir_x = 0;
		cub->ray.dir_y = -1;
		cub->ray.plane_x = 0.66;
		cub->ray.plane_y = 0;
	}
	else if (cub->p_dir == 'S')
	{
		cub->ray.dir_x = 0;
		cub->ray.dir_y = 1;
		cub->ray.plane_x = -0.66;
		cub->ray.plane_y = 0;
	}
	else
		facing_dir2(cub);
}

void	zero_value_check(t_game *cub)
{
	if (cub->ray.ray_dir_x == 0)
    	cub->ray.delta_dist_x = FLT_MAX; // or another appropriate value to handle the edge case
	else 
    	cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	if (cub->ray.ray_dir_y == 0)
    	cub->ray.delta_dist_y = FLT_MAX; // similarly handle for ray_dir_y
	else
    	cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
}

void	get_delta_distance(t_game *cub, int x)
{
	cub->ray.cam_x = 2 * x / (double)WIN_W - 1;
	cub->ray.ray_dir_x = cub->ray.dir_x + cub->ray.plane_x * cub->ray.cam_x;
	cub->ray.ray_dir_y = cub->ray.dir_y + cub->ray.plane_y * cub->ray.cam_x;
	// zero_value_check(cub);
	if (fabs(cub->ray.ray_dir_x) > EPSILON)
    	cub->ray.delta_dist_x = fabs(1 / cub->ray.ray_dir_x);
	else
    	cub->ray.delta_dist_x = FLT_MAX; // Use FLT_MAX for finite "practically infinite"
	if (fabs(cub->ray.ray_dir_y) > EPSILON)
    	cub->ray.delta_dist_y = fabs(1 / cub->ray.ray_dir_y);
	else
    	cub->ray.delta_dist_y = FLT_MAX;
	// printf("x: %d, delta_dist_x: %.2f, delta_dist_y: %.2f, ray_dir_x: %.2f, ray_dir_y: %.2f\n", x, cub->ray.delta_dist_x, cub->ray.delta_dist_y, cub->ray.ray_dir_x, cub->ray.ray_dir_y);
	if (cub->ray.ray_dir_x == 0)
	{
		cub->ray.step_x = 0;
    	cub->ray.side_dist_x = FLT_MAX;
	}
	else if (cub->ray.ray_dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.side_dist_x = (cub->ray.pos_x - cub->ray.map_x) * cub->ray.delta_dist_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.side_dist_x = (cub->ray.map_x + 1.0 - cub->ray.pos_x) * cub->ray.delta_dist_x;
	}
	if (cub->ray.ray_dir_y == 0)
	{
		cub->ray.step_y = 0;
    	cub->ray.side_dist_y = FLT_MAX;
	}
	else if (cub->ray.ray_dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.side_dist_y = (cub->ray.pos_y - cub->ray.map_y) * cub->ray.delta_dist_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.side_dist_y = (cub->ray.map_y + 1.0 - cub->ray.pos_y) * cub->ray.delta_dist_y;
	}
	// printf("x: %d, pos_x: %.2f, pos_y: %.2f, map_x: %d, map_y: %d,step_x: %.d, step_y: %d, side_dist_x: %.2f, side_dis_y: %.2f\n", x, cub->ray.pos_x, cub->ray.pos_y, cub->ray.map_x, cub->ray.map_y, cub->ray.step_x, cub->ray.step_y, cub->ray.side_dist_y, cub->ray.side_dist_y);
}

void	wall_distance(t_game *cub)
{
	// printf("cub->map[%d][%d]: %c\n", cub->ray.map_y, cub->ray.map_x, cub->map[cub->ray.map_y][cub->ray.map_x]);
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
	// printf("map_x: %d, step_x: %d, side_dist_x: %.2f, delta_dist_x: %.2f\nmap_y: %d, step_y: %d, side_dist_y: %.2f, delta_dist_y: %.2f\n", cub->ray.map_x, cub->ray.step_x, cub->ray.side_dist_x, cub->ray.delta_dist_x, cub->ray.map_y, cub->ray.step_y, cub->ray.side_dist_y, cub->ray.delta_dist_y);
	if (cub->ray.ray_dir_x == 0)
    	cub->ray.wall_dist = FLT_MAX;
	else if (cub->ray.side == 0)
    	cub->ray.wall_dist = (cub->ray.map_x - cub->ray.pos_x + (1 - cub->ray.step_x) / 2) / cub->ray.ray_dir_x;
	else
    	cub->ray.wall_dist = (cub->ray.map_y - cub->ray.pos_y + (1 - cub->ray.step_y) / 2) / cub->ray.ray_dir_y;
	// printf("side: %d, wall_dist: %.2f\n", cub->ray.side, cub->ray.wall_dist);
}

void	draw_wall(t_game *cub)
{
	cub->ray.draw_s = -cub->ray.line_h / 2 + WIN_H / 2;
	if (cub->ray.draw_s < 0)
		cub->ray.draw_s = 0;
	cub->ray.draw_e = cub->ray.line_h / 2 + WIN_H / 2;
	if (cub->ray.draw_e >= WIN_H)
		cub->ray.draw_e = WIN_H - 1;
	if (cub->ray.side == 0)
		cub->ray.wall_x = cub->ray.pos_y + cub->ray.wall_dist * cub->ray.ray_dir_y;
	else
		cub->ray.wall_x = cub->ray.pos_x + cub->ray.wall_dist * cub->ray.ray_dir_x;
	cub->ray.wall_x -= floor(cub->ray.wall_x);
}

void	get_textures(t_game *cub)
{
	cub->img.tex_x = (int)cub->ray.wall_x * cub->img.tex_size;
	if ((cub->ray.side == 0 && cub->ray.ray_dir_y > 0) \
		|| (cub->ray.side == 1 && cub->ray.ray_dir_y < 0))
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
	
	y = 0;
	while (y < WIN_H)
	{
		if (y < cub->ray.draw_s)
			cub->img_buf[y * cub->win_w + x] = cub->img.c_color;
		else if (y > cub->ray.draw_e)
			cub->img_buf[y * cub->win_w + x] = cub->img.f_color;
		else
		{
			if (cub->ray.line_h > 0)
   				cub->img.tex_y = (int)((y - cub->ray.draw_s) * cub->img.tex_size / cub->ray.line_h);
			else
   				cub->img.tex_y = 0;
			cub->img_buf[y * cub->win_w + x] = cub->img.tex_buf[cub->img.tex_i][cub->img.tex_y * cub->img.tex_size + cub->img.tex_x];
		}
		y++;
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

void	raycasting(t_game *cub)
{
	int	x;

	x = 0;
	ray_init(cub);
	cub->mlx_img = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (cub->mlx_img == NULL)
		ft_exit("Error generating mlx_img", cub, 1);
	cub->img_buf = (int *)mlx_get_data_addr(cub->mlx_img, &cub->bpp, &cub->line_len, &cub->endian);
	if (cub->img_buf == NULL)
		ft_exit("Error generating img_buf", cub, 1);
	facing_dir(cub);
	while (x < WIN_W)
	{
		get_delta_distance(cub, x);
		// printf("\n--------------------------\n");
		// printf("Get delta distance\n");
		// debug_print(cub, x);
		wall_distance(cub);
		// printf("\n--------------------------\n");
		// printf("Wall distance\n");
		// debug_print(cub, x);
		cub->ray.line_h = (int)WIN_H / cub->ray.wall_dist;
		// printf("line_h: %d, ray_dir_y: %.2f\n", cub->ray.line_h, cub->ray.ray_dir_y);
		draw_wall(cub);
		// printf("\n--------------------------\n");
		// printf("draw_wa	printf("Map Reading\npos_x: %.2f\n, pos_y: %.2f\n, face_dir: %c\n--------------------\n", cub->ray.pos_x, cub->ray.pos_y, cub->p_dir);ll\n");
		// debug_print(cub, x);
		get_textures(cub);
		// printf("\n--------------------------\n");
		// printf("Get textures\n");
		// debug_print(cub, x);
		render_textures(cub, x);
		// printf("\n--------------------------\n");
		// printf("render textures\n");
		// debug_print(cub, x);
		x++;
	}
	printf("\n--------------------------\n");
	printf("Before put img to window\n");
	debug_print(cub, x);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
}

