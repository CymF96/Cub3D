/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:41 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:14:18 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map(t_game *game, char *line)
{
	char	**temp_map;
	int		i;

	i = -1;
	game->map_height = 0;
	if (!line || line[0] == '\0')
		return ;
	if (game->map != NULL)
		game->map_height = ft_lines_count(game->map);
	temp_map = malloc(sizeof(char *) * (game->map_height + 2));
	if (temp_map == NULL)
		return ;
	while (++i < game->map_height)
		temp_map[i] = game->map[i];
	if (game->map)
		free(game->map);
	game->map = temp_map;
	game->map[i++] = ft_strdup(line);
	if (game->map[game->map_height] == NULL)
		return ;
	game->map[i] = NULL;
}

char	*copy_path(t_game *game, char *line)
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
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		temp[j++] = line[i++];
	temp[j] = '\0';
	return (temp);
}

void	copy_color(int *str, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return ;
	while (line[i] && line[i] != '\n' && j < 3)
	{
		str[j] = 0;
		while (line[i] >= '0' && line[i] <= '9')
			str[j] = str[j] * 10 + (line[i++] - '0');
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != '\n')
			return ;
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
		game->no = copy_path(game, line);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		game->so = copy_path(game, line);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		game->we = copy_path(game, line);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		game->ea = copy_path(game, line);
	else if (line[i] == 'D' && line[i + 1] == 'O' && line[i + 2] == ' ')
		game->dr = copy_path(game, line);
	else if (line[i] == 'F')
		copy_color(game->f, line);
	else if (line[i] == 'C')
		copy_color(game->c, line);
	else
		return (0);
	return (1);
}
