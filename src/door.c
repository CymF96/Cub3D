/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:53 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:14:53 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_init(t_door *d)
{
	d->open = false;
	d->x = 0;
	d->y = 0;
}

int	find_door_index(t_game *game, int x, int y)
{
	int	i;

	x = (x + 0.5) * BLOCK_SIZE;
	y = (y + 0.5) * BLOCK_SIZE;
	i = 0;
	while (game->d[i] != NULL)
	{
		if (game->d[i]->x == x && game->d[i]->y == y)
			return (i);
		i++;
	}
	return (-1);
}

bool	hit_door(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (game->map[y][x] == 'D')
	{
		game->d_index = find_door_index(game, x, y);
		if (game->d_index == -1)
			ft_exit("door id not found", game, 1);
		if (game->d[game->d_index]->open == false)
			return (true);
	}
	return (false);
}

void	door_movement(t_game *game, t_player *player)
{
	if (player->door)
	{
		if ((fabs(player->x - (float)game->d[game->d_index]->x) < 150 \
			&& fabs(player->y - (float)game->d[game->d_index]->y) < 75))
		{
			if (!game->d[game->d_index]->open)
			{
				gettimeofday(&game->d[game->d_index]->open_time, NULL);
				game->d[game->d_index]->open = true;
			}
		}
		else
			player->door = false;
	}
}

void	check_door_timeout(t_game *game)
{
	long	current_time;
	long	door_open_time;

	if (game->d[game->d_index]->open)
	{
		current_time = get_time_in_seconds();
		door_open_time = game->d[game->d_index]->open_time.tv_sec;
		if (current_time - door_open_time >= DOOR_TIMEOUT)
		{
			game->player.door = false;
			game->d[game->d_index]->open = false;
		}
	}
}
