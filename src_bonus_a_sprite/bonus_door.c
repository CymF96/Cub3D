/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_door.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:03:53 by cofische          #+#    #+#             */
/*   Updated: 2024/12/06 10:38:37 by cofische         ###   ########.fr       */
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
			if (game->d.state == CLOSE)
			{
				gettimeofday(&game->d.open_time, NULL); 
				game->d.state = OPENING;
			}
		}
		else
			player->door = false;
	}
}

void check_door_timeout(t_game *game)
{
    if (game->d.state == OPEN)
    {
        // Get the current time and check if 30 seconds have passed since the door was opened
        long current_time = get_time_in_seconds();
        long door_open_time = game->d.open_time.tv_sec;
        if (current_time - door_open_time >= DOOR_TIMEOUT)
        {
            // If 30 seconds have passed, close the door
			game->player.door = false;
            game->d.state = CLOSING;
			
        }
    }  // Returning 0 is important for mlx hook functions
}

void update_doors(t_game *game, t_door *door)
{
	struct timeval now;
	gettimeofday(&now, NULL);

	// for (int i = 0; i < game->door_count; i++)
	// {
	//     t_door *door = &game->doors[i];

	//     // Calculate elapsed time since the last update
	float elapsed = (now.tv_sec - door->open_time.tv_sec) +
					(now.tv_usec - door->open_time.tv_usec) / 1000000.0;

		// Check if the door is open and exceeds timeout
	// Update the door timer based on its state
	if (door->state == OPENING)
	{
		door->timer += elapsed / DOOR_ANIMATION_DURATION;
		if (door->timer >= 1.0)
		{
			door->timer = 1.0;
			door->state = OPEN;
			door->open_time = now; // Record the time the door fully opened
		}
	}
	else if (door->state == CLOSING)
	{
		door->timer -= elapsed / DOOR_ANIMATION_DURATION;
		if (door->timer <= 0.0)
		{
			door->timer = 0.0;
			door->state = CLOSE;
		}
	}

		// Update the last update time to the current time
	door->last_update = now;
}


void	render_door(t_game *game, t_door *d, int x)
{
	int color;
	float pos;
	if (d->timer == 0.0)
    	game->ray.tex_x = (int)(game->ray.ray_x / BLOCK_SIZE) % BLOCK_SIZE;
	else
    	game->ray.tex_x = (int)((game->ray.ray_x / BLOCK_SIZE + (d->timer / 2)) * BLOCK_SIZE) % BLOCK_SIZE;
	pos = (game->ray.start_wall - HEIGHT / 2 + game->ray.height_wall / 2) * game->ray.step;
	while (game->ray.start_wall < game->ray.end_wall)
	{
		game->ray.tex_y = (int)pos % BLOCK_SIZE;
		color = get_pixel_image_door(game, &game->ray);
		put_pixel(x, game->ray.start_wall, color, game);
		pos += game->ray.step;
		game->ray.start_wall++;
	}
}
