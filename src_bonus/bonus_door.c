/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:53 by cofische          #+#    #+#             */
/*   Updated: 2024/12/09 10:46:19 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

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
	int x;
	int y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (game->map[y][x] == 'D')
	{
		game->d_index = find_door_index(game, x, y);
		if (game->d_index == -1)
			ft_exit("door id not found", game, 1);
		if (game->d[game->d_index]->open == false)
			return true;
	}	
	return false;	
}

long get_time_in_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec;
}

void	door_movement(t_game *game, t_player *player)
{
	if (player->door)
	{
		if ((fabs(player->x - (float)game->d[game->d_index]->x) < 150 && fabs(player->y - (float)game->d[game->d_index]->y) < 75))
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

void check_door_timeout(t_game *game)
{
    if (game->d[game->d_index]->open)
    {
        // Get the current time and check if 30 seconds have passed since the door was opened
        long current_time = get_time_in_seconds();
        long door_open_time = game->d[game->d_index]->open_time.tv_sec;
        if (current_time - door_open_time >= DOOR_TIMEOUT)
        {
            // If 30 seconds have passed, close the door
			game->player.door = false;
            game->d[game->d_index]->open = false;
        }
    }  // Returning 0 is important for mlx hook functions
}