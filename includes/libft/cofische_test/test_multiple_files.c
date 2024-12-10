#include <stdio.h>
#include "../libft.h"


int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("files/Lorem_Ipsum.txt", O_RDONLY);
	fd2 = open("files/French_comptine.txt", O_RDONLY);
	fd3 = open("files/Pizza_recipe.txt", O_RDONLY);
	i = 1;
	while (i < 20)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
