#include "cub.h"

static void	validate_args_count(int argc)
{
	if (argc != 2)
		no_mem_free_err(WRONG_ARGS_ERR);
	return ;
}

static void	validate_file_format(char *map_arg, int size)
{
	if (!ft_strnstr(map_arg, ".cub", size))
		no_mem_free_err(WRONG_FILE_FORMAT_ERR);
	if (open(map_arg, O_RDONLY) == -1)
		no_mem_free_err(INVALID_MAP_ERR);
	return ;
}

void	validate_args(int argc, char **argv)
{
	char	*map_arg;
	int		map_arg_len;

	validate_args_count(argc);
	map_arg = argv[1];
	map_arg_len = ft_strlen(map_arg);
	validate_file_format(map_arg, map_arg_len);
	return ;
}