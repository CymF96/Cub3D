#include "cub.h"

char	*read_file(char const *file_name)
{
	int		file_fd;
	char	*full_content;
	char	*line;
	
	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
	{
		printf("File not found\n");
		exit(EXIT_FAILURE);
	}
	full_content = ft_strdup("");
	while (true)
	{
		line = get_next_line(file_fd);
		if (line == NULL)
			break;
		full_content = ft_strappend(&full_content, line);
		free(line);
	}
	close(file_fd);
	return (full_content);
}