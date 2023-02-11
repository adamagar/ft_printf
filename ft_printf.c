/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagar <aagar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:24:04 by aagar             #+#    #+#             */
/*   Updated: 2023/02/11 16:16:13 by aagar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(char c)
{
	int	val;

	val = write(1, &c, 1);
	return (val);
}

int	ft_check_format(char c, va_list *args)
{
	int	val;

	val = 0;
	if (c == 'c')
		val += print_character(va_arg(*args, int));
	if (c == '%')
		val += write(1, "%", 1);
	if (c == 'd' || c == 'i')
		val += print_number(va_arg(*args, int));
	if (c == 'u')
		val += print_unsigned_number(va_arg(*args, unsigned int));
	if (c == 'x')
		val += print_hex(va_arg(*args, unsigned int), 1);
	if (c == 'X')
		val += print_hex(va_arg(*args, unsigned int), 2);
	if (c == 'p')
	{
		val += write(1, "0x", 2);
		val += print_address(va_arg(*args, unsigned long int));
	}
	if (c == 's')
		val += print_string(va_arg(*args, char *));
	return (val);
}

int	ft_printf(const char *format, ...)
{
	int		val;
	int		i;
	va_list	args;

	val = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			val += write(1, &format[i], 1);
		else
		{
			val += ft_check_format(format[i + 1], &args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (val);
}
