#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_rex
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}				t_rex;
int		check(char *str, int *array, int len);
void	swap(t_list **list);
void	push(t_list **a, t_list **b, t_rex *rex);
void	rotate(t_list **list);
void	rev_rotate(t_list **list);
void	sort_arr(int *array, int lo, int hi);
int		parse(t_list **list, int **array, char **argv, int argc);
int		parse_count(int argc, char **argv);
int		count_list(t_list *list, int flag, t_rex *rex);
int		count(t_list *list);
int		count_list_push(t_list *listb);
void	make_index(t_list *list, int *arr);
void	pull(t_rex *rex, int len);
int		check_finish(t_list *list);
void	give_to_b(t_list **lista, t_list **listb, t_rex *rex);
void	sort_small(t_list **lista, t_rex *rex, int col);
void	rt_next(t_list **lista, t_rex *rex);
void	sort_three(t_list **lista);

int		get_next_line(int fd, char **line);
#endif
