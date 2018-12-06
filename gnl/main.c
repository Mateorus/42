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

	fd = open("test.txt", O_RDONLY);
	i = get_next_line(fd, &str);
	printf("%s", str);
	return (0);
}
