/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagar <aagar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:32:16 by aagar             #+#    #+#             */
/*   Updated: 2023/02/11 16:15:26 by aagar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	print_number(int num);
int	print_character(char c);
int	ft_check_format(char c, va_list *args);
int	ft_printf(const char *format, ...);
int	print_address(unsigned long int num);
int	print_unsigned_number(unsigned int num);
int	print_hex(unsigned int num, int s);
int	print_string(char	*str);
#endif