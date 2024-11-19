#include "cub3d.h"

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
        cub->img.bpp[i] = malloc(sizeof(int));
        cub->img.line_lenght[i] = malloc(sizeof(int));
        cub->img.endian[i] = malloc(sizeof(int));
		cub->img.tex_buf[i] = (int *)mlx_get_data_addr(cub->img.tex[i], cub->img.bpp[i], cub->img.line_lenght[i], cub->img.endian[i]);
		if (!cub->img.tex_buf[i])
			printf("error in saving %d address\n", i);
	}
	cub->img.tex[4] = NULL;
}

void	set_up_color(t_game *cub)
{
	cub->img.c_color = (cub->c[0] << 16 | cub->c[1] << 8 | cub->c[2]);
	cub->img.f_color = (cub->f[0] << 16 | cub->f[1] << 8 | cub->f[2]);
}
