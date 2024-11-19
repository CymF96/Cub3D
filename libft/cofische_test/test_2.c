#include <stdio.h>
#include "../libft.h"


int main()
{
	int     fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char    *line;

	fd1 = open("files/Lorem_Ipsum.txt", O_RDONLY);

	fd2 = open("files/big_line_no_nl.txt", O_RDONLY);

	fd3 = open("files/French_comptine.txt", O_RDONLY);

	fd4 = open("files/Pizza_recipe.txt", O_RDONLY);

	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	printf("\n");
	while ((line = get_next_line(fd2)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	printf("\n\n");
	while ((line = get_next_line(fd3)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	printf("\n\n");
	while ((line = get_next_line(fd4)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	printf("\n");

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return 0;
}
