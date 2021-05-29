#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*list;
	t_list	*begin;

	if (!lst)
		return (0);
	begin = ft_lstnew(f(lst->content), 0, 0);
	if (!begin)
		return (0);
	lst = lst->next;
	list = begin;
	while (lst)
	{
		list->next = ft_lstnew(f(lst->content), 0, 0);
		if (!list->next)
			ft_lstclear(&begin, del);
		lst = lst->next;
		list = list->next;
	}
	return (begin);
}
