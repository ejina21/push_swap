#include "push_swap.h"

static void	freem(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

int	parse_count(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;
	char	**str;

	len = 0;
	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			return (0);
		j = 0;
		while (str[j])
		{
			j++;
			len++;
		}
		freem(str);
		i++;
	}
	return (len);
}

static int	parse_help(char **str, int **array, t_list **list, int *len)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (check(str[j], *array, *len) < 0)
		{
			write(2, "Error\n", 6);
			freem(str);
			return (0);
		}
		(*array)[*len] = ft_atoi(str[j]);
		ft_lstadd_front(list, ft_lstnew((*array)[*len], 0, 0));
		j++;
		(*len)++;
	}
	return (1);
}

int	parse(t_list **list, int **array, char **argv, int argc)
{
	int		i;
	char	**str;
	int		len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
			return (0);
		if (!parse_help(str, array, list, &len))
			return (0);
		freem(str);
		i++;
	}
	return (len);
}
