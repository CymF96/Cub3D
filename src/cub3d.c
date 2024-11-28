#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	cub;

	if (ac < 2 || av[1] == NULL || av[1][0] == '\0')
		ft_exit("Missing arguments. Format accepted ./cub3D map_name.cub\n", NULL, 1);
	//initializa the main structure and the ray struct for raycasting calculation
	initialization(&cub);
	//perform the parsing/checking of the map and texture information
	map_validation(&cub, av[1]);
	//start the game and perfom player movement
	start_game(&cub);
	//cleaning structure (this is probably never reach as ft_exit is also in cmd to close window (e.g cross and ESC))
	ft_exit("End game", &cub, 0);
}
