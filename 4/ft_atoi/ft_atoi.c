int		ft_atoi(char *str)
{
	int		cnt;
	int		out_int;

	out_int = 0;
	if (str[0] == '-')
		cnt = 1;
	else
		cnt = 0;
	while (str[cnt] != 0 && str[cnt] > 47 && str[cnt] < 58)
	{
		out_int = out_int * 10 + (str[cnt] - '0');
		cnt++;
	}
	if (str[0] == '-')
		out_int = -out_int;
	return (out_int);
}
