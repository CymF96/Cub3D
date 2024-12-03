/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:38 by cofische          #+#    #+#             */
/*   Updated: 2024/12/03 12:33:29 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	closed_by_walls(t_game *game)
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
				return (false);
			else if (game->map[i + 1] == NULL && game->map[i][j] == '0')
				return (false);
			else if (game->map[i][j] == ' ')
			{
				if (i != 0 && game->map[i - 1][j] == '0')
					return (false);
				else if (game->map[i + 1] != NULL \
						&& game->map[i + 1][j] == '0')
					return (false);
			}
		}
	}
	return (true);
}

void	check_color_format(t_game *game, int	*array)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (array[i] < 0 || array[i] > 255)
			ft_exit("RGB format incorrect", game, 1);
		i++;
	}
}

void	case_with_1(t_game *game, char *line, int i)
{
	int	j;

	j = i + 1; // got to the second char. If not 
	while (line[j] != '\0' && line[j] == ' ')
	{
		j++;
		if (line[j] != '1' && line[j] != '\n' \
			&& line[j] != ' ' && line[j] != '\0')
			ft_exit("map is not closed/surrounded by walls", game, 1);
	}
}

//check if the line is a wall map and so if there is only 1 // check also correct id char
void	map_identifiers(t_game *game, char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			case_with_1(game, line, i);
		else if (line[i] == '\0')
			break ;
		else if (line[i] == '0')
		{
			if (line[i + 1] == '\n' || line[i + 1] == '\0' \
				|| line[i + 1] == ' ')
				ft_exit("map is not closed/surrounded by walls", game, 1);
		}
		else if (line[i] == 'N' || line[i] == 'S' \
					|| line[i] == 'W' || line[i] == 'E')
			game->player_pos++;
		else if (line[i] != ' ' && line[i] != '\n')
			ft_exit("Wrong map token", game, 1);
		i++;
	}
	copy_map(game, line);
}

//main function to analyse the input from gnl
void	analyse_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ') //as long as there is space and it is not the end of the line continue
		i++;
	if (texture_info(game, line, i)) // checking if we got a texture information like nroth path or ceiling rgb color 
		return ;
	if (line && line[i] == '1' && game->no && game->so && game->we && \
			game->ea && game->f[0] != -1 && game->f[1] != -1 && \
			game->f[2] != -1 && game->c[0] != -1 && \
			game->c[1] != -1 && game->c[2] != -1)
	{
		map_identifiers(game, line, i); // if the line start by 1, we are entering the map parsing step so additional check in map id
		return ;
	}
	else if (line[i] == '\n')
		return ;
	else if (line[i] == '0')
		ft_exit("map is not closed/surrounded by walls", game, 1); // as we always check the 1st element of the line (after the texture info) it most be either a space or a 1, if a 0 is meat then the walls are not closed
	else
		ft_exit("File format is wrong", game, 1); // any other char is an error
	return ;
}
