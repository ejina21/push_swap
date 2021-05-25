SRCS	=	$(wildcard *.c)

OBJS	=	$(SRCS:.c=.o)

BSRCS	=	bonuses/get_next_line.c	\
			bonuses/checker.c		\
			help_functions.c		\
			instructions.c			\
			count_functions.c		\
			sort_array.c			\
			parse.c					\
			check.c					

BOBJS	=	$(BSRCS:.c=.o)

NAME	=	push_swap

BNAME	=	checker

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror 

RM		=	rm -f

all:		make_libft $(NAME)

$(NAME):	$(OBJS) libft/libft.a
			$(CC) $(CFLAGS)  -o $@ $^
	
%.o:		%.c push_swap.h libft/libft.h
			$(CC) $(CFLAGS) -c $< -o $@

$(BNAME):	$(BOBJS) libft/libft.a
			$(CC) $(CFLAGS) -o $@ $^

make_libft:
			@$(MAKE) -C libft/

clean:
			$(RM) $(OBJS) $(BOBJS)
			@$(MAKE) -C libft/ clean

fclean:		clean
			$(RM) $(NAME) $(BNAME)
			@$(MAKE) -C libft/ fclean

re:			fclean all

.PHONY:		all make_libft clean fclean re
