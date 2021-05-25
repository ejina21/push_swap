#include "push_swap.h"

void	rt_next(t_list **lista, t_rex *rex)
{
	t_list	*last;

	last = ft_lstlast(*lista);
	while (last->index == rex->next)
	{
		rotate(lista);
		write(1, "ra\n", 3);
		rex->next++;
		last = ft_lstlast(*lista);
	}
}

static void	clean_b_help(int i, t_list **lista, t_list **listb, t_rex *rex)
{
	t_list	*last;

	while (i)
	{
		last = ft_lstlast(*listb);
		if (last->index >= rex->mid || last->index == rex->next)
		{
			push(listb, lista, rex);
			write(1, "pa\n", 3);
			rt_next(lista, rex);
			if (last->index >= rex->mid)
				i--;
		}
		else
		{
			rotate(listb);
			write(1, "rb\n", 3);
		}
	}
}

static void	clean_b(t_rex *rex, t_list **lista, t_list **listb)
{
	int		i;

	while (*listb)
	{
		rex->flag++;
		rex->mid = (rex->max + rex->next) / 2;
		i = count_list_push(*listb);
		if (count(*listb) == 3)
		{
			rex->mid = rex->next;
			i = 3;
		}
		clean_b_help(i, lista, listb, rex);
		rex->max = rex->mid - 1;
	}
}

static void	sort_list(t_list **list, int len)
{
	t_rex	rex;
	t_list	*listb;
	int		col;

	col = count_list(*list, 0, &rex);
	listb = 0;
	if (!check_finish(*list))
		return ;
	pull(&rex, len);
	if (col < 6)
	{
		sort_small(list, &rex, col);
		return ;
	}
	while (check_finish(*list))
	{
		give_to_b(list, &listb, &rex);
		clean_b(&rex, list, &listb);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*list;
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
	len = parse(&list, &array, argv, argc);
	if (!len)
		return (0);
	sort_arr(array, 0, len - 1);
	make_index(list, array);
	sort_list(&list, len);
	return (0);
}
