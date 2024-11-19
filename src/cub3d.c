#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	cub;

	if (ac < 2 || av[1] == NULL || av[1][0] == '\0')
		ft_exit("Missing arguments. Format accepted ./cub3D map_name.cub\n", 0);
	clean_init(&cub);
	map_validation(&cub, av[1]);
	//window init
	//game
	clean_game(&cub);
	exit(EXIT_SUCCESS);
}
