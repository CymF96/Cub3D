#include "cub3d.h"

bool	closed_by_walls(t_game *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map[++i] != NULL)
	{
		j = -1;
		while (cub->map[i][++j] != '\0')
		{
			if (i == 0 && cub->map[i][j] == '0')
				return (false);
			else if (cub->map[i + 1] == NULL && cub->map[i][j] == '0')
				return (false);
			else if (cub->map[i][j] == ' ')
			{
				if (i != 0 && cub->map[i - 1][j] == '0')
					return (false);
				else if (cub->map[i + 1] != NULL \
						&& cub->map[i + 1][j] == '0')
					return (false);
			}
		}
	}
	return (true);
}

void	check_color_format(t_game *cub, int	*array)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (array[i] < 0 || array[i] > 255)
			ft_exit("RGB format incorrect, please enter color \
				format in RGB (between 0 and 255)", cub);
		i++;
	}
}

void	case_with_1(t_game *cub, char *line, int i)
{
	int	j;

	j = i + 1;
	while (line[j] != '\0' && line[j] == ' ')
	{
		j++;
		if (line[j] != '1' && line[j] != '\n' \
			&& line[j] != ' ' && line[j] != '\0')
			ft_exit("map is not closed/surrounded by walls", cub);
	}
}

void	map_identifiers(t_game *cub, char *line, int i)
{
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			case_with_1(cub, line, i);
		else if (line[i] == '\0')
			break ;
		else if (line[i] == '0')
		{
			if (line[i + 1] == '\n' || line[i + 1] == '\0' \
				|| line[i + 1] == ' ')
				ft_exit("map is not closed/surrounded by walls", cub);
		}
		else if (line[i] == 'N' || line[i] == 'S' \
					|| line[i] == 'W' || line[i] == 'E')
			cub->player_pos++;
		else if (line[i] != ' ' && line[i] != '\n')
			ft_exit("map identifier not recognised, please \
				used only 1, 0 or N/S/W/E", cub);
		i++;
	}
	copy_map(cub, line);
}

void	analyse_line(t_game *cub, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (texture_info(cub, line, i))
		return ;
	if (line[i] == '1' && cub->no && cub->so && cub->we && \
			cub->ea && cub->f[0] != -1 && cub->f[1] != -1 && \
			cub->f[2] != -1 && cub->c[0] != -1 && \
			cub->c[1] != -1 && cub->c[2] != -1)
	{
		map_identifiers(cub, line, i);
		return ;
	}
	else if (line[i] == '\n')
		return ;
	else if (line[i] == '0')
		ft_exit("map is not closed/surrounded by walls", cub);
	else
		ft_exit("A format error has been encountered in the map file", cub);
	return ;
}
