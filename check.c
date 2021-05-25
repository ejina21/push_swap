static int	check_double(int sum, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == sum)
			return (-1);
		i++;
	}
	return (0);
}

static unsigned int	check_sum(char flag, char *str)
{
	unsigned int	sum;
	int				i;

	i = 0;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + str[i] - '0';
		i++;
		if (flag && sum > 2147483648)
			return (-1);
		if (!flag && sum > 2147483647)
			return (-1);
	}
	return (sum);
}

static int	check_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	check(char *str, int *array, int len)
{
	int				i;
	unsigned int	sum;
	char			flag;

	flag = 0;
	i = 0;
	sum = 0;
	if (*str == '-')
	{
		str++;
		flag = 1;
	}
	else if (*str == '+')
		str++;
	if (!*str)
		return (-1);
	if (check_int(str))
		return (-1);
	sum = check_sum(flag, str);
	if ((int)sum == -1)
		return (-1);
	if (flag)
		sum = -sum;
	return (check_double(sum, array, len));
}
