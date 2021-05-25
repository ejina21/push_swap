#include "../push_swap.h"

int	command_s(char *line, t_list **lista, t_list **listb)
{
	if (*(line + 1) == 'a' && !*(line + 2))
		swap(lista);
	else if (*(line + 1) == 'b' && !*(line + 2))
		swap(listb);
	else if (*(line + 1) == 's' && !*(line + 2))
	{
		swap(lista);
		swap(listb);
	}
	else
		return (1);
	return (0);
}

int	command_r(char *line, t_list **lista, t_list **listb)
{
	if (*(line + 1) == 'a' && !*(line + 2))
		rotate(lista);
	else if (*(line + 1) == 'b' && !*(line + 2))
		rotate(listb);
	else if (*(line + 1) == 'r' && !*(line + 2))
	{
		rotate(lista);
		rotate(listb);
	}
	else if (*(line + 1) == 'r' && *(line + 2) == 'a' && !*(line + 3))
		rev_rotate(lista);
	else if (*(line + 1) == 'r' && *(line + 2) == 'b' && !*(line + 3))
		rev_rotate(listb);
	else if (*(line + 1) == 'r' && *(line + 2) == 'r' && !*(line + 3))
	{
		rev_rotate(lista);
		rev_rotate(listb);
	}
	else
		return (1);
	return (0);
}

int	doing_command(char *line, t_list **lista, t_list **listb)
{
	t_rex	rex;

	pull(&rex, 1);
	if (*line == 's')
	{
		if (command_s(line, lista, listb))
			return (1);
	}
	else if (*line == 'p')
		if (*(line + 1) == 'a' && !*(line + 2))
			push(listb, lista, &rex);
	else if (*(line + 1) == 'b' && !*(line + 2))
		push(lista, listb, &rex);
	else
		return (1);
	else if (*line == 'r')
	{
		if (command_r(line, lista, listb))
			return (1);
	}
	else
		return (1);
	return (0);
}

void	read_check(t_list **lista, t_list **listb, int len)
{
	int		i;
	char	*line;

	i = 1;
	while (i)
	{
		i = get_next_line(0, &line);
		if (!i)
			break ;
		if (doing_command(line, lista, listb))
		{
			free(line);
			write(2, "Error\n", 6);
			return ;
		}
	}
	free(line);
	if (check_finish(*lista) || count(*lista) != len)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*lista;
	t_list	*listb;
	int		*array;
	int		len;

	if (argc == 1)
		return (0);
	len = parse_count(argc, argv);
	if (!len)
		return (0);
	array = malloc(sizeof(int) * len);
	if (!array)
		return (0);
	len = parse(&lista, &array, argv, argc);
	if (!len)
		return (0);
	sort_arr(array, 0, len - 1);
	make_index(lista, array);
	read_check(&lista, &listb, len);
	return (0);
}
