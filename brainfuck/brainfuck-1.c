#include <unistd.h>
#include <stdlib.h>

static void	ft_putstr(char *str)
{
	int		cnt;

	cnt = 0;
	while (str[cnt] != '\0')
	{
		write(1, &str[cnt], 1);
		cnt++;
	}
	write(1, "\n", 1);
}

static void	init(char *bytes, unsigned int size)
{
	int		cnt;

	cnt = 0;
	while (cnt < size)
	{
		bytes[cnt] = 0;
		cnt++;
	}
}

static void	interpret(char *bytes, char **args)
{
	int		cnt;
	int		scnt;
	int		bracket;
	int		bcnt;

	cnt = 0;
	scnt = 1;
	bracket = 0;
	while (args[scnt] != 0)
	{
		while (args[scnt][cnt] != '\0')
		{
			if (args[scnt][cnt] == '>')
				bytes++;
			else if (args[scnt][cnt] == '<')
				bytes--;
			else if (args[scnt][cnt] == '+')
				(*bytes)++;
			else if (args[scnt][cnt] == '-')
				(*bytes)--;
			else if (args[scnt][cnt] == '.')
				write(1, &(*bytes), 1);
			else if (args[scnt][cnt] == '[')
			{
				if (*bytes == 0)
				{
					bracket = 1;
					cnt++;
					while (bracket != 0)
					{
						if (args[scnt][cnt] == '[')
							bracket++;
						else if (args[scnt][cnt] == ']')
							bracket--;
						if (bracket != 0)
							cnt++;
					}
				}
			}
			else if (args[scnt][cnt] == ']')
			{
				if (*bytes != 0)
				{
					bracket = 1;
					cnt--;
					while (bracket != 0)
					{
						if (args[scnt][cnt] == ']')
							bracket++;
						else if (args[scnt][cnt] == '[')
							bracket--;
						if (bracket != 0)
							cnt--;
					}
				}
			}
			cnt++;
		}
		cnt = 0;
		scnt++;
	}
}

int			main(int argc, char **argv)
{
	char	bytes[2048];

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	init(&bytes[0], 2048);
	interpret(&bytes[0], argv);
	return (0);
}
