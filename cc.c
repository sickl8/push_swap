#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>

#define PV(x, y) printf("%s = " y, #x, x)
// #define MALLOC(x, y) x = malloc(sizeof(*(x)) * (y))

#include "header.h"


int		main(int ac, char **av)
{
	struct timeval taym;
	gettimeofday(&taym, NULL);
	srand(taym.tv_sec * 1000000 + taym.tv_usec);
	long *tab;
	int indexes = FALSE;
	long len = av[1] ? ft_atoi(av[1]) : 20;
	if (av[1] && av[2])
		indexes = TRUE;
	MALLOC(tab, len);
	for (long i = 0; i < len; i++)
	{
		long num;
		label:
		num = rand() % (len * 2) * pow(-1, rand() % 2);
		if (indexes)
			num = labs(num) % len;
		// num = 1 + rand() % len;
		for (long j = 0; j < i; j++)
		{
			if (tab[j] == num)
				goto label;
		}
		tab[i] = num;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%ld ", tab[i]);
	}
	printf("\n");
}