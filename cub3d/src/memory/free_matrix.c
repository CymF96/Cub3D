#include "cub.h"

void free_matrix(t_state *state)
{
	int i;

	i = 0;
	while (state->matrix[i])
	{
		free(state->matrix[i]);
		i++;
	}
	free(state->matrix);
	state->matrix = NULL;
	return ;
}