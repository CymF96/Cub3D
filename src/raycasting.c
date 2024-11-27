# include "cub3d.h"

int	set_up_color(int *rgb)
{
	int	color;
	int	r;
	int g;
	int b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	color = (r << 16 | g << 8 | b);
	return (color);
}

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = HEIGHT / 2 - 1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel_rgb(x, y, game->f, game);
	}
}

void	draw_ceiling(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			put_pixel_rgb(x, y, game->c, game);
	}
}

void	put_pixel_rgb(int x, int y, int *rgb, t_game *game)
{
	int index;
	int color;

	color = set_up_color(rgb);
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	int index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->data[index] = color & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

int	get_pixel_image(t_game *game, t_ray *ray)
{
	char	*pixel;

	if (ray->tex_id == 0)
		game->tex_wall = load_tex(game, game->no);
	else if (ray->tex_id == 1)
		game->tex_wall = load_tex(game, game->so);
	else if (ray->tex_id == 2)
		game->tex_wall = load_tex(game, game->we);
	else if (ray->tex_id == 3)
		game->tex_wall = load_tex(game, game->ea);
	else
		return (1);
	ray->tex_x = ray->tex_x % game->tex_wall->width;
	ray->tex_y = ray->tex_y % game->tex_wall->height;
	if (ray->tex_x >= 0 && ray->tex_x < game->tex_wall->width && ray->tex_y >= 0 && ray->tex_y < game->tex_wall->height)
	{
		pixel = game->tex_wall->data + (ray->tex_y * game->tex_wall->size_line + ray->tex_x * (game->tex_wall->bpp / 8));
		return (*(int *)pixel);
	}
	return (0);
}

bool	hit_wall(float px, float py, t_game *game)
{
	int x;
	int y;

	x = px / BLOCK_SIZE;
	y = py / BLOCK_SIZE;
	if (x < 0 || y < 0 || x >= WIDTH || y <= HEIGHT)
		return true;
	else if (game->map[y][x] == '1')
		return true;
	return false;
}

float	distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float	fix_distance(float x1, float y1, float x2, float y2, t_game *game)
{
	float wall_dist;

    game->ray.delta_x = x2 - x1;
	game->ray.delta_y = y2 - y1;
	game->ray.angle = atan2(game->ray.delta_y, game->ray.delta_x) - game->player.angle;
	wall_dist = distance(game->ray.delta_x, game->ray.delta_y) * cos(game->ray.angle);
	return (wall_dist);
}

void	wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle)
{
	int	side_x;
	int	side_y;

	if (cos(ray_angle) > 0)
		side_x = 1;
	if (sin(ray_angle) > 0)
		side_y = 1;
	if (hit_wall(ray_x - side_x, ray_y, game) || hit_wall(ray_x - side_x, ray_y - side_y, game))
	{
		game->ray.tex_x = (int)ray_x % BLOCK_SIZE;
		game->ray.tex_id = 3;
		if (side_y == 1)
			game->ray.tex_id = 0;
	}
	else if (hit_wall(ray_x, ray_y - side_y, game) || hit_wall(ray_x, ray_y, game))
	{
		game->ray.tex_x = (int)ray_y % BLOCK_SIZE;
		game->ray.tex_id = 2;
		if (side_x == 1)
			game->ray.tex_id = 1;	
	}
}

void	render_wall(t_game *game, t_ray *ray, int i)
{
	int	color;

	ray->step = BLOCK_SIZE / ray->height_wall;
	if (ray->height_wall > HEIGHT)
	{
		ray->tex_y = (ray->height_wall - HEIGHT) * ray->step / 2;
		ray->height_wall = HEIGHT;
	}
	ray->start_wall = (HEIGHT - ray->height_wall) / 2;
	ray->end_wall = game->ray.start_wall + game->ray.height_wall;
	while (game->ray.start_wall < game->ray.end_wall)
	{
		color = get_pixel_image(game, &game->ray);
		put_pixel(i, ray->start_wall, color, game);
		ray->tex_y += ray->step;
		ray->start_wall++;
	}
}


void	draw_line(t_player *player, t_game *game, float ray_angle, int i)
{
	game->ray.cos_angle = cos(ray_angle);
	game->ray.sin_angle = sin(ray_angle);
	game->ray.ray_x = player->x;
	game->ray.ray_y = player->y;
	while (!hit_wall(game->ray.ray_x, game->ray.ray_y, game))
	{
		game->ray.ray_x += game->ray.cos_angle;
		game->ray.ray_y += game->ray.sin_angle;
	}
	wall_direction(game, game->ray.ray_x, game->ray.ray_y, ray_angle);
	game->ray.wall_dist = fix_distance(player->x, player->y, game->ray.ray_x, game->ray.ray_y, game);
	game->ray.height_wall = (BLOCK_SIZE / game->ray.wall_dist) * (WIDTH / 2);
	render_wall(game, &game->ray, i);
}

void	draw_wall(t_game *game)
{
	t_player	*player;
	t_ray		*ray;
	int			i;
	float		start_angle;
	float		ray_angle;

	player = &game->player;
	ray = &game->ray;
	ray->fov = 60 * PI / 180;
	start_angle = player->angle - ray->fov / 2.0;
	i = -1;
	while (++i < WIDTH)
	{
		ray_angle = start_angle + ((float)i / WIDTH) * ray->fov;
		draw_line(player, game, ray_angle, i);
	}
}

int	draw_game(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	draw_floor(game);
	draw_ceiling(game);
	draw_wall(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	mlx_destroy_image(game->mlx, game->img);
	move_player(&game->player);
	return (0);
}