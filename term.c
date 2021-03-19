#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

int		get_pos(int *y, int *x);

void	get_dim(int *x, int *y)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	*y = w.ws_row;
	*x = w.ws_col;
}

int		get_pos(int *y, int *x)
{
	struct	termios term, restore;
	char	buf[30] = {0};
	int		ret, i, pow;
	char	ch;

	*y = 0; *x = 0;
	tcgetattr(0, &term);
	tcgetattr(0, &restore);
	term.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(0, TCSANOW, &term);
	write(1, "\033[6n", 4);
	for( i = 0, ch = 0; ch != 'R'; i++ )
	{
		ret = read(0, &ch, 1);
		if ( !ret ) {
			tcsetattr(0, TCSANOW, &restore);
			fprintf(stderr, "getpos: error reading response!\n");
			return 1;
		}
		buf[i] = ch;
	}
	if (i < 2) {
		tcsetattr(0, TCSANOW, &restore);
		printf("i < 2\n");
		return(1);
	}
	for( i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
		*x = *x + ( buf[i] - '0' ) * pow;
	for( i-- , pow = 1; buf[i] != '['; i--, pow *= 10)
		*y = *y + ( buf[i] - '0' ) * pow;
	tcsetattr(0, TCSANOW, &restore);
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
	return 0;
}

int		main()
{
	int x = 0, y = 0;


	get_dim(&x, &y);
	printf("xmax:%d, ymax:%d\n", x, y);
	sleep(1);
	system("clear");
	// sleep(1);
	// gotoxy(20, 40);
	sleep(1);
	get_pos(&x, &y);
	sleep(1);
	gotoxy(1, 10);
	sleep(1);
	get_pos(&x, &y);
	getc(stdin);
	// printf("x:%d, y:%d\n", x, y);
	sleep(1);
	printf("x:%d, y:%d\n", x, y);
	return 0;
}
