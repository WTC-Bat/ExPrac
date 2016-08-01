#include <stdio.h>
#include <stdlib.h>

static void	fprime(int num)
{
	int		cnt;

	while (1)
	{
		cnt = 2;
		//while (++cnt <= num)
		while (cnt <= num)
		{
			if (num % cnt == 0)
			{
				printf("%i", cnt);
				num = num / cnt;
				break;
			}
			cnt++;
		}
		if (num == 1)
			break;
		else
			printf("*");
	}
	printf("\n");
}

int			main(int argc, char **argv)
{
	int		num;

	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	num = atoi(argv[1]);
	if (num < 1)
	{
		printf("\n");
		return (1);
	}
	if (num == 1)
	{
		printf("1\n");
		return (0);
	}
	fprime(num);
	return (0);
}
