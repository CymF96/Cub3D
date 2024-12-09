/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofische <cofische@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:21:43 by cofische          #+#    #+#             */
/*   Updated: 2024/12/09 10:25:07 by cofische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CUB3D_H
#define BONUS_CUB3D_H

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <float.h>
#include <limits.h>
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#define WIDTH 1600
#define HEIGHT 1000
#define BLOCK_SIZE 64
#define STEP_SIZE 0.25
#define MOUSE_SEN 0.015
#define PI 3.14159265359
#define ESC 65307
#define W 119
#define S 115
#define A 97
#define D 100
#define E 101
#define LEFT 65361
#define RIGHT 65363
#define DOOR_TIMEOUT 10

typedef struct s_game t_game;

typedef struct s_door
{
	float	x;
	float	y;
	bool	open;
	struct timeval open_time;	
}	t_door;

typedef struct s_ray
{
	float ray_x;
	float ray_y;
	float cos_a;
	float sin_a;
	float delta_x;
	float delta_y;
	float angle;
	float dist;
	float cos_angle;
	float sin_angle;
	float height_wall;
	float fov;
	float start_x;
	float step;
	float wall_dist;
	int start_wall;
	int end_wall;
	int side;
	int tex_id;
	int tex_x;
	int tex_y;
} t_ray;

typedef struct s_tex
{
	void *img;
	int bpp;
	int size_line;
	int endian;
	char *data;
	int width;
	int height;
} t_tex;

typedef struct s_player
{
	float x;
	float y;
	int speed;
	float angle;
	float angle_speed;
	float cos_angle;
	float sin_angle;
	float angle_direction;
	bool up;
	bool down;
	bool right;
	bool left;
	bool exit;
	bool door;
	bool ro_left;
	bool ro_right;
	char direction;
	t_game *game;
} t_player;

typedef struct s_game
{
	void *mlx;
	void *win;
	t_tex *north;
	t_tex *south;
	t_tex *west;
	t_tex *east;
	t_tex *door;
	t_ray ray;
	t_player player;
	t_door **d;
	int	nbr_doors;
	int	d_index;
	void *img;
	int bpp;
	int size_line;
	int endian;
	float	mouse_delta_x;
	int last_mouse_x;
	char *data;
	int player_pos;
	char p_dir;
	char **map;
	char	*line;
	int map_height;
	bool	flag;
	char *no;
	char *so;
	char *we;
	char *ea;
	char *dr;
	int f[3];
	int c[3];
	int ceiling_color;
	int floor_color;
} t_game;

void initialization(t_game *cub);
void analyse_line(t_game *cub, char *line);
void ft_copy_color(int *str, char *line);
char *ft_copy_path(t_game *cub, char *line);
void copy_map(t_game *cub, char *line);
bool map_validation(t_game *cub, char *input);
bool map_format(char *input);
void readmap(t_game *cub, int fd);
void check_map_rules(t_game *cub);
int ft_lines_count(char **tab);
void *safe_malloc(size_t size, t_game *cub);
void ft_exit(const char *str, t_game *cub, int flag);
void clean_game(t_game *cub);
int texture_info(t_game *cub, char *line, int i);
int check_color_format(int *array);
bool closed_by_walls(t_game *cub);
int cross_close_window(t_game *cub);
void start_game(t_game *cub);
int set_up_color(int *rgb);
void raycasting(t_game *cub);
void move_player(t_player *player);
void put_pixel(int x, int y, int color, t_game *game);
int draw_game(t_game *game);
void clear_image(t_game *game);
t_tex *load_tex(t_game *game, char *texture_file);
void init_texture(t_tex *texture);
void init_player(t_player *player, t_game *game);
void draw_wall(t_game *game);
int get_pixel_image(t_game *game, t_ray *ray);
void put_pixel(int x, int y, int color, t_game *game);
void draw_ceiling(t_game *game);
void draw_floor(t_game *game);
void draw_line(t_player *player, t_game *game, float ray_angle, int i);
void ray_init(t_ray *ray);
bool hit_wall(float px, float py, t_game *game);
int key_press(int keycode, t_player *player);
int key_release(int keycode, t_player *player);
void draw_minimap(t_game *game);
void	mouse_move(t_game *game);
bool	hit_door(float px, float py, t_game *game);
void check_door_timeout(t_game *game);
int	get_pixel_image_door(t_game *game, t_ray *ray);
void	door_movement(t_game *game, t_player *player);
void find_player_position(t_game *game);
void	init_door_struct(t_game *game);
void	find_doors_position(t_game *game);
void	door_init(t_door *d);


#endif
