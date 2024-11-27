#include "cub.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	validate_args(argc, argv);
	state = init_state(argv[FILE_ARG]);
	validate_file(state);
	parse_textures(state);
	parse_colours(state);
	printf("TEST1 NO: %s\n", state->map.style.no);
	printf("TEST2 SO: %s\n", state->map.style.so);
	//parse_map(state, argv[FILE_ARG]);
	// validate_map(state);
	// create_window(state);
	// init_sprites(state);
	// mlx_hook(state->win, KeyPress, KeyPressMask, input_handler, state);
	// mlx_loop_hook(state->mlx, loop_hook, state);
	// mlx_loop(state->mlx);
	free_state(state);
	return (0);
}
