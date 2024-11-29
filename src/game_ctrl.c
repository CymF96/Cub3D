/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:54:25 by cofische          #+#    #+#             */
/*   Updated: 2024/11/29 13:33:00 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_player *player)
{
	if (keycode == ESC)
		player->exit = true;
	if (keycode == W)
		player->up = true;
	if (keycode == S)
		player->down = true;
	if (keycode == A)
		player->left = true;
	if (keycode == D)
		player->right = true;
	if (keycode == RIGHT)
		player->ro_right = true;
	if (keycode == LEFT)
		player->ro_left = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == ESC)
		player->exit = false;
	if (keycode == W)
		player->up = false;
	if (keycode == S)
		player->down = false;
	if (keycode == A)
		player->left = false;
	if (keycode == D)
		player->right = false;
	if (keycode == RIGHT)
		player->ro_right = false;
	if (keycode == LEFT)
		player->ro_left = false;
	return (0);
}


//changing the angle of player by angle_speed when arrow pressed
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

//updating cos and sin angle to calculate the new x and y of player
void	key_movement(t_player *player) // add checker for the wall coalistion 
{
	if (player->up)
	{
		//testing wall coalition checker
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
	//change the player x and y position and the angle depending on the keycode
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

int	cross_close_window(t_game *cub)
{
	mlx_loop_end(cub->mlx);
	ft_exit(NULL, cub, 0);
	return (0);
}