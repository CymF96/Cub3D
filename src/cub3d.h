/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:43 by cofische          #+#    #+#             */
/*   Updated: 2024/12/10 12:30:30 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
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
# define LEFT 65361
# define RIGHT 65363

typedef struct s_game	t_game;

typedef struct s_ray
{
	float	ray_x;
	float	ray_y;
	float	delta_x;
	float	delta_y;
	float	tan_angle;
	float	height_wall;
	float	fov;
	float	step;
	float	wall_dist;
	float	hit_x;
	float	hit_y;
	int		start_wall;
	int		end_wall;
	int		side;
	int		tex_id;
	int		tex_x;
	int		tex_y;
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
	bool	ro_left;
	bool	ro_right;
	char	direction;
	t_game	*game;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_tex		*north;
	t_tex		*south;
	t_tex		*west;
	t_tex		*east;
	t_ray		ray;
	t_player	player;
	void		*img;
	int			bpp;
	int			size_line;
	int			endian;
	char		*data;
	int			player_pos;
	char		p_dir;
	char		**map;
	char		*line;
	int			map_height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	int			ceiling_color;
	int			floor_color;
}	t_game;

/*MAP_PARSING*/
bool	map_validation(t_game *game, char *input);
void	check_map_rules(t_game *game);
bool	map_format(char *input);
void	readmap(t_game *game, int fd);
void	analyse_line(t_game *game, char *line);
int		map_info(char **map);
int		check_texture(t_game *game);
int		check_file(char *filename);
int		check_color_format(int *array);
int		closed_by_walls(t_game *game);
void	find_player_position(t_game *game);
int		texture_info(t_game *game, char *line, int i);
void	ft_copy_color(int *str, char *line);
char	*ft_copy_path(t_game *game, char *line);
void	copy_map(t_game *game, char *line);
/*LAUNCHING GAME*/
void	init_game(t_game *game);
void	get_facing_direction(t_player *player, char c);
void	launch_game(t_game *game);
/*PLAYER*/
int		key_press(int keycode, t_player *player);
int		key_release(int keycode, t_player *player);
int		cross_close_window(t_game *cub);
void	rotation(t_player *player);
void	key_movement(t_player *player);
void	move_player(t_player *player);
/*RAYCASTING*/
int		gameloop(t_game *game);
void	calculate_line(t_player *player, t_game *game, float ray_angle, int i);
void	render_wall(t_game *game);
void	wall_direction(t_game *game, float ray_x, float ray_y, float ray_angle);
bool	hit_wall(float px, float py, t_game *game);
/*TEXTURES*/
t_tex	*load_tex(t_game *game, char *texture_file);
int		set_up_color(int *rgb);
int		get_pixel_image(t_game *game, t_ray *ray);
void	put_pixel(int x, int y, int color, t_game *game);
/*DRAW ELEMENTS*/
void	draw_wall(t_game *game, t_ray *ray, int x);
void	draw_ceiling(t_game *game);
void	draw_floor(t_game *game);
/*UTILS*/
void	initialization(t_game *game);
void	init_player(t_player *player, t_game *game);
void	init_texture(t_tex *texture);
void	ray_init(t_ray *ray);
void	clean_map(t_game *game);
void	clear_image(t_game *game);
void	destroy_img(t_game *game);
void	free_textures(t_game *game);
void	free_game_struct(t_game *game);
int		ft_lines_count(char **tab);
void	*safe_malloc(size_t size, t_game *game);
void	clean_game(t_game *game);
void	ft_exit(const char *str, t_game *game, int flag);

#endif
