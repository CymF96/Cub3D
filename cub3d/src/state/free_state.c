#include "cub.h"

void	free_state(t_state *state)
{
	if (state->matrix)
		free_matrix(state);
	if (state->raw_content)
		free(state->raw_content);
	state->raw_content = NULL;
	free_textures(state);
	free_colours(state);
	free(state);
}