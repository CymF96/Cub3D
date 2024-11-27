#include "cub.h"

static void	validate_texture_count(t_state *state)
{
	int		i;
	int		count;
	char	*line;

	i = 0;
	count = 0;
	while (state->matrix[i])
	{
		line = state->matrix[i];
		if (ft_strchr("NESW", line[0]))
			count++;
		i++;
	}
	if (count != 4)
		err_and_free_state(TEXTURE_COUNT_ERR, state);
	return ;
}

static void	validate_colours_count(t_state *state)
{
	int		i;
	int		count;
	char	*line;

	i = 0;
	count = 0;
	while (state->matrix[i])
	{
		line = state->matrix[i];
		if (ft_strchr("FC", line[0]))
			count++;
		i++;
	}
	if (count != 2)
		err_and_free_state(COLOURS_COUNT_ERR, state);
	return ;
}

static void	set_map_start(t_state *state)
{
	int		i;
	int		j;
	char	element;

	i = 0;
	while (state->matrix[i])
	{
		j = 0;
		while (state->matrix[i][j])
		{
			element = state->matrix[i][j];
			if (ft_strchr(" 1", element) && \
				ft_strchr("1", state->matrix[i][j + 1]))
			{
				state->map.map_start_row = i;
				return;
			}
			j++;
		}
		i++;
	}
	if (state->map.map_start_row == -1)
		err_and_free_state("Map not found", state);
	return ;
}	

void	validate_file(t_state *state)
{
	int		i;
	char	*line;

	i = 0;
	while (state->matrix[i])
	{
		line = state->matrix[i];
		if (!ft_strchr("FCNESW01 ", line[0]))
			err_and_free_state(INVALID_MAP_ATTR_ERR, state);
		i++;
	}
	validate_texture_count(state);
	validate_colours_count(state);
	set_map_start(state);
	return ;
}