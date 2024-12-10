/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:46:58 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 14:49:30 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

void	init_door_struct(t_game *game)
{
	int	i;

	game->d = malloc(sizeof(t_door *) * (game->nbr_doors + 1));
	if (game->d == NULL)
		ft_exit("Init door struct failed", game, 1);
	i = 0;
	while (i < game->nbr_doors)
	{
		game->d[i] = malloc(sizeof(t_door));
		if (game->d[i] == NULL)
			ft_exit("Malloc door failed", game, 1);
		door_init(game->d[i]);
		i++;
	}
	game->d[i] = NULL;
}

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->map)
		ft_exit("Map not generated", game, 1);
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' \
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				game->player.x = (j + 0.5) * BLOCK_SIZE;
				game->player.y = (i + 0.5) * BLOCK_SIZE;
				game->player.direction = game->map[i][j];
				game->player_pos++;
			}
			else if (game->map[i][j] == 'D')
				game->nbr_doors++;
			j++;
		}
		i++;
	}
}

void	find_doors_position(t_game *game)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	while (game->map[++y] && game->d[i] != NULL)
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'D')
			{
				game->d[i]->x = (x + 0.5) * BLOCK_SIZE;
				game->d[i]->y = (y + 0.5) * BLOCK_SIZE;
				i++;
			}
		}
	}
}
