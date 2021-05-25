#include "push_swap.h"

int	count_list(t_list *list, int flag, t_rex *rex)
{
	int	i;

	i = 0;
	rex->max = 0;
	while (list)
	{
		if (list->flag == flag)
		{
			if (list->index > rex->max || !rex->max)
				rex->max = list->index;
			i++;
		}
		else
		{
			i = 0;
		}
		list = list->next;
	}
	rex->mid = (rex->max + rex->next) / 2;
	return (i);
}

int	count(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	count_list_push(t_list *listb)
{
	int	i;
	int	res;

	i = 0;
	while (listb)
	{
		listb = listb->next;
		i++;
	}
	res = i / 2 + 1;
	return (res);
}
