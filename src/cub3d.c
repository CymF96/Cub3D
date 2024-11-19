#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	cub;

	if (ac < 2 || av[1] == NULL || av[1][0] == '\0')
		ft_exit("Missing arguments. Format accepted ./cub3D map_name.cub\n", NULL, 1);
	initialization(&cub);
	map_validation(&cub, av[1]);
	start_game(&cub);
	//game
	ft_exit("End game", &cub, 0);
}
