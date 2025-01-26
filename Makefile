CC = cc
FLAGS = -Wall -Werror -Wextra
SRCS = client.c server.c utils.c
OBJS = ${SRCS:.c=.o}

SRCSB = client_bonus.c server_bonus.c utils.c
OBJSB = ${SRCSB:.c=.o}
PRINTF=ft_printf/libftprintf.a
NAME = client server
NAMEB = client_bonus server_bonus

all: $(NAME)

bonus: $(NAMEB)

client: client.o
	make -s -C ft_printf
	$(CC) $(FLAGS) $(PRINTF) $^ -o $@

server: server.o
	make -s -C ft_printf
	$(CC) $(FLAGS) $(PRINTF) $^ -o $@

client_bonus: client_bonus.o
	make -s -C ft_printf
	$(CC) $(FLAGS) $(PRINTF) $^ -o $@

server_bonus: server_bonus.o
	make -s -C ft_printf
	$(CC) $(FLAGS) $(PRINTF) $^ -o $@

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@make clean -s -C ft_printf
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	@make fclean -s -C ft_printf
	rm -rf $(NAME) $(NAMEB)

re: fclean all
