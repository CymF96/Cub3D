/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:53 by cofische          #+#    #+#             */
/*   Updated: 2024/12/04 16:04:03 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

bool	hit_door(float px, float py, t_game *game)
{
	int x = px / BLOCK_SIZE;
	int y = py / BLOCK_SIZE;

	if (game->map[y][x] == 'D' && !game->d.open)
		return true;
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
		if ((fabs(player->x - (float)game->d.x) < 150 && fabs(player->y - (float)game->d.y) < 75))
		{
			if (!game->d.open)
			{
				gettimeofday(&game->d.open_time, NULL); 
				game->d.open = true;
			}
		}
		else
			player->door = false;
	}
}

void check_door_timeout(t_game *game)
{
    if (game->d.open)
    {
        // Get the current time and check if 30 seconds have passed since the door was opened
        long current_time = get_time_in_seconds();
        long door_open_time = game->d.open_time.tv_sec;
        if (current_time - door_open_time >= DOOR_TIMEOUT)
        {
            // If 30 seconds have passed, close the door
			game->player.door = false;
            game->d.open = false;
        }
    }  // Returning 0 is important for mlx hook functions
}