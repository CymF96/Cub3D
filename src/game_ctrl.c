/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:54:25 by cofische          #+#    #+#             */
/*   Updated: 2024/11/27 19:18:03 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	t_player *player = &game->player;
	if (keycode == ESC)
	{
		mlx_loop_end(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
		player->up = true;
	if (keycode == S)
		player->down = true;
	if (keycode == A)
		player->left = true;
	if (keycode == D)
		player->right = true;
	if (keycode == LEFT)
		player->ro_left = true;
	if (keycode == RIGHT)
		player->ro_right = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->up = false;
	if (keycode == S)
		player->down = false;
	if (keycode == A)
		player->left = false;
	if (keycode == D)
		player->right = false;
	if (keycode == LEFT)
		player->ro_left = false;
	if (keycode == RIGHT)
		player->ro_right = false;
	return (0);
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
	if (player->left)
	{
		player->x += player->cos_angle * player->speed;
		player->y -= player->sin_angle * player->speed;
	}
	if (player->right)
	{
		player->x -= player->cos_angle * player->speed;
		player->y += player->sin_angle * player->speed;
	}
}

void	move_player(t_player *player)
{
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	if (player->ro_left)
		player->angle -= player->angle_speed;
	if (player->ro_right)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	key_movement(player);
}

int	cross_close_window(t_game *cub)
{
	mlx_loop_end(cub->mlx);
	ft_exit(NULL, cub, 0);
	return (0);
}