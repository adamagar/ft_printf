/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagar <aagar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:20:09 by aagar             #+#    #+#             */
/*   Updated: 2023/02/11 16:15:19 by aagar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int num)
{
	long long	n;
	int			val;

	n = num;
	val = 0;
	if (n < 0)
	{
		val += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		val += print_number(n / 10);
		val += print_number(n % 10);
	}
	if (n < 10)
		val += print_character(n + 48);
	return (val);
}

int	print_address(unsigned long int num)
{
	int	val;

	val = 0;
	if (num >= 16)
	{
		val += print_address(num / 16);
		val += print_address(num % 16);
	}
	if (num < 16)
	{
		if (num < 10)
			val += print_character(num + 48);
		else
			val += print_character(num + 87);
	}
	return (val);
}

int	print_unsigned_number(unsigned int num)
{
	int	val;

	val = 0;
	if (num >= 10)
	{
		val += print_unsigned_number(num / 10);
		val += print_unsigned_number(num % 10);
	}
	if (num < 10)
		val += print_character(num + 48);
	return (val);
}

int	print_hex(unsigned int num, int s)
{
	int	val;

	val = 0;
	if (num >= 16)
	{
		val += print_hex(num / 16, s);
		val += print_hex(num % 16, s);
	}
	if (num < 16)
	{
		if (num < 10)
			val += print_character(num + 48);
		else
		{
			if (s == 1)
				val += print_character(num + 87);
			else
				val += print_character(num + 55);
		}
	}
	return (val);
}

int	print_string(char	*str)
{
	int	val;

	val = 0;
	if (!str)
		str = "(null)";
	while (*str)
		val += write(1, str++, 1);
	return (val);
}
