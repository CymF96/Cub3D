#include "cub.h"

void	parse_map(t_state *state)
{
	int		i;
	int		j;
	char	*row;
	char	*column;

	i = 0;
	while (state->matrix[i])
	{
		row = state->matrix[i];
		j = 0;
		while (state->matrix[i][j])
		{
			column = state->matrix[i][j];
			if (ft_strchr(" 01"))
			j++;
		}
		i++;
	}
	return ;
}
