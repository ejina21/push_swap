#include "push_swap.h"

void	make_index(t_list *list, int *arr)
{
	int	i;

	while (list)
	{
		i = 0;
		while (arr[i] != list->content)
			i++;
		list->index = i + 1;
		list = list->next;
	}
}

void	pull(t_rex *rex, int len)
{
	rex->next = 1;
	rex->max = len;
	rex->mid = rex->max / 2 + rex->next;
	rex->flag = 0;
}

int	check_finish(t_list *list)
{
	int	i;

	i = list->index;
	while (list)
	{
		if (list->index != i)
			return (1);
		i--;
		list = list->next;
	}
	return (0);
}
