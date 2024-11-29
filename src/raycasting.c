/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:40 by cofische          #+#    #+#             */
/*   Updated: 2024/11/29 17:24:53 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

bool	hit_wall(float px, float py, t_game *game)
{
	int x;
	int y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;

	if (x < 0 || y < 0 || x >= (int)ft_strlen(game->map[y]) || y >= game->map_height)
		return true;
	if (game->map[y][x] == '1')
		return true;
	return false;
}

void	wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle)
{
	int		side_x;
	int		side_y;

	side_x = 0;
	side_y = 0;
	// printf("%.5f\n", cos(ray_angle));
	if (cos(ray_angle) > 0)
		side_x = 1;
	if (sin(ray_angle) > 0)
		side_y = 1;
	/******PROBLEM ON THIS PART OF CODE*********/
	
	if (hit_wall(ray_x - side_x, ray_y, game) || hit_wall(ray_x - side_x, ray_y - side_y, game))
	{
		game->ray.tex_x = (int)ray_x % BLOCK_SIZE;
		// printf("for NO//SO -- ray.tex_x: %d, ray.x: %.5f\n", game->ray.tex_x, ray_x);
		game->ray.tex_id = 0;
		if (side_y == 1)
			game->ray.tex_id = 1; //PROBLEM -- texture prints in reverse on screen
	}
	else if (hit_wall(ray_x, ray_y - side_y, game) || hit_wall(ray_x, ray_y, game))
	{
		game->ray.tex_x = (int)ray_y % BLOCK_SIZE;
		// printf("for WE/EA -- ray.tex_x: %d\n", game->ray.tex_x );
		game->ray.tex_id = 2; //PROBLEM -- WEST text is getting the 1st hit_wall condition 
		if (side_x == 1)
			game->ray.tex_id = 3;	
	}
}

void	render_wall(t_game *game, t_ray *ray, int x)
{
	int		color;
	float	pos;

	ray->step = BLOCK_SIZE / ray->height_wall; //calcualtion the incrementation for pixel loop
	if (ray->height_wall > HEIGHT) // security to fit the wall as the screen H value
	{
		ray->tex_y = (ray->height_wall - HEIGHT) * ray->step / 2;
		ray->height_wall = HEIGHT;
	}
	ray->start_wall = (HEIGHT - ray->height_wall) / 2; //start position of wall slice
	ray->end_wall = game->ray.start_wall + game->ray.height_wall; //end position of wall slice
	pos = (ray->start_wall - HEIGHT / 2 + ray->height_wall / 2) * ray->step; //getting the step converted into pixel side for correct dimension in pixel loop
	while (game->ray.start_wall < game->ray.end_wall) //add curent pixel wall to mlx_data for final image
	{ //cheking the ray assignement
		ray->tex_y = (int)pos & (BLOCK_SIZE - 1); // using binary AND op to ensure pixel not get out of TILE_HEIGHT
		color = get_pixel_image(game, &game->ray);
		put_pixel(x, ray->start_wall, color, game);
		pos += ray->step;
		ray->start_wall++;
	}
}

void	draw_line(t_player *player, t_game *game, float ray_angle, int i)
{
	(void)i;
	//set the ray start point as player postion on screen
	game->ray.ray_x = player->x;
	game->ray.ray_y = player->y;
	while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game)) // problem 
	{
		//inscreasing ray movement until getting the wall hit point
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
	//printing pixel to img with the wall render in 3D with correct textures 
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
void	draw_square(int x, int y, int size, int color, t_game *game)
{
	for (int i = 0; i < size; i++)
		put_pixel(x + i, y, color, game);
	for (int i = 0; i < size; i++)
		put_pixel(x, y + i, color, game);
	for (int i = 0; i < size; i++)
		put_pixel(x + size, y + i, color, game);
	for (int i = 0; i < size; i++)
		put_pixel(x + i, y + size, color, game);
}

void	draw_map(t_game *game)
{
	char **map = game->map;
	int color = 0x0000FF;
	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			if (map[y][x] == '1')
				draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, color, game);
		}
	}
}
/*DEBUGGING SHOWING THE MAP ON 2D GRID*/


int	draw_game(t_game *game)
{
	//creating the final img pointer and data addrs to be use for screen display
	move_player(&game->player);
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
	//put final image to window
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
	game->img = NULL;
	// mlx_destroy_image(game->mlx, game->img);
	// game->img = NULL;
	return (0);
}
