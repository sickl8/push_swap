#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define PA 0
#define PB 1
#define PV(x, y) printf("%s = " y, #x, x)
#define MALLOC(x, y) x = malloc(sizeof(*(x)) * (y))

int		main()
{
	struct timeval taym;
	gettimeofday(&taym, NULL);
	srand(taym.tv_sec * 1000000 + taym.tv_usec);
	int *tab;
	int len = 20;
	MALLOC(tab, len);
	for (int i = 0; i < len; i++)
	{
		int num;
		label:
		num = rand() % len;
		for (int j = 0; j < i; j++)
		{
			if (tab[j] == num)
				goto label;
		}
		tab[i] = num;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}