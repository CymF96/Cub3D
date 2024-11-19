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

// typedef struct s_map
// {

// }	t_mapinfo;

typedef struct s_game
{
	char		*error;
	int			player_pos;
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f[3];
	int			c[3];
}	t_game;

void	clean_init(t_game *cub);
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
void	ft_exit(const char *str, t_game *cub);
void	clean_game(t_game *cub);
int		texture_info(t_game *cub, char *line, int i);
void	check_color_format(t_game *cub, int	*array);
bool	closed_by_walls(t_game *cub);

#endif