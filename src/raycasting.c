#include "cub3d.h"

// function to prepare the raycasting info depending on the player facing position
// dir_x, dir_y, plane_x, plane_y
/*
Facing North (up):

    dir_x = 0, dir_y = -1
    plane_x = 0.66, plane_y = 0

Facing South (down):

    dir_x = 0, dir_y = 1
    plane_x = -0.66, plane_y = 0

Facing East (right):

    dir_x = 1, dir_y = 0
    plane_x = 0, plane_y = 0.66

Facing West (left):

    dir_x = -1, dir_y = 0
    plane_x = 0, plane_y = -0.66
*/
/*
// Assume we have the player's grid position
int player_x = 2; // Column index
int player_y = 2; // Row index

// Set up player's position as float
double pos_x = player_x + 0.5; // Center of the cell in the x-direction
double pos_y = player_y + 0.5; // Center of the cell in the y-direction
*/

void	raycasting(t_game *cub)
{
	cub->win_h = WIN_H;
	cub->win_w = WIN_W;
	double	camera_x = 0;
	double	camera_y = 0;
	double	ray_dir_x = 0;
	double	ray_dir_y = 0;
	double	dir_x = 0; // depend on player pos -- here is for NORTH
	double	dir_y = -1; // depend on player pos -- here is for NORTH
	double	plane_x = 0.66; // depend on player pos -- here is for NORTH
	double	plane_y = 0; // depend on player pos -- here is for NORTH
	int		x;
	/*DELTA DISTANCE CALCULATION*/
	double	posx = 5.5; //position_player_x;
	double	posy = 2.5; //position_player_y;
	int		map_x = (int)posx; 
	int		map_y = (int)posy; 
	double	delta_dir_x = 0;
	double	delta_dir_y = 0;
	/*MOVING THE RAY*/
	int		step_x = 0; // step_x = -1 -->left // step_x = 1 -->right
	int		step_y = 0; // step_y = -1 -->up // step_y = 1 -->down
	double	side_dist_x = 0; //store dist from ray pos to next x or y grid line
	double	side_dist_y = 0;
	/*CROSS A WALL*/
	int 	side = 0; // if side = 0 is x wall 1st // if side = 1 y wall 1st
	/*CALCULATING WALL DISTANCE*/
	double	wall_dist = 0;
	double	wall_x = 0;
	int		line_height = 0;
	int		draw_start = 0;
	int		draw_end = 0;
	/*texture render*/
	int		tex_index = 0; // select which image to generate (NO, SO, WE or EA)

	x = 0;
	cub->mlx_img = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (cub->mlx_img == NULL)
		ft_exit("Error generating mlx_img", cub, 1);
	cub->img_buf = (int *)mlx_get_data_addr(cub->mlx_img, &cub->bpp, &cub->line_lenght, &cub->endian);
	if (cub->img_buf == NULL)
		ft_exit("Error generating img_buf", cub, 1);

	while (x < WIN_W) // creating the fan of ray for NORTH side
	{
		/*RAYCASTING*/
		camera_y = 0;
		camera_x = 2 * x / WIN_W - 1;
		ray_dir_x = dir_x + plane_x * camera_x;
		ray_dir_y = dir_y + plane_y * camera_y;
		/*current grid position*/
		map_x = (int)posx;
		map_y = (int)posy;
		/*DELTA DISTANCE*/
		delta_dir_x = fabs(1 / ray_dir_x); // see the distance between my pos and the next x or y grid
		delta_dir_y = fabs(1 / ray_dir_y);
		/*MOVING RAY*/
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (posx - map_x) * delta_dir_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - posx) * delta_dir_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (posy - map_y) * delta_dir_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - posy) * delta_dir_y;
		}
		/*MOVING UNTIL WALL*/
		while (cub->map[map_x][map_y] != '1')
		{
			if (side_dist_x < side_dist_y)
			{
				map_x += step_x;
				side_dist_x += delta_dir_x;
				side = 0;
			}
			else
			{
				map_y += step_y;
				side_dist_y += delta_dir_y;
				side = 1;
			}
		}
		/*calculate the distance btw player and wall intersection*/
		if (side == 0)
			wall_dist = (map_x - posx + (1 - step_x) / 2) / ray_dir_x;
		else
			wall_dist = (map_y - posy + (1 - step_y) / 2) / ray_dir_y;
		/*calculating the wall height for texture*/
		line_height = (int)WIN_H / wall_dist; // how it's going to appear on player's eyes (smaller or larger)
		/*draw the wall segment based on the screen size*/
		draw_start = -line_height / 2 + WIN_H / 2; // on the screen size, where the line start, if < 0 it is bottom
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WIN_H / 2; // on the screen size, where the line start, if > screen height it is top of sreen so -1 security.
		if (draw_end >= WIN_H)
			draw_end =WIN_H - 1;
		if (side == 0)
			wall_x = posy + wall_dist * ray_dir_y;
		else
			wall_x = posx + wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		/*texture render*/
		cub->img.tex_x = (int)wall_x * cub->img.tex_size;
		if ((side == 0 && ray_dir_y > 0) || (side == 1 && ray_dir_y < 0))
			cub->img.tex_x = cub->img.tex_size - cub->img.tex_x - 1;
		if (side == 0) 
		{
			if (ray_dir_x > 0)
				tex_index = 0;
			else
				tex_index = 1;
		}
		else
		{
			if (ray_dir_y > 0)
				tex_index = 2;
			else
				tex_index = 3;
		}
		int y = 0;
		while (y < WIN_H)
		{
			if (y < draw_start)
				cub->img_buf[y * cub->win_w + x] = cub->img.c_color;
			else if (y > draw_end)
				cub->img_buf[y * cub->win_w + x] = cub->img.f_color;
			else
			{
				if (line_height > 0)
    				cub->img.tex_y = (int)((y - draw_start) * cub->img.tex_size / line_height);
				else
    				cub->img.tex_y = 0;
				cub->img_buf[y * cub->win_w + x] = cub->img.tex_buf[tex_index][cub->img.tex_y * cub->img.tex_size + cub->img.tex_x];
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->mlx_img, 0, 0);
}