#include <stdio.h>
#include "ft_itoa.c"

int		main(void)
{
	int		i;
	char	*str;

	i = -2147482648;
	str = ft_itoa(i);
	printf("%s", str);
	return (0);
}
