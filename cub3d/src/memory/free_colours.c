#include "cub.h"

void free_colours(t_state *state)
{
	if (state->map.style.ceiling_rgb)
	{
		free(state->map.style.ceiling_rgb);
		state->map.style.ceiling_rgb = NULL;
	}
	if (state->map.style.floor_rgb)
	{
		free(state->map.style.floor_rgb);
		state->map.style.floor_rgb = NULL;
	}
}