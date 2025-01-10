/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:36:38 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/10 22:47:55 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft/libft.h"
#include "utils/ft_printf/ft_printf.h"
#include <signal.h>

void	handlesig(int sig, siginfo_t *info, void *context)
{
	static int				bit_count;
	static unsigned char	current_byte;

	(void)context;
	current_byte <<= 1;
	if (sig == SIGUSR2)
		current_byte |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", current_byte);
		bit_count = 0;
		current_byte = 0;
		if (info && info->si_pid)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("usage: ./server\n");
		return (1);
	}
	ft_printf("server pid: %d\n", getpid());
	sa.sa_sigaction = handlesig;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
