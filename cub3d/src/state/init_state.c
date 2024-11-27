#include "cub.h"

static void	init_map_state(t_state *state)
{
	state->map.full = NULL;
	state->map.style.no = NULL;
	state->map.style.so = NULL;
	state->map.style.we = NULL;
	state->map.style.ea = NULL;
	state->map.map_start_row = -1;
	state->map.style.floor_rgb = NULL;
	state->map.style.ceiling_rgb = NULL;
	return ;
}

t_state	*init_state(char *file_path)
{
	t_state	*state;

	state = malloc(sizeof(*state));
	if (!state)
		no_mem_free_err(INIT_STATE_ERR);
	state->raw_content = read_file(file_path);
	state->matrix = ft_split(state->raw_content, '\n');
	init_map_state(state);
	return (state);
}