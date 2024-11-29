#include "cub3d.h"

void	generate_texture_in_img_data(t_game *cub)
{
	int	x;
	int	y;

	cub->img_buf = malloc(WIN_H * sizeof(int *));
	x = -1;
	while (++x < WIN_H)
	{
		cub->img_buf[x] = malloc(WIN_W * sizeof(int));
		if (!cub->img_buf[x])
			ft_exit("failed allocation memory for img_buffer", cub, 1);
	}
	x = -1;
	while (++x < WIN_W)
	{
		y = -1;
		while (++y < WIN_H)
			cub->img_buf[y][x] = cub->img.tex_add[0][(y % cub->img.tex_size) * cub->img.tex_size + (x % cub->img.tex_size)];
	}
}

void	load_textures(t_game *cub) // replace the printf to ft_exit
{
	int	i;

	i = -1;
	cub->img.tex_size = 64;
	cub->img.tex[0] = mlx_xpm_file_to_image(cub->mlx, cub->no, &cub->img.tex_size, &cub->img.tex_size);
	if (cub->img.tex[0] == NULL)
		printf("error generating image north %s\n", cub->no);
	cub->img.tex[1] = mlx_xpm_file_to_image(cub->mlx, cub->so, &cub->img.tex_size, &cub->img.tex_size);
	if (cub->img.tex[1] == NULL)
		printf("error generating image south\n");
	cub->img.tex[2] = mlx_xpm_file_to_image(cub->mlx, cub->we, &cub->img.tex_size, &cub->img.tex_size);
	if (cub->img.tex[2] == NULL)
		printf("error generating image west\n");
	cub->img.tex[3] = mlx_xpm_file_to_image(cub->mlx, cub->ea, &cub->img.tex_size, &cub->img.tex_size);
	if (cub->img.tex[3] == NULL)
		printf("error generating image east\n");
	while (++i < 4)
	{
		cub->img.tex_add[i] = (int *)mlx_get_data_addr(cub->img.tex[i], &(int){0}, &(int){0}, &(int){0});
		if (!cub->img.tex_buf[i])
			printf("error in saving %d address\n", i);
	}
	generate_texture_in_img_data(cub);
}

void	generate_textures(t_game *cub)
{
	int i;

	cub->mlx_img = mlx_new_image(cub->mlx, cub->win_w, cub->win_h);
	if (cub->mlx_img == NULL)
		ft_exit("Error generating mlx_img", cub, 1);
	cub->img_add = (int *)mlx_get_data_addr(cub->mlx_img, &(int){0}, &(int){0}, &(int){0});
	if (cub->img_add == NULL)
		ft_exit("Error generating img_buf", cub, 1);
	i = -1;
	while (++i < 8)
	{
		cub->img.tex_buf[i] = (int *)malloc(cub->img.tex_size * cub->img.tex_size * sizeof(int));
		if (cub->img.tex_buf[i] == NULL)
			ft_exit("Error generating textures strucutre", cub, 1);
	}
}

void	set_up_color(t_game *cub)
{
	cub->img.c_color = (cub->c[0] << 16 | cub->c[1] << 8 | cub->c[2]);
	cub->img.f_color = (cub->f[0] << 16 | cub->f[1] << 8 | cub->f[2]);
}

void	render_textures(t_game *cub, int x)
{
	int	y;
	
	y = -1;
	cub->img.tex_x = (int)cub->ray.wall_x * cub->img.tex_size % cub->img.tex_size;
	while (++y < WIN_H - 1)
	{
		if (y < cub->ray.draw_s)
			cub->img_data[y * cub->win_w + x] = &cub->img.c_color;
		else if (y > cub->ray.draw_e)
			cub->img_data[y * cub->win_w + x] = &cub->img.f_color;
		else
		{
			cub->img.tex_y = ((y - cub->ray.draw_s) * cub->img.tex_size / cub->ray.line_h);
			cub->color = cub->img.tex_add[cub->img.tex_id][cub->img.tex_y * cub->img.tex_size + cub->img.tex_x];
			cub->img_buf[y][x] = cub->color;
		}
	}
}

void	img_to_window(t_game *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			cub->img_add[y * WIN_W + x] = cub->img_buf[y][x];
	}
}
