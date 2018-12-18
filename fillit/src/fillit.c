#include "fillit.h"

void	fillit(int fd)
{
	char	**argv;

	if (!(argv = malloc(sizeof(*argv) * (MAX_CARDS + 1))))
	{
		ft_putstr("malloc failed\n");
		exit(0);
	}
	argv[validator(fd, argv)] = 0;
	while (*argv)
		ft_putstr(*argv++);
//	print_square(tetramino_arr);
}
