/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:43 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 16:08:12 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CUB3D_H
# define BONUS_CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1600
# define HEIGHT 1000
# define BLOCK_SIZE 64
# define STEP_SIZE 0.25
# define MOUSE_SEN 0.015
# define PI 3.14159265359
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define E 101
# define LEFT 65361
# define RIGHT 65363
# define DOOR_TIMEOUT 10

typedef struct s_game	t_game;

typedef struct s_door
{
	float			x;
	float			y;
	bool			open;
	struct timeval	open_time;	
}	t_door;

typedef struct s_ray
{
	float	ray_x;
	float	ray_y;
	float	delta_x;
	float	delta_y;
	float	tan_angle;
	float	hit_x;
	float	hit_y;
	float	height_wall;
	float	fov;
	float	step;
	float	wall_dist;
	float	pos;
	int		color;
	int		start_wall;
	int		end_wall;
	int		side;
	int		tex_id;
	int		tex_x;
	int		tex_y;
	int		map_x;
	int		map_y;
}	t_ray;

typedef struct s_tex
{
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	int		width;
	int		height;
}	t_tex;

typedef struct s_player
{
	float	x;
	float	y;
	float	new_x;
	float	new_y;
	int		speed;
	float	angle;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;
	float	angle_direction;
	bool	up;
	bool	down;
	bool	right;
	bool	left;
	bool	exit;
	bool	door;
	bool	shot;
	bool	ro_left;
	bool	ro_right;
	char	direction;
	t_game	*game;
}	t_player;

typedef struct s_mini
{
	int	m_tile;
	int	m_x;
	int	m_y;
	int	m_player_x;
	int	m_player_y;
	int	m_dir_x;
	int	m_dir_y;
	int	m_color;
}	t_mini;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_tex			*north;
	t_tex			*south;
	t_tex			*west;
	t_tex			*east;
	t_tex			*door;
	t_tex			*gun1;
	t_tex			*gun2;
	t_tex			*shot1;
	t_ray			ray;
	t_player		player;
	t_door			**d;
	t_mini			m_map;
	int				nbr_doors;
	int				d_index;
	int				gun_frame;
	struct timeval	last_frame_time;
	double			accumulated_time;
	int				gun_x_start;
	int				gun_y_start;
	int				gun_color;
	void			*img;
	int				bpp;
	int				size_line;
	int				endian;
	float			mouse_delta_x;
	int				last_mouse_x;
	char			*data;
	int				player_pos;
	char			p_dir;
	char			**map;
	char			*line;
	int				map_height;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*dr;
	int				f[3];
	int				c[3];
	int				ceiling_color;
	int				floor_color;
}	t_game;

/*MAP_PARSING*/
bool	map_validation(t_game *game, char *input);
void	check_map_rules(t_game *game);
bool	map_format(char *input);
void	readmap(t_game *game, int fd);
void	analyse_line(t_game *game, char *line);
int		texture_info(t_game *game, char *line, int i);
void	copy_color(int *str, char *line);
char	*copy_path(t_game *game, char *line);
void	copy_map(t_game *game, char *line);
int		map_info(char **map);
int		check_texture(t_game *game);
int		check_file(char *filename);
int		check_color_format(int *array);
bool	closed_by_walls(t_game *game);
void	init_door_struct(t_game *game);
void	find_player_position(t_game *game);
void	find_doors_position(t_game *game);
/*LAUNCHING GAME*/
void	launch_game(t_game *game);
void	get_facing_direction(t_player *player, char c);
void	init_game(t_game *game);
/*PLAYER*/
void	move_player(t_player *player);
void	key_movement(t_player *player);
void	new_coordinates(t_player *player, float new_x, float new_y);
void	rotation(t_player *player);
int		cross_close_window(t_game *cub);
int		key_release(int keycode, t_player *player);
int		key_press(int keycode, t_player *player);
int		handle_shoot(int button, int x, int y, t_game *game);
void	mouse_move(t_game *game);
/*SPRITES*/
void	door_init(t_door *d);
int		find_door_index(t_game *game, int x, int y);
bool	hit_door(float px, float py, t_game *game);
void	door_movement(t_game *game, t_player *player);
void	check_door_timeout(t_game *game);
void	draw_gun(t_game *game);
void	update_gun_frame(t_game *game);
int		get_pixel_image_gun(t_tex *temp, int x, int y);
void	load_gun_img(t_game *game);
/*RAYCASTING*/
int		gameloop(t_game *game);
void	render_wall(t_game *game);
void	draw_line(t_player *player, t_game *game, float ray_angle, int x);
void	wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle);
bool	hit_wall(float px, float py, t_game *game);
/*TEXTURES*/
int		get_pixel_image_door(t_game *game, t_ray *ray);
int		get_pixel_image(t_game *game, t_ray *ray);
void	put_pixel(int x, int y, int color, t_game *game);
void	init_texture(t_tex *texture);
int		set_up_color(int *rgb);
t_tex	*load_tex(t_game *game, char *texture_file);
/*MINIMAP*/
void	draw_tile(int x, int y, t_mini *m, t_game *game);
int		get_tile_color(char tile_type);
void	draw_map_tiles(t_game *game, t_mini *m);
void	draw_player_dot(t_game *game, int player_x, int player_y);
void	draw_minimap(t_game *game, t_mini *m);
/*DRAW ELEMENTS*/
void	draw_wall(t_game *game, t_ray *r, int x);
void	draw_floor(t_game *game);
void	draw_ceiling(t_game *game);
/*UTILS*/
void	ray_init(t_ray *ray);
void	init_player(t_player *player, t_game *game);
void	map_init(t_mini *m);
void	initialization_bis(t_game *game);
void	initialization(t_game *game);
int		ft_lines_count(char **tab);
void	*safe_malloc(size_t size, t_game *game);
void	clean_game(t_game *game);
void	ft_exit(const char *str, t_game *game, int flag);
long	get_time_in_seconds(void);
void	clean_doors(t_game *game);
void	free_textures(t_game *game);
void	clean_map(t_game *game);
void	clear_image(t_game *game);
void	destroy_img_bis(t_game *game);
void	destroy_img(t_game *game);
void	free_game_struct(t_game *game);

#endif
