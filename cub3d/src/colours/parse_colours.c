#include "cub.h"

static void	validate_colours(t_state *state)
{
	bool	is_valid;

	is_valid = true;
	if (state->map.style.floor_rgb == NULL)
		is_valid = false;
	if (state->map.style.ceiling_rgb == NULL)
		is_valid = false;
	if (!is_valid)
		err_and_free_state(COLOURS_ARGS_ERR, state);
}

static void set_colour(char *line, char **colour)
{
	char **arr;

	arr = ft_split(line, ' ');
	if (arr && arr[1])
	{
		free(*colour);
		*colour = ft_strdup(arr[1]);
		free(arr[0]);
		free(arr[1]);
	}
	else
	{
		free(arr[0]);
		*colour = NULL;
	}
	free(arr);
	return ;
}

void	parse_colours(t_state *state)
{
	int		i;
	char	*line;

	i = 0;
	while (state->matrix[i])
	{
		line = state->matrix[i];
		if (line[0] == 'F')
			set_colour(line, &state->map.style.floor_rgb);
		if (line[0] == 'C')
			set_colour(line, &state->map.style.ceiling_rgb);
		i++;
	}
	validate_colours(state);
	return ;
}