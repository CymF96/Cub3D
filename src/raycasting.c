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
char *map[] = {
    "1111111111",
    "1010000001",
    "10100N0001",
    "1010000101",
    "1000000001",
    "1111111111",
    NULL
};
	double	camera_x;
	double	camera_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	dir_x = 0; // depend on player pos -- here is for NORTH
	double	dir_y = -1; // depend on player pos -- here is for NORTH
	double	plane_x = 0.66; // depend on player pos -- here is for NORTH
	double	plane_y = 0; // depend on player pos -- here is for NORTH
	double	win_w = 640;
	double	win_h = 320;
	int		x;
	/*DELTA DISTANCE CALCULATION*/
	double	posx = 5.5; //position_player_x;
	double	posy = 2.5; //position_player_y;
	int		map_x = (int)posx; 
	int		map_y = (int)posy; 
	double	delta_dir_x;
	double	delta_dir_y;
	/*MOVING THE RAY*/
	int		step_x; // step_x = -1 -->left // step_x = 1 -->right
	int		step_y; // step_y = -1 -->up // step_y = 1 -->down
	double	side_dist_x; //store dist from ray pos to next x or y grid line
	double	side_dist_y;
	/*CROSS A WALL*/
	int 	side; // if side = 0 is x wall 1st // if side = 1 y wall 1st
	/*CALCULATING WALL DISTANCE*/
	double	wall_dist;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;

	x = 0;
	while (x < win_w) // creating the fan of ray for NORTH side
	{
		/*RAYCASTING*/
		camera_x = 2 * x / win_w - 1;
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
		while (map[map_x][map_y] != '1')
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
		line_height = (int)win_h / wall_dist; // how it's going to appear on player's eyes (smaller or larger)
		/*draw the wall segment based on the screen size*/
		draw_start = -line_height / 2 + win_h / 2; // on the screen size, where the line start, if < 0 it is bottom
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + win_h / 2; // on the screen size, where the line start, if > screen height it is top of sreen so -1 security.
		if (draw_end >= win_h)
			draw_end =win_h - 1;
		if (side == 0)
			wall_x = posy + wall_dist * ray_dir_y;
		else
			wall_x = posx + wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		//function to draw the line
		x++;
	}
}