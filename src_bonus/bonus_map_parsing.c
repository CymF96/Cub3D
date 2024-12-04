/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_map_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:41 by cofische          #+#    #+#             */
/*   Updated: 2024/12/04 11:09:57 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

//copying map by using a temp map that is increase at every line met
void	copy_map(t_game *game, char *line)
{
	char	**temp_map;
	int		i;

	i = -1;
	game->map_height = 0;
	if (!line || line[0] == '\0')
		ft_exit("line in copy_map() is NULL", game, 1);
	if (game->map != NULL)
		game->map_height = ft_lines_count(game->map);
	temp_map = malloc(sizeof(char *) * (game->map_height + 2));
	if (temp_map == NULL)
		ft_exit("malloc of temp_map in copy_map failed", game, 1);
	while (++i < game->map_height)
		temp_map[i] = game->map[i];
	if (game->map)
		free(game->map);
	game->map = temp_map;
	game->map[i++] = ft_strdup(line);
	if (game->map[game->map_height] == NULL)
		ft_exit("strdup of line in copy_map failed", game, 1);
	game->map[i] = NULL;
}

char	*ft_copy_path(t_game *game, char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != '.')
		i++;
	temp = safe_malloc((ft_strlen(line + i) + 1), game);
	if (temp == NULL)
		ft_exit("Textures infos incorrect", game, 1);
	while (line[i] != '\0' && line[i] != '\n')
		temp[j++] = line[i++];
	temp[j] = '\0';
	i = open(temp, O_RDONLY, 0664);
	if (i < 0)
	{
		free(temp);
		ft_exit("Reading tex file failed", game, 1);
	}
	close(i);
	return (temp);
}

void	ft_copy_color(t_game *game, int *str, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		ft_exit("Empty RGB", game, 1);
	while (line[i] && line[i] != '\n' && j < 3)
	{
		str[j] = 0;
		while (line[i] >= '0' && line[i] <= '9')
			str[j] = str[j] * 10 + (line[i++] - '0');
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != '\n')
			ft_exit("RGB format incorrect", game, 1);
		if (line[i] == ' ')
			i++;
		if (line[i] == ',')
			j++;
		i++;
	}
}

int	texture_info(t_game *game, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		game->no = ft_copy_path(game, line);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		game->so = ft_copy_path(game, line);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		game->we = ft_copy_path(game, line);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		game->ea = ft_copy_path(game, line);
	else if (line[i] == 'F')
	{
		ft_copy_color(game, game->f, line);
		check_color_format(game, game->f);
	}
	else if (line[i] == 'C')
	{
		ft_copy_color(game, game->c, line);
		check_color_format(game, game->c);
	}
	else
		return (0);
	return (1);
}
