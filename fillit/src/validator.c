#include "fillit.h"

int		valid_block(char *buf)
{
	int	neighbors;
	int	i;

	neighbors = 0;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				neighbors++;
			if (i > 0 && buf[i - 1] == '#')
				neighbors++;
			if (i >= 5 && buf[i - 5] == '#')
				neighbors++;
			if (i <= 15 && buf[i + 5] == '#')
				neighbors++;
		}
	}
	if (neighbors != 6 && neighbors != 8)
		return (0);
	return (1);
}

void	write_valid_card(char **argv, char *buf)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (++i < CARD_SIZE)
	{
		if ((i + 1) % 5 && (buf[i] != '.' && buf[i] != '#'))
			ft_assert(0);
		if (!((i + 1) % 5) && buf[i] != '\n')
			ft_assert(0);
		if (buf[i] == '#')
			counter++;
	}
	ft_assert(counter == 4 && valid_block(buf));
	if (!(*argv = ft_strdup(buf)))
	{
		ft_putstr("malloc failed\n");
		exit(0);
	}
}

int		validator(int fd, char **argv)
{
	int		rd;
	char	buf[CARD_SIZE + 1];
	int		total;
	int		file_size;

	total = 0;
	file_size = 0;
	while ((rd = read(fd, buf, CARD_SIZE + 1)) > 0)
	{
		buf[rd] = 0;
		write_valid_card(argv, buf);
		argv++;
		total++;
		file_size += rd;
	}
	if (rd == -1 || (file_size + 1) % (CARD_SIZE + 1) || total > 26)
		ft_assert(0);
	return (total);
}
