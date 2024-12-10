/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:54:25 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 11:32:58 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation(t_player *player)
{
	if (player->ro_left)
		player->angle -= player->angle_speed;
	if (player->ro_right)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	key_movement(t_player *player)
{
	if (player->up)
	{
		player->x += player->cos_angle * player->speed;
		player->y += player->sin_angle * player->speed;
	}
	if (player->down)
	{
		player->x -= player->cos_angle * player->speed;
		player->y -= player->sin_angle * player->speed;
	}
	if (player->right)
	{
		player->y += player->cos_angle * player->speed;
		player->x -= player->sin_angle * player->speed;
	}
	if (player->left)
	{
		player->y -= player->cos_angle * player->speed;
		player->x += player->sin_angle * player->speed;
	}
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
