#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <float.h>
# include <limits.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK_SIZE 64
# define PI 3.14159265359
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363

typedef struct s_ray
{
	float	ray_x;
	float	ray_y;
	float	cos_a;
	float	sin_a;
	float	delta_x;
	float	delta_y;
	float	angle;
	float	dist;
	float	cos_angle;
	float	sin_angle;
	float	height_wall;
	float	fov;
	float	start_x;
	float	step;
	float	wall_dist;
	int		start_wall;
	int		end_wall;
	int		side;
	int		tex_id;
	int		tex_x;
	int		tex_y;
}	t_ray;

typedef struct s_tex
{
	void		*img;
	int			bpp;
	int			size_line;
	int			endian;
	char		*data;
	int			width;
	int			height;
}	t_tex;

typedef	struct s_player
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
	bool	ro_left;
	bool	ro_right;
	char	direction;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_tex	*tex_wall;
	t_ray	ray;
	t_player	player;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	int		player_pos;
	char	p_dir;
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}	t_game;

void	initialization(t_game *cub);
void	analyse_line(t_game *cub, char *line);
void	map_identifiers(t_game *cub, char *line, int i);
void	case_with_1(t_game *cub, char *line, int i);
void	ft_copy_color(t_game *cub, int *str, char *line);
char	*ft_copy_path(t_game *cub, char *line);
void	copy_map(t_game *cub, char *line);
bool	map_validation(t_game *cub, char *input);
bool	map_format(char *input);
void	readmap(t_game *cub, int fd);
void	check_map_rules(t_game *cub);
int		ft_lines_count(char **tab);
void	*safe_malloc(size_t size, t_game *cub);
void	ft_exit(const char *str, t_game *cub, int flag);
void	clean_game(t_game *cub);
int		texture_info(t_game *cub, char *line, int i);
void	check_color_format(t_game *cub, int	*array);
bool	closed_by_walls(t_game *cub);
int		cross_close_window(t_game *cub);
void	start_game(t_game *cub);
void	move_player(t_player *player);
int		set_up_color(int *rgb);
void	raycasting(t_game *cub);
void	facing_dir(t_game *cub);
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_player *player);
void	move_player(t_player *player);
void	put_pixel(int x, int y, int color, t_game *game);
int	draw_game(t_game *game);
void	clear_image(t_game *game);
t_tex	*load_tex(t_game *game, char *texture_file);
void	put_pixel_rgb(int x, int y, int *rgb, t_game *game);
void	init_texture(t_tex *texture);
void	init_player(t_player *player);

#endif