NAME		= libftprintf.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f

SRCS 		=  ft_printf.c ft_utility.c ft_utility2.c ft_utility3.c ft_flags.c ft_print_char.c ft_print_string.c ft_print_pointer.c ft_print_intdec.c ft_print_uns_dec.c ft_print_hex.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar rcs $(NAME) $(OBJS)

.c.o: 	
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean