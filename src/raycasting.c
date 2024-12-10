/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:40 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 12:22:56 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	hit_wall(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle)
{
	float	map_x;
	float	map_y;

	map_x = floor(ray_x / BLOCK_SIZE);
	map_y = floor(ray_y / BLOCK_SIZE);
	game->ray.hit_x = ray_x - (map_x * BLOCK_SIZE);
	game->ray.hit_y = ray_y - (map_y * BLOCK_SIZE);
	if (game->ray.hit_x <= 1 || game->ray.hit_x >= BLOCK_SIZE - 1)
	{
		game->ray.tex_x = (int)game->ray.hit_y % BLOCK_SIZE;
		if (game->ray.tex_x == 63 || game->ray.tex_x == 0)
			return ;
		if (cos(ray_angle) > 0)
			game->ray.tex_id = 3;
		else
			game->ray.tex_id = 2;
	}
	else
	{
		game->ray.tex_x = (int)game->ray.hit_x % BLOCK_SIZE;
		if (sin(ray_angle) > 0)
			game->ray.tex_id = 1;
		else
			game->ray.tex_id = 0;
	}
}

void	calculate_line(t_player *player, t_game *game, float ray_angle, int x)
{
	game->ray.ray_x = player->x;
	game->ray.ray_y = player->y;
	while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game))
	{
		game->ray.ray_x += cos(ray_angle);
		game->ray.ray_y += sin(ray_angle);
	}
	wall_direction(game, game->ray.ray_x, game->ray.ray_y, ray_angle);
	game->ray.delta_x = game->ray.ray_x - player->x;
	game->ray.delta_y = game->ray.ray_y - player->y;
	game->ray.tan_angle = atan2(game->ray.delta_y, game->ray.delta_x) \
		- game->player.angle;
	game->ray.wall_dist = sqrt((game->ray.delta_x * game->ray.delta_x) \
		+ (game->ray.delta_y * game->ray.delta_y)) * cos(game->ray.tan_angle);
	game->ray.height_wall = (BLOCK_SIZE / game->ray.wall_dist) * (WIDTH / 2);
	draw_wall(game, &game->ray, x);
}

void	render_wall(t_game *game)
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
		calculate_line(&game->player, game, ray_angle, x);
	}
}

int	gameloop(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, \
		&game->size_line, &game->endian);
	move_player(&game->player);
	draw_floor(game);
	draw_ceiling(game);
	render_wall(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
	game->img = NULL;
	return (0);
}
