#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#include "header.h"

typedef struct s_i
{
	long	len;
	long	num;
	long	i;
	long	j;
}				t_i;

void	print(int len, long *tab)
{
	int		i;

	i = -1;
	while (++i < len)
		printf("%ld ", tab[i]);
	printf("\n");
}

int	main(int ac, char **av)
{
	long			*tab;
	struct timeval	taym;
	int				indexes;
	t_i				x;

	x.len = !(!(av[1])) * ft_atoi(av[1]) + !(av[1]) * 20;
	indexes = av[1] && av[2];
	gettimeofday(&taym, NULL);
	srand(taym.tv_sec * 1000000 + taym.tv_usec);
	tab = malloc(sizeof(*(tab)) * (x.len));
	x.i = -1;
	while (++x.i < x.len)
	{
		x.num = rand() % (x.len * 2) * pow(-1, rand() % 2);
		x.num = indexes * (labs(x.num) % x.len) + x.num * !indexes;
		x.j = -1;
		while (++x.j < x.i)
			if (tab[x.j] == x.num && 1 + 0 * x.i--)
				break ;
		if (x.j < x.i)
			continue ;
		tab[x.i] = x.num;
	}
	print(x.len, tab);
}
