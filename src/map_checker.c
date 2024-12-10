/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:38 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 11:57:55 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	closed_by_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i] != NULL)
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (i == 0 && game->map[i][j] == '0')
				return (0);
			else if (game->map[i + 1] == NULL && game->map[i][j] == '0')
				return (0);
			else if (game->map[i][j] == ' ')
			{
				if (i != 0 && game->map[i - 1][j] == '0')
					return (0);
				else if (game->map[i + 1] != NULL \
						&& game->map[i + 1][j] == '0')
					return (0);
			}
		}
	}
	return (1);
}

int	check_color_format(int *array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (i < 3)
	{
		if (array[i] < 0 || array[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	check_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0664);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_texture(t_game *game)
{
	if (!game->no || !game->so || !game->we || ! game->ea)
		return (0);
	else if (!check_file(game->no) || !check_file(game->so) \
			|| !check_file(game->we) || !check_file(game->ea))
		return (0);
	else if (!check_color_format(game->c) || !check_color_format(game->f))
		return (0);
	else
		return (1);
}

int	map_info(char **map)
{
	int	i;
	int	j;

	i = -1;
	if (!map)
		return (0);
	while (map[++i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (map[i][j] != ' ' && map[i][j] != '0' \
				&& map[i][j] != '1' && map[i][j] != 'N' \
				&& map[i][j] != 'S' && map[i][j] != 'W' \
				&& map[i][j] != 'E')
				return (0);
			j++;
		}
	}
	return (1);
}
