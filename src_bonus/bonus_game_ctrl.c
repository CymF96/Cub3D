/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_game_ctrl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:54:25 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 16:08:09 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	rotation(t_player *player)
{
	if (player->ro_left)
		player->angle -= player->angle_speed;
	if (player->ro_right)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle += 2 * PI;
}

void	new_coordinates(t_player *player, float new_x, float new_y)
{
	float	c_offset;

	c_offset = 2.0;
	if (!hit_wall(new_x + c_offset, new_y + c_offset, player->game) \
		&& !hit_wall(new_x - c_offset, new_y - c_offset, player->game) \
		&& !hit_wall(new_x + c_offset, new_y - c_offset, player->game) \
		&& !hit_wall(new_x - c_offset, new_y + c_offset, player->game) \
		&& !hit_door(new_x + c_offset, new_y + c_offset, player->game) \
		&& !hit_door(new_x - c_offset, new_y - c_offset, player->game) \
		&& !hit_door(new_x + c_offset, new_y - c_offset, player->game) \
		&& !hit_door(new_x - c_offset, new_y + c_offset, player->game))
	{
		player->x = new_x;
		player->y = new_y;
	}
}

void	key_movement(t_player *player)
{
	player->new_x = player->x;
	player->new_y = player->y;
	if (player->up)
	{
		player->new_x += player->cos_angle * player->speed;
		player->new_y += player->sin_angle * player->speed;
	}
	if (player->down)
	{
		player->new_x -= player->cos_angle * player->speed;
		player->new_y -= player->sin_angle * player->speed;
	}
	if (player->right)
	{
		player->new_y += player->cos_angle * player->speed;
		player->new_x -= player->sin_angle * player->speed;
	}
	if (player->left)
	{
		player->new_y -= player->cos_angle * player->speed;
		player->new_x += player->sin_angle * player->speed;
	}
	new_coordinates(player, player->new_x, player->new_y);
}

void	move_player(t_player *player)
{
	if (player->exit)
	{
		mlx_loop_end(player->game->mlx);
		ft_exit(NULL, player->game, 0);
	}
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	if (player->up || player->down || player->right || player->left)
		key_movement(player);
	else if (player->ro_left || player->ro_right)
		rotation(player);
}
