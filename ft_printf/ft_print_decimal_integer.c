/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:29:01 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/24 13:08:56 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_integer(int n)
{
	int		length;
	long	num;

	length = 0;
	num = n;
	if (num < 0)
	{
		length += ft_printchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		length += ft_print_digit_integer(num / 10);
	}
	length += ft_printchar((num % 10) + '0');
	return (length);
}
