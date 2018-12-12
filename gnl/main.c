//#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(void)
{
	char	*str = NULL;
	int		i;
	int		fd;
	int		fd2;

	fd = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while ((i = get_next_line(fd, &str)))
	{
		printf("%s\n", str);
	}
/*	i = get_next_line(fd, &str);
	printf("%s\n", str);
	printf("%d\n", i);
	i = get_next_line(fd2, &str);
	printf("%s\n", str);
	printf("%d\n", i);
	i = get_next_line(fd, &str);
	printf("%s\n", str);
	printf("%d\n", i);
	*/
	free(str);
	close(fd);
	return (0);
}
