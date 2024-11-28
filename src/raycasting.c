/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:40 by cofische          #+#    #+#             */
/*   Updated: 2024/11/28 12:53:10 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

bool	hit_wall(float px, float py, t_game *game)
{
	int x;
	int y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;

	if (x < 0 || y < 0 || x >= (int)ft_strlen(game->map[y]) || y <= game->map_height)
	 	return true;
	if (game->map[y][x] == '1')
		return true;
	return false;
}

void	wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle)
{
	int		side_x;
	int		side_y;
	bool	hit_x;
	bool	hit_y;

	side_x = 0;
	side_y = 0;
	if (cos(ray_angle) > 0)
		side_x = 1;
	if (sin(ray_angle) > 0)
		side_y = 1;
	hit_x = hit_wall(ray_x - side_x, ray_y, game) || hit_wall(ray_x - side_x, ray_y - side_y, game);
	hit_y = hit_wall(ray_x, ray_y - side_y, game) || hit_wall(ray_x, ray_y, game);
	if (hit_x)
	{
		game->ray.tex_x = (int)ray_x % BLOCK_SIZE;
		game->ray.tex_id = 3;
		if (side_y == 1)
			game->ray.tex_id = 0;
	}
	else if (hit_y)
	{
		game->ray.tex_x = (int)ray_y % BLOCK_SIZE;
		game->ray.tex_id = 2;
		if (side_x == 1)
			game->ray.tex_id = 1;	
	}
}

void	render_wall(t_game *game, t_ray *ray, int i)
{
	int	color;

	ray->step = BLOCK_SIZE / ray->height_wall;
	if (ray->height_wall > HEIGHT)
	{
		ray->tex_y = (ray->height_wall - HEIGHT) * ray->step / 2;
		ray->height_wall = HEIGHT;
	}
	ray->start_wall = (HEIGHT - ray->height_wall) / 2;
	ray->end_wall = game->ray.start_wall + game->ray.height_wall;
	while (game->ray.start_wall < game->ray.end_wall)
	{
		color = 255;
		// color = get_pixel_image(game, &game->ray);
		put_pixel(i, ray->start_wall, color, game);
		ray->tex_y += ray->step;
		ray->start_wall++;
	}
}

void	draw_line(t_player *player, t_game *game, float ray_angle, int i)
{
	game->ray.ray_x = player->x;
	game->ray.ray_y = player->y;
	// printf("BEFORE WALL_DIRECTION: ray_x: %.5f, player_x %.5f, ray_y: %.5f, player_y: %.5f\n", game->ray.ray_x, player->x, game->ray.ray_y, player->y);
	while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game))
	{
		game->ray.ray_x += cos(ray_angle);
		game->ray.ray_y += sin(ray_angle);
		printf("HIT_WALL: ray_x: %.5f, ray_y: %.5f\n", game->ray.ray_x, game->ray.ray_y);
	}
	// printf("AFTER WALL_DIRECTION: ray_x: %.5f, player_x %.5f, ray_y: %.5f, player_y: %.5f\n", game->ray.ray_x, player->x, game->ray.ray_y, player->y);
	wall_direction(game, game->ray.ray_x, game->ray.ray_y, ray_angle);
	game->ray.delta_x = game->ray.ray_x - player->x;
	game->ray.delta_y = game->ray.ray_y - player->y;
	// printf("delta_x: %.2f, delta_y: %.2f\n", game->ray.delta_x, game->ray.delta_y);
	// printf("atan: %.2f\n", atan2(game->ray.delta_y, game->ray.delta_x) - game->player.angle);
	game->ray.angle = atan2(game->ray.delta_y, game->ray.delta_x) - game->player.angle;
	// printf("sqrt: %.2f\n", sqrt((game->ray.delta_x * game->ray.delta_x) + (game->ray.delta_y * game->ray.delta_y)) * cos(game->ray.angle));
	game->ray.wall_dist = sqrt((game->ray.delta_x * game->ray.delta_x) + (game->ray.delta_y * game->ray.delta_y)) * cos(ray_angle);
	game->ray.height_wall = (BLOCK_SIZE / game->ray.wall_dist) * (WIDTH / 2);
	// printf("ray->wall_distance : %.2f\n", game->ray.wall_dist);
	render_wall(game, &game->ray, i);
}

void	draw_game(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
	draw_floor(game);
	draw_ceiling(game);
	draw_wall(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
	game->img = NULL;
}
