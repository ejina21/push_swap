#include "push_swap.h"

static t_list	*sort_ff(int number, t_list **lista, t_rex *rex)
{
	t_list	*last;
	t_list	*listb;

	listb = 0;
	last = ft_lstlast(*lista);
	while (check_finish(*lista) && count(*lista) != 3)
	{
		if (last->index <= number)
		{
			push(lista, &listb, rex);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(lista);
			write(1, "ra\n", 3);
		}
		last = ft_lstlast(*lista);
	}
	return (listb);
}

static void	sort_four(t_list **lista, t_rex *rex)
{
	t_list	*listb;

	listb = sort_ff(1, lista, rex);
	if (!listb)
		return ;
	if (check_finish(*lista))
		sort_three(lista);
	push(&listb, lista, rex);
	write(1, "pa\n", 3);
}

static void	sort_five(t_list **lista, t_rex *rex)
{
	t_list	*listb;

	listb = sort_ff(2, lista, rex);
	if (!listb)
		return ;
	else if (count(listb) == 1)
	{
		push(&listb, lista, rex);
		write(1, "pa\n", 3);
		return ;
	}
	if (check_finish(*lista))
		sort_three(lista);
	if (listb->index == 2)
	{
		swap(&listb);
		write(1, "sb\n", 3);
	}
	push(&listb, lista, rex);
	push(&listb, lista, rex);
	write(1, "pa\npa\n", 6);
}

void	sort_small(t_list **lista, t_rex *rex, int col)
{
	if (col == 2)
	{
		swap(lista);
		write(1, "sa\n", 3);
		return ;
	}
	if (col == 3)
	{
		sort_three(lista);
		return ;
	}
	if (col == 4)
	{
		sort_four(lista, rex);
		return ;
	}
	if (col == 5)
	{
		sort_five(lista, rex);
		return ;
	}
}
