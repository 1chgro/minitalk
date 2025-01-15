SRCS=client.c server.c
OBJS= ${SRCS:.c=.o}
SRCSB=client_bonus.c server_bonus.c
OBJSB= ${SRCSB:.c=.o}
FLAGS= -Wall -Werror -Wextra
PRINTF=utils/ft_printf/libftprintf.a
LIBFT=utils/libft/libft.a


all: client server
bonus: client_bonus server_bonus

client: client.o
	@make -s -C utils/ft_printf
	@make -s -C utils/libft
	cc $(FLAGS) $(PRINTF) $(LIBFT) $< -o $@

server: server.o
	@make -s -C utils/ft_printf
	@make -s -C utils/libft
	cc $(FLAGS) $(PRINTF) $(LIBFT) $< -o $@
client_bonus: client_bonus.o
	@make -s -C utils/ft_printf
	@make -s -C utils/libft
	cc $(FLAGS) $(PRINTF) $(LIBFT) $< -o $@

server_bonus: server_bonus.o
	@make -s -C utils/ft_printf
	@make -s -C utils/libft
	cc $(FLAGS) $(PRINTF) $(LIBFT) $< -o $@


%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make -s clean -C utils/ft_printf
	@make -s clean -C utils/libft
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	@make -s fclean -C utils/ft_printf
	@make -s clean -C utils/libft
	rm -rf client server server_bonus client_bonus

re: fclean all bonus