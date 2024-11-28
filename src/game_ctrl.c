/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:54:25 by cofische          #+#    #+#             */
/*   Updated: 2024/11/28 14:35:00 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//changing the angle of player by angle_speed when arrow pressed
void	player_rotation(int keycode, t_player *player)
{
	if (keycode == LEFT)
		player->angle -= player->angle_speed;
	if (keycode == RIGHT)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

//updating cos and sin angle to calculate the new x and y of player
void	key_movement(int keycode, t_player *player)
{
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	if (keycode == ESC)
	{
		mlx_loop_end(player->game->mlx);
		ft_exit(NULL, player->game, 0);
	}
	if (keycode == W)
	{
		player->x += player->cos_angle * player->speed;
		player->y += player->sin_angle * player->speed;
	}
	if (keycode == S)
	{
		player->x -= player->cos_angle * player->speed;
		player->y -= player->sin_angle * player->speed;
	}
	if (keycode == A)
	{
		player->x += player->cos_angle * player->speed;
		player->y -= player->sin_angle * player->speed;
	}
	if (keycode == D)
	{
		player->x -= player->cos_angle * player->speed;
		player->y += player->sin_angle * player->speed;
	}
	if (keycode == RIGHT || keycode == LEFT)
		player_rotation(keycode, player);
}

int	move_player(int keycode, t_game *game)
{
	//change the player x and y position and the angle depending on the keycode
	key_movement(keycode, &game->player);
	mlx_destroy_image(game->mlx, game->img);
	game->img = NULL;
	//draw new rendering
	draw_game(game);
	return (0);
}

int	cross_close_window(t_game *cub)
{
	mlx_loop_end(cub->mlx);
	ft_exit(NULL, cub, 0);
	return (0);
}