#include "cub3d.h"

void draw_tile(int x, int y, int mini_tile, int color, t_game *game)
{
	int dx;
	int dy;

	dx = 0;
	while (dx < mini_tile)
	{
		dy = 0;
		while (dy < mini_tile)
		{
			put_pixel(x + dx, y + dy, color, game);
			dy++;
		}
		dx++;
	}
}

int get_tile_color(char tile_type)
{
	if (tile_type == '1')
		return (0xFFFFFF);
	else if (tile_type == '0' || tile_type == 'N' || tile_type == 'S' ||
			 tile_type == 'E' || tile_type == 'W')
		return (0x444444);
	return (0);
}

void draw_map_tiles(t_game *game, int mini_tile, int mini_x, int mini_y)
{
	int i;
	int j;
	int x;
	int y;
	int color;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			x = mini_x + j * mini_tile;
			y = mini_y + i * mini_tile;
			color = get_tile_color(game->map[i][j]);
			draw_tile(x, y, mini_tile, color, game);
		}
	}
}

void draw_player_dot(t_game *game, int player_x, int player_y)
{
	int dx;
	int dy;

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

void draw_direction_line(t_game *game, int player_x, int player_y, int dir_x, int dir_y)
{
	int i;

	i = 0;
	while (i < 5)
	{
		put_pixel(player_x + (dir_x - player_x) * i / 5,
				  player_y + (dir_y - player_y) * i / 5,
				  0xFFFF00, game);
		i++;
	}
}

void draw_minimap(t_game *game)
{
	int mini_tile;
	int mini_x;
	int mini_y;
	int player_x;
	int player_y;
	int dir_x;
	int dir_y;

	mini_tile = 8;
	mini_x = WIDTH - 100;
	mini_y = HEIGHT - 70;

	draw_map_tiles(game, mini_tile, mini_x, mini_y);

	player_x = mini_x + (game->player.x / BLOCK_SIZE) * mini_tile;
	player_y = mini_y + (game->player.y / BLOCK_SIZE) * mini_tile;
	draw_player_dot(game, player_x, player_y);

	dir_x = player_x + cos(game->player.angle) * 5;
	dir_y = player_y + sin(game->player.angle) * 5;
	draw_direction_line(game, player_x, player_y, dir_x, dir_y);
}
