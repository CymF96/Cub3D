/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:40 by cofische          #+#    #+#             */
/*   Updated: 2024/12/09 10:03:06 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

bool hit_wall(float px, float py, t_game *game)
{
	int x;
	int y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;

	if (game->map[y][x] == '1')
		return true;
	return false;
}

void wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle)
{
	float map_x;
	float map_y;
	float hit_x;
	float hit_y;

	map_x = floor(ray_x / BLOCK_SIZE);
	map_y = floor(ray_y / BLOCK_SIZE);
	hit_x = ray_x - (map_x * BLOCK_SIZE);
	hit_y = ray_y - (map_y * BLOCK_SIZE);
	if (hit_x <= 1 || hit_x >= BLOCK_SIZE - 1)
	{
		game->ray.tex_x = (int)hit_y % BLOCK_SIZE;
		if (game->ray.tex_x == 63 || game->ray.tex_x == 0)
			return ;
		game->ray.tex_id = (cos(ray_angle) > 0) ? 3 : 2; //change for norminette
	}
	else
	{
		game->ray.tex_x = (int)hit_x % BLOCK_SIZE;
		game->ray.tex_id = (sin(ray_angle) > 0) ? 1 : 0; //change for norminette
	}
}

void render_wall(t_game *game, t_ray *ray, int x)
{
	int color;
	float pos;

	ray->step = BLOCK_SIZE / ray->height_wall; // calcualtion the incrementation for pixel loop
	ray->start_wall = (HEIGHT - ray->height_wall) / 2;						 // start position of wall slice
	ray->end_wall = ray->start_wall + ray->height_wall;	
	if (ray->height_wall > HEIGHT)
		ray->start_wall %= HEIGHT; 	 // if wall is bigger than screen, do a modulo so it start at correct position
	pos = (ray->start_wall - HEIGHT / 2 + ray->height_wall / 2) * ray->step; // getting the step converted into pixel side for correct dimension in pixel loop
	while (ray->start_wall < ray->end_wall)						 // add curent pixel wall to mlx_data for final image
	{
		int map_x = (int)(ray->ray_x / BLOCK_SIZE);
        int map_y = (int)(ray->ray_y / BLOCK_SIZE);														 // cheking the ray assignement
		ray->tex_y = (int)pos % BLOCK_SIZE;
        if (game->map[map_y][map_x] == 'D' && !game->d[game->d_index]->open)
		{ 
			color = get_pixel_image_door(game, &game->ray);
            put_pixel(x, ray->start_wall, color, game);								 // using binary AND op to ensure pixel not get out of TILE_HEIGHT
		}
		else
		{
			color = get_pixel_image(game, &game->ray);
			put_pixel(x, ray->start_wall, color, game);
		}
		pos += ray->step;
		ray->start_wall++;
	}
}

void draw_line(t_player *player, t_game *game, float ray_angle, int i)
{
	(void)i;
	// set the ray start point as player postion on screen
	game->ray.ray_x = player->x;
	game->ray.ray_y = player->y;
	while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game) && !hit_door(game->ray.ray_x, game->ray.ray_y, game)) // problem
	{
		// inscreasing ray movement until getting the wall hit point
		/*DEBUGGING SHOWING THE FOV CAST IN RED*/
		// put_pixel(game->ray.ray_x, game->ray.ray_y, 0xFF0000, game);
		/*DEBUGGING SHOWING THE FOV CAST IN RED*/
		game->ray.ray_x += cos(ray_angle);
		game->ray.ray_y += sin(ray_angle);
	}
	// //per hit point, checking which wall has been hit to use correct texture
	wall_direction(game, game->ray.ray_x, game->ray.ray_y, ray_angle);

	// //calculating the total distance between player and wall to set the size of the wall line with fisheye correction
	game->ray.delta_x = game->ray.ray_x - player->x;
	game->ray.delta_y = game->ray.ray_y - player->y;
	game->ray.angle = atan2(game->ray.delta_y, game->ray.delta_x) - game->player.angle;
	game->ray.wall_dist = sqrt((game->ray.delta_x * game->ray.delta_x) + (game->ray.delta_y * game->ray.delta_y)) * cos(game->ray.angle);
	game->ray.height_wall = (BLOCK_SIZE / game->ray.wall_dist) * (WIDTH / 2);
	// printing pixel to img with the wall render in 3D with correct textures
	render_wall(game, &game->ray, i);

	/*DEBUGGING SHOWING THE WALL RENDER ON 3D*/
	// int start_y = (HEIGHT - game->ray.height_wall) / 2;
	// int	end = start_y + game->ray.height_wall;
	// while (start_y < end)
	// {
	// 	put_pixel(i, start_y, 255, game);
	// 	start_y++;
	// }
	/*DEBUGGING SHOWING THE WALL RENDER ON 3D*/
}

/*DEBUGGING SHOWING THE MAP ON 2D GRID*/
// void draw_square(int x, int y, int size, int color, t_game *game)
// {
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x + i, y, color, game);
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x, y + i, color, game);
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x + size, y + i, color, game);
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x + i, y + size, color, game);
// }

// void draw_map(t_game *game)
// {
// 	char **map = game->map;
// 	int color = 0x0000FF;
// 	for (int y = 0; map[y]; y++)
// 	{
// 		for (int x = 0; map[y][x]; x++)
// 		{
// 			if (map[y][x] == '1')
// 				draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, color, game);
// 		}
// 	}
// }
/*DEBUGGING SHOWING THE MAP ON 2D GRID*/

int draw_game(t_game *game)
{
	// creating the final img pointer and data addrs to be use for screen display
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);

	// as floor and ceiling are always in the screen, they are draw separatly before the wall rendering
	draw_floor(game);
	draw_ceiling(game);

	/*DEBUGGING SHOWING THE MAP ON 2D GRID*/
	// draw_square(game->player.x, game->player.y, 5, 0x00FF00, game);
	// draw_map(game);
	/*DEBUGGING*/

	// draw wall after the background
	draw_wall(game);
	draw_minimap(game);
	mouse_move(game);
	move_player(&game->player);
	door_movement(game, &game->player);
	check_door_timeout(game);
	// put final image to window
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
	game->img = NULL;
	// mlx_destroy_image(game->mlx, game->img);
	// game->img = NULL;
	return (0);
}
