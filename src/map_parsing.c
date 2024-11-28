#include "cub3d.h"

void	copy_map(t_game *cub, char *line)
{
	char	**temp_map;
	int		i;

	i = -1;
	cub->map_height = 0;
	if (!line || line[0] == '\0')
		ft_exit("line in copy_map() is NULL", cub, 1);
	if (cub->map != NULL)
		cub->map_height = ft_lines_count(cub->map);
	temp_map = malloc(sizeof(char *) * (cub->map_height + 2));
	if (temp_map == NULL)
		ft_exit("malloc of temp_map in copy_map failed", cub, 1);
	while (++i < cub->map_height)
		temp_map[i] = cub->map[i];
	if (cub->map)
		free(cub->map);
	cub->map = temp_map;
	cub->map[i++] = ft_strdup(line);
	if (cub->map[cub->map_height] == NULL)
		ft_exit("strdup of line in copy_map failed", cub, 1);
	cub->map[i] = NULL;
}

char	*ft_copy_path(t_game *cub, char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '.')
		i++;
	temp = safe_malloc((ft_strlen(line + i) + 1), cub);
	while (line[i] != '\0' && line[i] != '\n')
		temp[j++] = line[i++];
	temp[j] = '\0';
	return (temp);
}

void	ft_copy_color(t_game *cub, int *str, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	while (line[i] && j < 3)
	{
		str[j] = 0;
		while (line[i] >= '0' && line[i] <= '9')
			str[j] = str[j] * 10 + (line[i++] - '0');
		j++;
		while (line[i] != '\0' && line[i] != '\n' && line[i] != ',')
		{
			if (!ft_isdigit(line[i]))
				ft_exit("color identifier is incorrect", cub, 1);
			i++;
		}
		i++;
	}
}

int	texture_info(t_game *cub, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		cub->no = ft_copy_path(cub, line);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		cub->so = ft_copy_path(cub, line);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		cub->we = ft_copy_path(cub, line);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		cub->ea = ft_copy_path(cub, line);
	else if (line[i] == 'F' && line[i + 1] == ' ')
	{
		ft_copy_color(cub, cub->f, line);
		check_color_format(cub, cub->f);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		ft_copy_color(cub, cub->c, line);
		check_color_format(cub, cub->c);
	}
	else
		return (0);
	return (1);
}
