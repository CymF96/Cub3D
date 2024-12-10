/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:36:10 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 15:36:52 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

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
	if (keycode == E)
		player->door = true;
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

int	cross_close_window(t_game *cub)
{
	mlx_loop_end(cub->mlx);
	ft_exit(NULL, cub, 0);
	return (0);
}
