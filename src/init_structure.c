#include "cub3d.h"

void	init_img(t_img img)
{
	*img.tex = NULL;
	ft_memset(img.tex_buf, -1, sizeof(img.tex_buf));
	img.tex_size = 0;
	img.tex_x = 0;
	img.tex_y = 0;
	ft_memset(img.line_lenght, -1, sizeof(img.line_lenght));
	ft_memset(img.bpp, -1, sizeof(img.bpp));
	ft_memset(img.endian, -1, sizeof(img.endian));
	img.c_color = 0;
	img.f_color = 0;
	img.h = WIN_H;
	img.w = WIN_W;
}

void	initialization(t_game *cub)
{
	cub->error = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->map = NULL;
	cub->mlx_img = NULL;
	cub->img_buf = NULL;
	ft_memset(cub->f, -1, sizeof(cub->f));
	ft_memset(cub->c, -1, sizeof(cub->c));
	cub->player_pos = 0;
	cub->mlx = NULL;
	cub->mlx_win = NULL;
	cub->bpp = 0;
	cub->endian = 0;
	cub->line_lenght = 0;
	init_img(cub->img);
}
