/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_bonus_map_reading.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:23 by cofische          #+#    #+#             */
/*   Updated: 2024/12/05 13:17:08 by cofische         ###   ########.fr       */
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

// void check_map_rules(t_game *game)
// {
// 	if (game->player_pos != 1)
// 		ft_exit("Info player incorrect", game, 1);
// 	if (!closed_by_walls(game))
// 		ft_exit("map is not closed/surrounded by walls", game, 1);
// }

// Reading file line by line to parse information in variable
// void readmap(t_game *game, int fd)
// {
// 	game->line = get_next_line(fd);
// 	if (game->line == NULL)
// 		ft_exit("reading the file info failed", game, 1);
// 	while (game->line && game->line[0] != '\0')
// 	{
// 		analyse_line(game, game->line);
// 		free(game->line);
// 		game->line = get_next_line(fd);
// 	}
// 	free(game->line);
// 	game->line = NULL;
// }

// bool map_format(char *input)
// {
// 	int i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '.')
// 		{
// 			if (ft_strlen(input + i) == 4 &&
// 				!ft_strncmp(".cub", input + i, 4) && input[i + 4] == '\0')
// 				return (true);
// 		}
// 		i++;
// 	}
// 	return (false);
// }

// find player and convert the position coordinate into screen + set direction for later initialization
// void find_player_position(t_game *game)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (game->map[i] != NULL)
// 	{
// 		j = 0;
// 		while (game->map[i][j] != '\0')
// 		{
// 			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' \
// 				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
// 			{
// 				game->player.x = (j + 0.5) * BLOCK_SIZE;
// 				game->player.y = (i + 0.5) * BLOCK_SIZE;
// 				game->player.direction = game->map[i][j];
// 			}
// 			else if (game->map[i][j] == 'D')
// 			{
// 				game->d.x = (j + 0.5) * BLOCK_SIZE;
// 				game->d.y = (i + 0.5) * BLOCK_SIZE;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// bool map_validation(t_game *game, char *input)
// {
// 	int fd;

// 	// check if the map is in correct .cub format
// 	if (!map_format(input))
// 		ft_exit("Map format isn't correct.", game, 1);
// 	fd = open(input, O_RDONLY);
// 	if (fd < 0)
// 		ft_exit("Map file can't be read.", game, 1);
// 	// read the file and add element to correct variable in the structure + setup map char **
// 	readmap(game, fd);
// 	find_player_position(game);
// 	// additionnal map checking
// 	check_map_rules(game);
// 	// init the player position for raycasting calculation
	
// 	return (true);
}
