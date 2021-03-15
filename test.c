#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		main()
{
	int ret;
	char buf[10000];
	while (1)
	{
		memset(buf, 0, 10000);
		ret = read(0, buf, 9999);
		printf("buf = |%s|\n", buf);
		printf("ret = %d\n", ret);
	}
}