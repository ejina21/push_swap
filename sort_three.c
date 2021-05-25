#include "push_swap.h"

static void	sort_three_first(t_list **list)
{
	if ((*list)->index > (*list)->next->next->index)
	{
		swap(list);
		write(1, "sa\n", 3);
	}
	else
	{
		rotate(list);
		write(1, "ra\n", 3);
	}
}

static void	sort_three_sec(t_list **list)
{
	if ((*list)->next->index > (*list)->next->next->index)
	{
		rev_rotate(list);
		write(1, "rra\n", 4);
	}
	else
	{
		rotate(list);
		swap(list);
		write(1, "ra\nsa\n", 6);
	}
}

void	sort_three(t_list **lista)
{
	t_list	*list;

	list = *lista;
	if (list->index > list->next->index)
		sort_three_first(&list);
	else if (list->index < list->next->next->index)
		sort_three_sec(&list);
	else
	{
		rev_rotate(&list);
		swap(&list);
		write(1, "rra\nsa\n", 7);
	}
	*lista = list;
}
