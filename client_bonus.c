/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:08:03 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/23 06:05:23 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

static int	skip_spaces_and_check_sign(int *i, const char *str)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			sign = -1;
		}
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	result;
	long long	tmp;

	result = 0;
	tmp = 0;
	i = 0;
	sign = skip_spaces_and_check_sign(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp *= 10;
		tmp += str[i] - '0';
		if (tmp / 10 < result)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		result = tmp;
		i++;
	}
	return (result * sign);
}

void	message_ack(int sig)
{
	if (sig == SIGUSR2)
	{
		write(1, "message sent ✅\n", 18);
	}
}

void	send_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j++ < 8)
	{
		if (((c >> (8 - j)) & 1) == 1)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(200);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	pid_t	server_pid;

	if (argc != 3 || ft_atoi(argv[1]) == 0)
	{
		ft_printf("\nInvalid input!\n");
		ft_printf("Usage: ./client <PID> <message>\n");
		return (1);
	}
	if (kill(ft_atoi(argv[1]), 0) == -1)
	{
		ft_printf("Invalid PID!\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, message_ack);
	signal(SIGUSR2, message_ack);
	i = 0;
	while (argv[2][i])
	{
		send_signal(server_pid, argv[2][i]);
		usleep(30);
		i++;
	}
	send_signal(server_pid, '\0');
}
