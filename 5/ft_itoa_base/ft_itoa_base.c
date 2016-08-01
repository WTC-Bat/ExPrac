#include <stdio.h>
#include <stdlib.h>

static int	slen(char *str)
{
	int		cnt;

	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

static int	set_nbr(int num)
{
	int		n;

	n = 0;
	if (num < 0)
	{
		if (num == -2147483648)
		{
			n = num + 1;
			n = -n;
		}
		else
		{
			n = num;
			n = -n;
		}
	}
	else
		n = num;
	return (n);
}

char		*ft_itoa_base(int value, int base)
{
	char	*basechars;
	char	*out_str;
	int		n;
	int		bc;

	basechars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	out_str = (char *)malloc(sizeof(char) * 32);
	n = set_nbr(value);
	bc = 0;
	*out_str = '\0';
	if (value == 0)
		*--out_str = '0';
	while (n != 0)
	{
		bc = n % base;
		n = n / base;
		*--out_str = basechars[bc];
	}
	if (value < 0 && base == 10)
		*--out_str = '-';
	if (value == -2147483648 && base == 10)
		out_str[slen(out_str) - 1] = '8';
	return (out_str);
}

/*TESTS*/
int		main(void)
{
	int		i;
	char	*base_str;

	i = 42;
	base_str = ft_itoa_base(i, 16);
	printf("%s", base_str);
	return (0);
}
