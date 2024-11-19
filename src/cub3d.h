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
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define WIN_W 800
# define WIN_H 600

typedef enum e_errcode
{
	WALL,
	CHAR,
	FORMAT,
	FD,
	M_INFO,
	M_INPUT,
	I_INFO,
	I_INPUT,
}	t_errcode;

typedef struct s_img
{
	void	*tex[5];
	int		*tex_buf[4];
	int		tex_size;
	int		tex_x;
	int		tex_y;
	int		*line_lenght[4];
	int		*bpp[4];
	int		*endian[4];
	int		c_color;
	int		f_color;
	int		h;
	int		w;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	void	*mlx_img;
	int		*img_buf;
	int		bpp;
	int		line_lenght;
	int		endian;
	char		*error;
	int			player_pos;
	int			p_posx;
	int			p_posy;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
	int			win_w;
	int			win_h;
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
int		esc_close_window(int keycode, t_game *cub);
int		cross_close_window(t_game *cub);
void	start_game(t_game *cub);
int		game_mv(int	keycode, t_game *cub);
void	set_up_color(t_game *cub);
void	load_textures(t_game *cub);
void	raycasting(t_game *cub);


#endif