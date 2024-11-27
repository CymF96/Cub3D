#include "cub.h"

static void	validate_textures(t_state *state)
{
	bool	is_valid;

	is_valid = true;
	if (state->map.style.no == NULL)
		is_valid = false;
	if (state->map.style.so == NULL)
		is_valid = false;
	if (state->map.style.ea == NULL)
		is_valid = false;
	if (state->map.style.we == NULL)
		is_valid = false;
	if (!is_valid)
		err_and_free_state(TEXTURE_ARGS_ERR, state);
}

static void set_texture(char *line, char **texture)
{
	char **arr;

	arr = ft_split(line, ' ');
	if (arr && arr[1])
	{
		free(*texture);
		*texture = ft_strdup(arr[1]);
		free(arr[0]);
		free(arr[1]);
	}
	else
	{
		free(arr[0]);
		*texture = NULL;
	}
	free(arr);
	return ;
}

void	parse_textures(t_state *state)
{
	int		i;
	char	*row;

	i = 0;
	while (state->matrix[i])
	{
		row = state->matrix[i];
		if (row[0] == 'N')
			set_texture(row, &state->map.style.no);
		if (row[0] == 'S')
			set_texture(row, &state->map.style.so);
		if (row[0] == 'E')
			set_texture(row, &state->map.style.ea);
		if (row[0] == 'W')
			set_texture(row, &state->map.style.we);
		i++;
	}
	validate_textures(state);
	return ;
}

	// char	*file_content;

	// file_content = read_file(file_path);
	// line_len = 0;
	// state->map.rows = 0;
	// while (1)
	// {
	// 	line_tmp = get_next_line(map_fd);
	// 	if (!line_tmp)
	// 		break ;
	// 	validate_line(state, &line_tmp, &line_len, map_tmp);
	// 	append_line_to_map(&map_tmp, line_tmp);
	// 	free(line_tmp);
	// 	state->map.rows++;
	// }
	// close(map_fd);
	// check_for_empty_line(map_tmp, state);
	// state->map.full = ft_split(map_tmp, '\n');
	// init_map(state);
	// free(map_tmp);