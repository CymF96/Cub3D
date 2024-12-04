/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:29 by cofische          #+#    #+#             */
/*   Updated: 2024/12/04 11:09:18 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2 || av[1] == NULL || av[1][0] == '\0')
		ft_exit("Missing arguments. Format accepted ./cub3D map_name.cub\n", NULL, 1);
	//initializa the main structure and the ray struct for raycasting calculation
	initialization(&game);
	//perform the parsing/checking of the map and texture information
	map_validation(&game, av[1]);
	//start the game and perfom player movement
	start_game(&game);
	//cleaning structure (this is probably never reach as ft_exit is also in cmd to close window (e.g cross and ESC))
	ft_exit("End game", &game, 0);
}
