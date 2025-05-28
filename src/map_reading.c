/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:23 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:14:14 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	analyse_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line && line[i] == '1' && game->no && game->so && game->we && \
		game->ea && game->dr && game->f[0] != -1 && game->f[1] != -1 && \
		game->f[2] != -1 && game->c[0] != -1 && \
		game->c[1] != -1 && game->c[2] != -1)
	{
		copy_map(game, line);
		return ;
	}
	else
	{
		texture_info(game, line, i);
		return ;
	}
	if (line[i] != '\0' || line[i] != '\n')
		return ;
}

void	readmap(t_game *game, int fd)
{
	game->line = get_next_line(fd);
	if (game->line == NULL)
		ft_exit("reading the file info failed", game, 1);
	while (game->line && game->line[0] != '\0')
	{
		analyse_line(game, game->line);
		free(game->line);
		game->line = get_next_line(fd);
	}
	free(game->line);
	game->line = NULL;
}

bool	map_format(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '.')
		{
			if (ft_strlen(input + i) == 4 && \
				!ft_strncmp(".cub", input + i, 4) && input[i + 4] == '\0')
				return (true);
		}
		i++;
	}
	return (false);
}

void	check_map_rules(t_game *game)
{
	if (!check_texture(game))
		ft_exit("Info textures incorrect", game, 1);
	find_player_position(game);
	if (game->player_pos != 1)
		ft_exit("Info player incorrect", game, 1);
	init_door_struct(game);
	find_doors_position(game);
	if (!closed_by_walls(game))
		ft_exit("map is not closed/surrounded by walls", game, 1);
	if (!map_info(game->map))
		ft_exit("Info map in wrong format", game, 1);
}

bool	map_validation(t_game *game, char *input)
{
	int	fd;

	if (!map_format(input))
		ft_exit("Map format isn't correct.", game, 1);
	fd = open(input, O_RDONLY);
	if (fd < 0)
		ft_exit("Map file can't be read.", game, 1);
	readmap(game, fd);
	check_map_rules(game);
	return (true);
}
