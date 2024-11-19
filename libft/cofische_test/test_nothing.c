#include <stdio.h>
#include "../libft.h"

int main()
{
	int     fd1;
	char    *line;

	fd1 = open("files/nothing.txt", O_RDONLY);
	
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	while ((line = get_next_line(42)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	
	close(fd1);
	close(42);

	return 0;
}
