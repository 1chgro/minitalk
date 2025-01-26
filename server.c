/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:38:40 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/23 23:25:31 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char		byte;
	static int		counter;
	static pid_t	client_pid;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (info->si_pid != client_pid)
	{
		client_pid = 0;
		counter = 0;
		byte = 0;
	}
	if (signum == SIGUSR2)
		byte |= (0b10000000 >> counter);
	if (++counter == 8)
	{
		counter = 0;
		if (byte == '\0')
		{
			write(1, "\n", 1);
		}
		write(1, &byte, 1);
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\nServer PID →  %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
