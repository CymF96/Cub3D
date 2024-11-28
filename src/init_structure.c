#include "cub3d.h"

void	ray_init(t_ray *ray)
{
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->cos_a = 0;
	ray->sin_a = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
	ray->angle = 0;
	ray->dist = 0;
	ray->cos_angle = 0;
	ray->sin_angle = 0;
	ray->height_wall = 0;
	ray->fov = 60;
	ray->start_x = 0;
	ray->step = 0;
	ray->wall_dist = 0;
	ray->start_wall = 0;
	ray->end_wall = 0;
	ray->side = 0;
	ray->tex_id = 0;
	ray->tex_x = 0;
	ray->tex_y = 0;
}

//init texture structure
void	init_texture(t_tex *texture)
{
	texture->img = NULL;
	texture->bpp = 0;
	texture->size_line = 0;
	texture->endian = 0;
	texture->data = NULL;
	texture->width = 0;
	texture->height = 0;
}

void	init_player(t_player *player, t_game *game)
{
	// player->up = false; //not needed in new calculation process but keep it until program is working fine
	// player->down = false;
	// player->right = false;
	// player->left = false;
	// player->exit = false;
	// player->ro_left = false;
	// player->ro_right = false;
	player->speed = 3;
	player->angle_speed = 0.1;
	player->angle = 0;
	player->game = game;
}

void	initialization(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->data = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->bpp = 0;
	game->size_line = 0;
	game->endian = 0;
	game->player_pos = 0;
	ft_memset(game->f, -1, sizeof(game->f));
	ft_memset(game->c, -1, sizeof(game->c));
	ray_init(&game->ray);
}
