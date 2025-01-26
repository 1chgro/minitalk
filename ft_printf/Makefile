NAME = libftprintf.a
SRCS =	ft_printf.c ft_printstr.c ft_printhex_lower.c ft_printhex_upper.c ft_printchar.c\
		ft_printpercent.c ft_printptr.c ft_print_decimal_integer.c ft_print_unsigned_decimal.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c ft_printf.h
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all