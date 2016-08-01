#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	fprime(int num)
{
	int		cnt;
	int		fcnt;
	int		pcnt;

	cnt = 1;
	fcnt = 0;
	while (cnt <= num)
	{
		pcnt = 0;
		if ((num % cnt) == 0)
		{
			fcnt = 1;
			while (fcnt <= cnt)
			{
				if ((cnt % fcnt) == 0)
				{
					pcnt++;
				}
				fcnt++;
			}
			if (pcnt == 2)
			{
				printf("%i", cnt);
				printf(" ");
			}
		}
		cnt++;
	}
}

int		main(int argc, char **argv)
{
	int		num;

	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	num = atoi(argv[1]);
	if (num < 0)
	{
		printf("\n");
		return (1);
	}
	fprime(num);
	return (0);
}
