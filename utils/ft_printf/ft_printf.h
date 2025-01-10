/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachgue <olachgue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:04:20 by olachgue          #+#    #+#             */
/*   Updated: 2024/11/19 12:43:50 by olachgue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_print_formats(va_list args, const char format);
int	ft_printstr(char *str);
int	ft_printchar(char c);
int	ft_printpercent(void);
int	ft_printhex_upper(unsigned int n);
int	ft_printhex_lower(unsigned int n);
int	ft_printptr(void *ptr);
int	ft_print_digit_integer(int n);
int	ft_print_unsigned_decimal(unsigned int n);

#endif