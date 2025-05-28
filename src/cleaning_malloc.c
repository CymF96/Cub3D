/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:31:37 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:15:18 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_doors(t_game *game)
{
	int	i;

	i = 0;
	while (game->d[i])
		free(game->d[i++]);
	free(game->d);
	game->d = NULL;
}

void	free_textures(t_game *game)
{
	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	if (game->ea)
		free(game->ea);
	if (game->dr)
		free(game->dr);
}

void	clean_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
}
