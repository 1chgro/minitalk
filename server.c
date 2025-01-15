/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:38:40 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/15 00:32:09 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/libft/libft.h"
#include "utils/ft_printf/ft_printf.h"
#include <signal.h>

void	handle(int sig)
{
	static int				bit_count;
	static unsigned char	current_byte;

	current_byte <<= 1;
	if (sig == SIGUSR2)
		current_byte |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_byte == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_byte);
		bit_count = 0;
		current_byte = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("usage: ./server\n");
		return (1);
	}
	ft_printf("server pid: %d\n", getpid());
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	while (1)
		pause();
	return (0);
}
