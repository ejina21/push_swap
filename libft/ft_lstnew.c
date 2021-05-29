#include "libft.h"

t_list	*ft_lstnew(int content, int flag, int index)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list->content = content;
	list->flag = flag;
	list->index = index;
	list->next = 0;
	return (list);
}
