/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:29 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 12:08:06 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2 || av[1] == NULL || av[1][0] == '\0')
		ft_exit("Missing arguments. Format: ./cub3D map_name.cub\n", NULL, 1);
	initialization(&game);
	map_validation(&game, av[1]);
	launch_game(&game);
	ft_exit("End game", &game, 0);
}
