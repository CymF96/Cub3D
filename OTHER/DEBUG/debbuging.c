
/*DEBUGGING -- PRINTING MAP FILE INFO*/
// for (int i = 0; game->map[i] != NULL; i++)
// 	printf("%s", game->map[i]);
// printf("\n");
// for (int i = 0; i < 3; i++)
// 	printf("%d, ", game->f[i]);
// printf("\n"); 
// for (int i = 0; i < 3; i++)
// 	printf("%d, ", game->c[i]);
// printf("\n%s\n%s\n%s\n%s\n%s\n", game->no, game->so, game->we, game->ea, game->dr);
/**DEBUGGING -- PRINTING MAP FILE INFO*/


	/*DEBUGGING PRINTING THE PLAYER POSITION AS GREEN SQUARE ON 2D MAP*/
	// game->ray.ray_x = game->player.x;
	// game->ray.ray_y = game->player.y;
	// game->ray.cos_a = cos(game->player.angle);
	// game->ray.sin_a = sin(game->player.angle);

	// while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game))
	// {
	// 	put_pixel(game->ray.ray_x, game->ray.ray_y, 0xFF0000, game);
	// 	game->ray.ray_x += game->ray.cos_a;
	// 	game->ray.ray_y += game->ray.sin_a;
	// }
	/*DEBUGGING PRINTING THE PLAYER POSITION AS GREEN SQUARE ON 2D MAP*/

/*DEBUGGING SHOWING THE MAP ON 2D GRID*/
// void draw_square(int x, int y, int size, int color, t_game *game)
// {
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x + i, y, color, game);
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x, y + i, color, game);
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x + size, y + i, color, game);
// 	for (int i = 0; i < size; i++)
// 		put_pixel(x + i, y + size, color, game);
// }

// void draw_map(t_game *game)
// {
// 	char **map = game->map;
// 	int color = 0x0000FF;
// 	for (int y = 0; map[y]; y++)
// 	{
// 		for (int x = 0; map[y][x]; x++)
// 		{
// 			if (map[y][x] == '1')
// 				draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, color, game);
// 		}
// 	}
// }
/*DEBUGGING SHOWING THE MAP ON 2D GRID*/

	/*DEBUGGING SHOWING THE WALL RENDER ON 3D*/
	// int start_y = (HEIGHT - game->ray.height_wall) / 2;
	// int	end = start_y + game->ray.height_wall;
	// while (start_y < end)
	// {
	// 	put_pixel(i, start_y, 255, game);
	// 	start_y++;
	// }

	/*DEBUGGING SHOWING THE WALL RENDER ON 3D*/
	// while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game) && !hit_door(game->ray.ray_x, game->ray.ray_y, game)) // problem
	// {
		// inscreasing ray movement until getting the wall hit point
		/*DEBUGGING SHOWING THE FOV CAST IN RED*/
		// put_pixel(game->ray.ray_x, game->ray.ray_y, 0xFF0000, game);
		/*DEBUGGING SHOWING THE FOV CAST IN RED*/
		// game->ray.ray_x += cos(ray_angle);
		// game->ray.ray_y += sin(ray_angle);
	// }
