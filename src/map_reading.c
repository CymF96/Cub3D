/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:23 by cofische          #+#    #+#             */
/*   Updated: 2024/11/29 13:37:13 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*DEBUGGING -- PRINTING MAP FILE INFO*/
	// for (int i = 0; cub->map[i] != NULL; i++)
	// 	printf("%s", cub->map[i]);
	// printf("\n");
	// for (int i = 0; i < 3; i++)
	// 	printf("%d, ", cub->f[i]);
	// printf("\n");
	// for (int i = 0; i < 3; i++) 
	// 	printf("%d, ", cub->c[i]);
	// printf("\n%s\n%s\n%s\n%s\n", cub->no, cub->so, cub->we, cub->ea);
/**DEBUGGING -- PRINTING MAP FILE INFO*/

void	check_map_rules(t_game *cub)
{
	for (int i = 0; cub->map[i] != NULL; i++)
		printf("%s", cub->map[i]);
	printf("\n");
	for (int i = 0; i < 3; i++)
		printf("%d, ", cub->f[i]);
	printf("\n");
	for (int i = 0; i < 3; i++) 
		printf("%d, ", cub->c[i]);
	printf("\n%s\n%s\n%s\n%s\n", cub->no, cub->so, cub->we, cub->ea);
	if (cub->player_pos != 1)
		ft_exit("Information about player position is incorrect", cub, 1);
	if (!closed_by_walls(cub))
		ft_exit("map is not closed/surrounded by walls", cub, 1);
}

//Reading file line by line to parse information in variable
void	readmap(t_game *cub, int fd)
{
	char	*line;
	int		nbr_line;

	nbr_line = 0;
	line = get_next_line(fd);
	if (line == NULL)
		ft_exit("reading the map failed", cub, 1);
	while (line && line[0] != '\0')
	{
		nbr_line++;
		analyse_line(cub, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
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

//find player and convert the position coordinate into screen + set direction for later initialization
void	find_player_position(t_game *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i] != NULL)
	{
		j = 0;
		while (cub->map[i][j] != '\0')
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' \
				|| cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
			{
				cub->player.x = (j + 0.5) * BLOCK_SIZE;
				cub->player.y = (i + 0.5) * BLOCK_SIZE;
				cub->player.direction = cub->map[i][j];
			}
			j++;
		}
		i++;
	}
}

bool	map_validation(t_game *cub, char *input)
{
	int	fd;

	//check if the map is in correct .cub format
	if (!map_format(input))
		ft_exit("Map format isn't correct. \
			Please use .cub only", cub, 1);
	fd = open(input, O_RDONLY);
	if (fd < 0)
		ft_exit("Map file can't be read. \
			Please check the map filename", cub, 1);
	//read the file and add element to correct variable in the structure + setup map char **
	readmap(cub, fd);
	//additionnal map checking 
	check_map_rules(cub);
	// init the player position for raycasting calculation
	find_player_position(cub);
	return (true);
}
