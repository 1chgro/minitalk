/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:36:38 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/23 06:15:08 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

int	check_uni_bytes(unsigned char c)
{
	if (c < 128)
		return (1);
	else if ((c & (0b11100000)) == 0b11000000)
		return (2);
	else if ((c & (0b11110000)) == 0b11100000)
		return (3);
	else if ((c & (0b11111000)) == 0b11110000)
		return (4);
	return (0);
}

int	process_char(int *bits, char *byte, int *client_pid, int *pos)
{
	static unsigned char	utf8_buf[4];
	static int				remaining;

	if (++(*bits) == 8)
	{
		if (*pos == 0)
			remaining = check_uni_bytes(*byte);
		utf8_buf[(*pos)++] = *byte;
		if (--remaining == 0)
		{
			utf8_buf[*pos] = '\0';
			ft_printf("%s", utf8_buf);
			*pos = 0;
			kill (*client_pid, SIGUSR1);
		}
		if (*byte == '\0')
		{
			kill (*client_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		*bits = 0;
		*byte = 0;
	}
	return (0);
}

void	handle_sig(int signum, siginfo_t *info, void *context)
{
	static int			bits;
	static char			byte;
	static pid_t		client_pid;
	static int			pos;

	(void)context;
	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		bits = 0;
		byte = 0;
		pos = 0;
	}
	if (signum == SIGUSR2)
		byte |= (0b10000000 >> bits);
	if (process_char(&bits, &byte, &client_pid, &pos) == 1)
		return ;
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\nServer PID → %d\n", getpid());
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
