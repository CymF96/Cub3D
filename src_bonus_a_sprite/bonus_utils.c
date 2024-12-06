/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:52 by cofische          #+#    #+#             */
/*   Updated: 2024/12/04 11:10:44 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

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
