#include "cub.h"

static void	check_map_empty_line(char *file_content)
{
	int		i;
	bool	is_map;
	bool	is_newline;
	bool	is_next_newline;
	bool	is_next_null;

	i = 0;
	is_map = false;
	while (file_content[i])
	{
		is_newline = file_content[i] == '\n';
		if (is_newline && ft_strchr("0 1", file_content[i + 1]))
			is_map = true;
		if (is_map)
		{
			is_next_newline = file_content[i + 1] == '\n';
			is_next_null = file_content[i + 1] == '\0';
			if (is_newline && (is_next_newline || is_next_null))
				err_and_free_char(NEWLINE_ON_MAP_ERR, file_content);
		}
		i++;
	}
	return ;
}

void map_validation_handler(char *file_name)
{
	char	*file_content;
	char	**content_matrix;

	file_content = read_file(file_name);
	if (!file_content[0])
		err_and_free_char(READ_MAP_ERR, file_content);
	check_map_empty_line(file_content);
	content_matrix = ft_split(file_content, '\n');
	free(file_content);
	
}