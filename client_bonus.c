/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:43:58 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/10 22:45:00 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft/libft.h"
#include "utils/ft_printf/ft_printf.h"
#include <signal.h>

void	ack_receive(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("ACK success\n");
}

void	action(pid_t server_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

void	send_message(pid_t server_pid, char *message)
{
	int	i;

	if (!message)
		return ;
	signal(SIGUSR1, ack_receive);
	i = 0;
	while (message[i])
	{
		action(server_pid, message[i]);
		i++;
	}
	message[i] = '\0';
	action(server_pid, message[i]);
}

int	main(int ac, char **av)
{
	char	*message;
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_printf("usage: ./client <server_pid> <message>\n");
		return (1);
	}
	message = av[2];
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_printf("error: not a valid server_pid\n");
		return (1);
	}
	if (kill(server_pid, 0) == -1)
	{
		ft_printf("error: server_pid doesn't exist\n");
		return (1);
	}
	send_message(server_pid, message);
	return (0);
}
