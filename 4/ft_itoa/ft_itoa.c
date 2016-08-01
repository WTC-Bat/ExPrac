#include <stdlib.h>

int		slen(char *str)
{
	int		cnt;

	while (str[cnt] != 0)
		cnt++;
	return (cnt);
}

char	*ft_itoa(int num)
{
	char	*istr;

	istr = (char *)malloc(sizeof(char) * 32);
	if (num == 0)
		*--istr = '0';
	if (num > 0)
	{
		while (num != 0)
		{
			*--istr = '0' + (num % 10);
			num = num / 10;
		}
	}
	else
	{
		while (num != 0)
		{
			*--istr = '0' - (num % 10);
			num = num / 10;
		}
		*--istr = '-';
	}
	istr[slen(istr)] = '\0';
	return (istr);
}
