/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:10:11 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 16:27:27 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_cub3d.h"
#include <stdio.h>

void	draw_tile(int x, int y, t_mini *m, t_game *game)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < m->m_tile)
	{
		dy = 0;
		while (dy < m->m_tile)
		{
			put_pixel(x + dx, y + dy, m->m_color, game);
			dy++;
		}
		dx++;
	}
}

int	get_tile_color(char tile_type)
{
	if (tile_type == '1')
		return (0xFFFFFF);
	else if (tile_type == '0' || tile_type == 'N' || tile_type == 'S' \
			|| tile_type == 'E' || tile_type == 'W')
		return (0x444444);
	else if (tile_type == 'D')
		return (0x50E0FF);
	return (0);
}

void	draw_map_tiles(t_game *game, t_mini *m)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			x = m->m_x + j * m->m_tile;
			y = m->m_y + i * m->m_tile;
			m->m_color = get_tile_color(game->map[i][j]);
			draw_tile(x, y, m, game);
		}
	}
}

void	draw_player_dot(t_game *game, int player_x, int player_y)
{
	int	dx;
	int	dy;

	dx = -2;
	while (dx <= 2)
	{
		dy = -2;
		while (dy <= 2)
		{
			put_pixel(player_x + dx, player_y + dy, 0xFF0000, game);
			dy++;
		}
		dx++;
	}
}

void	draw_minimap(t_game *game, t_mini *m)
{
	int	i;

	i = 0;
	draw_map_tiles(game, m);
	m->m_player_x = m->m_x + (game->player.x / BLOCK_SIZE) * m->m_tile;
	m->m_player_y = m->m_y + (game->player.y / BLOCK_SIZE) * m->m_tile;
	draw_player_dot(game, m->m_player_x, m->m_player_y);
	m->m_dir_x = m->m_player_x + cos(game->player.angle) * 5;
	m->m_dir_y = m->m_player_y + sin(game->player.angle) * 5;
	while (i < 5)
	{
		put_pixel(m->m_player_x + (m->m_dir_x - m->m_player_x) * i / 5, \
				m->m_player_y + (m->m_dir_y - m->m_player_y) * i / 5, \
				0xFFFF00, game);
		i++;
	}
}
