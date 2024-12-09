/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_reading.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:23 by cofische          #+#    #+#             */
/*   Updated: 2024/12/09 10:36:28 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

/*DEBUGGING -- PRINTING MAP FILE INFO*/
// for (int i = 0; game->map[i] != NULL; i++)
// 	printf("%s", game->map[i]);
// printf("\n");
// for (int i = 0; i < 3; i++)
// 	printf("%d, ", game->f[i]);
// printf("\n"); 
// for (int i = 0; i < 3; i++)
// 	printf("%d, ", game->c[i]);
// printf("\n%s\n%s\n%s\n%s\n%s\n", game->no, game->so, game->we, game->ea, game->dr);
/**DEBUGGING -- PRINTING MAP FILE INFO*/


void	analyse_line(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ') //as long as there is space and it is not the end of the line continue
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
	{
		game->flag = true;
		return ;
	} // checking if we got a texture information like nroth path or ceiling rgb color 
}

// Reading file line by line to parse information in variable
void readmap(t_game *game, int fd)
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

bool map_format(char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '.')
		{
			if (ft_strlen(input + i) == 4 &&
				!ft_strncmp(".cub", input + i, 4) && input[i + 4] == '\0')
				return (true);
		}
		i++;
	}
	return (false);
}
// find player and convert the position coordinate into screen + set direction for later initialization
bool map_validation(t_game *game, char *input)
{
	int fd;

	// check if the map is in correct .cub format
	if (!map_format(input))
		ft_exit("Map format isn't correct.", game, 1);
	fd = open(input, O_RDONLY);
	if (fd < 0)
		ft_exit("Map file can't be read.", game, 1);
	// read the file and add element to correct variable in the structure + setup map char **
	readmap(game, fd);
	// additionnal map checking
	check_map_rules(game);
	// init the player position for raycasting calculation
	return (true);
}
