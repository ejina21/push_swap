#include "push_swap.h"

static void	give_to_b_rot(t_list **lista, t_list **listb, t_rex *rex, int *len)
{
	t_list	*lastb;

	(*len)++;
	lastb = ft_lstlast(*listb);
	if (lastb && lastb->index != rex->next
		&& lastb->index < (rex->mid + rex->next) / 2)
	{
		rotate(listb);
		rotate(lista);
		write(1, "rr\n", 3);
	}
	else
	{
		rotate(lista);
		write(1, "ra\n", 3);
	}
}

static int	give_to_b_hf(t_list **lista, t_list **listb, t_rex *rex, int *len)
{
	t_list	*last;

	last = ft_lstlast(*lista);
	if (last->index <= rex->mid)
	{
		push(lista, listb, rex);
		write(1, "pb\n", 3);
		return (1);
	}
	else
		give_to_b_rot(lista, listb, rex, len);
	return (0);
}

static void	give_to_b_help(int i, t_list **lista, t_list **listb, t_rex *rex)
{
	t_list	*lastb;
	int		len;

	len = 0;
	while (i)
		i -= give_to_b_hf(lista, listb, rex, &len);
	while (len-- && rex->next != 1)
	{
		lastb = ft_lstlast(*listb);
		if (lastb->index != rex->next)
		{
			rev_rotate(listb);
			rev_rotate(lista);
			write(1, "rrr\n", 4);
		}
		else
		{
			rev_rotate(lista);
			write(1, "rra\n", 4);
		}
	}
}

static void	give_to_b_small(int len, t_list **lista, t_list **listb, t_rex *rex)
{
	t_list	*last;
	int		flag;

	last = ft_lstlast(*lista);
	flag = last->flag;
	while (len && check_finish(*lista))
	{
		if (last->index == rex->next + 1)
		{
			swap(lista);
			write(1, "sa\n", 3);
			last = ft_lstlast(*lista);
		}
		if (last->index == rex->next + 2)
		{
			push(lista, listb, rex);
			write(1, "pb\n", 3);
			last = ft_lstlast(*lista);
		}
		rt_next(lista, rex);
		len = count_list(*lista, flag, rex);
	}
}

void	give_to_b(t_list **lista, t_list **listb, t_rex *rex)
{
	int		flag;
	int		i;
	int		len;
	t_list	*last;

	last = ft_lstlast(*lista);
	flag = last->flag;
	len = count_list(*lista, flag, rex);
	if (len > 3)
	{
		i = len / 2 + len % 2;
		rex->max = rex->mid;
		give_to_b_help(i, lista, listb, rex);
	}
	else
	{
		give_to_b_small(len, lista, listb, rex);
	}
}
