CC		= gcc
FLAGS	= -Wall -Werror -Wextra
NAME	= libftprintf.a
HEAD	= ft_printf.h
OBJS	= \
ft_printf.o ft_initialize_flags.o ft_check_cases.o Libft/ft_memset.o \
ft_set_conversion_flags.o ft_set_min_field_width.o ft_set_precision.o \
Libft/ft_isdigit.o ft_set_conversion_specifier.o ft_conversion.o \
ft_print_char_conversion.o ft_print_str_conversion.o ft_print_ptr_conversion.o \


all:		$(NAME)

bonus:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:		%.c $(HEAD)
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re