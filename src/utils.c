/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:52 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:13:39 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_lines_count(char **tab)
{
	int	lines;

	lines = 0;
	if (!tab[lines])
		return (lines);
	while (tab[lines] != NULL)
		lines++;
	return (lines);
}

void	*safe_malloc(size_t size, t_game *game)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ft_exit("malloc failed", game, 1);
	return (ptr);
}

void	clean_game(t_game *game)
{
	if (game->line != NULL)
		free(game->line);
	if (game->map != NULL)
		clean_map(game);
	if (game->d != NULL)
		clean_doors(game);
	if (game->north || game->south \
		|| game->west || game->east)
		destroy_img(game);
	free_textures(game);
	free_game_struct(game);
	game = NULL;
}

void	ft_exit(const char *str, t_game *game, int flag)
{
	if (str != NULL)
		printf("Error:\n%s\n", str);
	if (game != NULL)
		clean_game(game);
	if (flag == 1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

long	get_time_in_seconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec);
}
