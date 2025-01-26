/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:27:06 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/24 14:31:18 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_lower(unsigned int n)
{
	int		length;
	char	*hex_digits;

	length = 0;
	hex_digits = "0123456789abcdef";
	if (n >= 16)
		length += ft_printhex_lower(n / 16);
	length += write(1, &hex_digits[n % 16], 1);
	return (length);
}
