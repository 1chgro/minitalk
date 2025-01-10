/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:58:36 by olachgue          #+#    #+#             */
/*   Updated: 2025/01/10 05:34:52 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length += ft_print_unsigned_decimal(n / 10);
	length += ft_printchar((n % 10) + '0');
	return (length);
}
