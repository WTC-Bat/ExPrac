#include <stdio.h>
#include "ft_atoi.c"
#include "../ft_itoa/ft_itoa.c"

int		main(void)
{
	char	*istr;
	int		i;

	istr = "-42";
	i = ft_atoi(istr);
	printf("%i", i);
	return (0);
}
