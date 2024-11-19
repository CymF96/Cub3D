#include "cub3d.h"

int	ft_lines_count(char **tab)
{
	int	lines;

	lines = 0;
	if (!tab[lines])
		return (lines);
	while (tab[lines] != NULL)
		lines++;
	return (lines);
}

void	*safe_malloc(size_t size, t_game *cub)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		ft_exit("malloc failed", cub);
	return (ptr);
}

void	ft_exit(const char *str, t_game *cub)
{
	printf("Error:\n%s\n", str);
	if (cub != NULL)
		clean_game(cub);
	exit(EXIT_FAILURE);
}
