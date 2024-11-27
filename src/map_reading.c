#include "cub3d.h"

/*TEST PURPOSE
	for (int i = 0; cub->map[i] != NULL; i++)
		printf("%s", cub->map[i]);
	printf("\n");
	for (int i = 0; i < 3; i++)
		printf("%d, ", cub->f[i]);
	printf("\n");
	for (int i = 0; i < 3; i++) 
		printf("%d, ", cub->c[i]);
	printf("\n%s\n%s\n%s\n%s\n", cub->no, cub->so, cub->we, cub->ea);
*/

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
	printf("player_pos: %d\n", cub->player_pos);
	if (cub->player_pos != 1)
		ft_exit("Information about player position is incorrect", cub, 1);
	if (!closed_by_walls(cub))
		ft_exit("map is not closed/surrounded by walls", cub, 1);
}

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
				cub->player.x = j + 0.5;
				cub->player.y = i + 0.5;
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

	if (!map_format(input))
		ft_exit("Map format isn't correct. \
			Please use .cub only", cub, 1);
	fd = open(input, O_RDONLY);
	if (fd < 0)
		ft_exit("Map file can't be read. \
			Please check the map filename", cub, 1);
	readmap(cub, fd);
	check_map_rules(cub);
	find_player_position(cub);
	return (true);
}
