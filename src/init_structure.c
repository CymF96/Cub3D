#include "cub3d.h"

void	clean_init(t_game *cub)
{
	cub->error = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->map = NULL;
	ft_memset(cub->f, -1, sizeof(cub->f));
	ft_memset(cub->c, -1, sizeof(cub->c));
	cub->player_pos = 0;
}
