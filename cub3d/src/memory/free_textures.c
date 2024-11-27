#include "cub.h"

void free_textures(t_state *state)
{
	if (state->map.style.no)
	{
		free(state->map.style.no);
		state->map.style.no = NULL;
	}
	if (state->map.style.so)
	{
		free(state->map.style.so);
		state->map.style.so = NULL;
	}
	if (state->map.style.ea)
	{
		free(state->map.style.ea);
		state->map.style.ea = NULL;
	}
	if (state->map.style.we)
	{
		free(state->map.style.we);
		state->map.style.we = NULL;
	}
}