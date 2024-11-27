#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map_style
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *floor_rgb;
    char    *ceiling_rgb;
}	t_map_style;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	char			**full;
	int				map_start_row;
	int				rows;
	int				columns;
	int				players;
	t_player		player;
	t_map_style		style;
}	t_map;

typedef struct s_state
{
	char			*raw_content;
	char			**matrix;
	t_map			map;
}	t_state;

#endif