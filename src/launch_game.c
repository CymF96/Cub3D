/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:15:55 by cofische          #+#    #+#             */
/*   Updated: 2025/05/28 11:14:27 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_exit("mlx_init failed", game, 1);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	if (game->win == NULL)
		ft_exit("mlx_win failed", game, 1);
	game->floor_color = set_up_color(game->f);
	game->ceiling_color = set_up_color(game->c);
	game->north = load_tex(game, game->no);
	game->south = load_tex(game, game->so);
	game->west = load_tex(game, game->we);
	game->east = load_tex(game, game->ea);
	game->door = load_tex(game, game->dr);
	game->gun1 = load_tex(game, "textures/gun/gun_1.xpm");
	game->gun2 = load_tex(game, "textures/gun/gun_2.xpm");
	game->shot1 = load_tex(game, "textures/gun/shot_1.xpm");
}

void	get_facing_direction(t_player *player, char c)
{
	if (c == 'N')
		player->angle = (3 * PI) / 2;
	else if (c == 'S')
		player->angle = PI / 2;
	else if (c == 'W')
		player->angle = PI;
	else if (c == 'E')
		player->angle = 0;
}

void	launch_game(t_game *game)
{
	init_game(game);
	init_player(&game->player, game);
	get_facing_direction(&game->player, game->player.direction);
	mlx_hook(game->win, 17, 0, cross_close_window, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, &game->player);
	mlx_hook(game->win, 3, 1L << 1, key_release, &game->player);
	mlx_mouse_hook(game->win, handle_shoot, game);
	mlx_mouse_move(game->mlx, game->win, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(game->mlx, gameloop, game);
	mlx_loop(game->mlx);
}
