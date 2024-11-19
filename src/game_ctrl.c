#include "cub3d.h"

int	esc_close_window(int keycode, t_game *cub)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(cub->mlx);
		ft_exit(NULL, cub, 0);
	}
	return (0);
}

int	cross_close_window(t_game *cub)
{
	mlx_loop_end(cub->mlx);
	ft_exit(NULL, cub, 0);
	return (0);
}