#include "push_swap.h"

void	swap(t_list **list)
{
	 int	tmp;
	 int	tmp1;
	 int	tmp2;
	 t_list	*lst;

	 lst = *list;
	 if (!lst || !lst->next)
		 return ;
	 tmp = 0;
	 tmp1 = 0;
	 tmp2 = 0;
	 while (lst->next->next)
		 lst = lst->next;
	 tmp = lst->content;
	 tmp1 = lst->flag;
	 tmp2 = lst->index;
	 lst->content = lst->next->content;
	 lst->flag = lst->next->flag;
	 lst->index = lst->next->index;
	 lst->next->content = tmp;
	 lst->next->flag = tmp1;
	 lst->next->index = tmp2;
}

void	push(t_list **a, t_list **b, t_rex *rex)
{
	t_list	*la;
	t_list	*lb;
	t_list	*tmp;

	la = *a;
	lb = *b;
	if (!la)
		return ;
	while (la->next)
	{
		if (la->next->next)
			la = la->next;
		else
		{
			tmp = la;
			la = la->next;
			tmp->next = 0;
		}
	}
	la->flag = rex->flag;
	ft_lstadd_back(b, la);
	if (*a == la)
		*a = 0;
}

void	rotate(t_list **list)
{
	t_list	*la;
	t_list	*tmp;

	la = *list;
	if (!la || !la->next)
		return ;
	while (la->next)
	{
		if (la->next->next)
			la = la->next;
		else
		{
			tmp = la;
			la = la->next;
			tmp->next = 0;
		}
	}
	ft_lstadd_front(list, la);
}

void	rev_rotate(t_list **list)
{
	t_list	*tmp;
	t_list	*la;

	la = *list;
	tmp = *list;
	if (!la || !la->next)
		return ;
	tmp = tmp->next;
	*list = tmp;
	la->next = 0;
	ft_lstadd_back(list, la);
}
