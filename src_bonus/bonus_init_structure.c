/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_structure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:35 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 16:12:15 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	ray_init(t_ray *ray)
{
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->tan_angle = 0;
	ray->height_wall = 0;
	ray->fov = PI / 3;
	ray->step = 0;
	ray->wall_dist = 0;
	ray->start_wall = 0;
	ray->end_wall = 0;
	ray->side = 0;
	ray->tex_id = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
	ray->hit_x = 0;
	ray->hit_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->color = 0;
	ray->pos = 0;
}

void	init_player(t_player *player, t_game *game)
{
	player->up = false;
	player->down = false;
	player->right = false;
	player->left = false;
	player->exit = false;
	player->ro_left = false;
	player->ro_right = false;
	player->door = false;
	player->shot = false;
	player->speed = 3;
	player->angle_speed = 0.1;
	player->angle = 0;
	player->game = game;
	player->new_x = 0;
	player->new_y = 0;
}

void	map_init(t_mini *m)
{
	m->m_tile = 8;
	m->m_x = 0;
	m->m_y = 0;
	m->m_dir_x = 0;
	m->m_dir_y = 0;
	m->m_player_x = 0;
	m->m_player_y = 0;
}

void	initialization_bis(t_game *game)
{
	game->d = NULL;
	game->gun_frame = 0;
	gettimeofday(&game->last_frame_time, NULL);
	game->accumulated_time = 0;
	game->nbr_doors = 0;
	game->d_index = 0;
	game->map_height = 0;
	game->bpp = 0;
	game->size_line = 0;
	game->endian = 0;
	game->player_pos = 0;
	game->mouse_delta_x = 0;
	game->last_mouse_x = WIDTH / 2;
	game->gun_x_start = (WIDTH - 640) / 2;
	game->gun_y_start = (HEIGHT - 505);
	game->gun_color = 0;
	ft_memset(game->f, -1, sizeof(game->f));
	ft_memset(game->c, -1, sizeof(game->c));
	ray_init(&game->ray);
	map_init(&game->m_map);
}

void	initialization(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->data = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->door = NULL;
	game->gun1 = NULL;
	game->gun2 = NULL;
	game->shot1 = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->dr = NULL;
	game->map = NULL;
	game->line = NULL;
	initialization_bis(game);
}
