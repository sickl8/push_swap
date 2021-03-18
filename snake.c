#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define MALLOC(x, y) x = malloc(sizeof(*(x)) * (y))

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct	slst
{
	piece		data;
	struct slst	*next;
}				lst;

typedef struct	scoor
{
	int		x;
	int		y;
}				coor;

typedef struct	spc
{
	coor	pos;
	int		dir;
}				piece;

typedef struct	ssnake
{
	coor	head;
	lst		body;
}				snake;

char canvas[100][100];

void	lst_push_back(piece data, lst **head)
{
	lst		*new;

	MALLOC(new, 1);
	new->data = data;
	new->next = NULL;
	while (*head)
		head = &(*head)->next;
	*head = new;
}

void	lst_push_front(piece data, lst **head)
{
	lst		*new;

	MALLOC(new, 1);
	new->data = data;
	new->next = *head;
	*head = new;
}

void	print_canvas()
{
	for (int i = 0; i < 100; i++)
		printf("%s\n", canvas[i]);
}

void	init_cavas()
{
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			canvas[i][j] = ' ';
}

int		random()
{
	struct timeval taym;
	gettimeofday(&taym, NULL);
	srand(taym.tv_sec * 1000000 + taym.tv_usec);
	return (rand());
}

int		main()
{
	init_cavas();
	
	while (1)
	{
		
	}
}