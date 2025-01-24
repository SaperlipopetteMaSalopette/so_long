/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:43:18 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/25 14:15:38 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_check(const char *format, va_list *arg)
{
	if (*format == 'c')
		return (ft_print_char(va_arg(*arg, int)));
	else if (*format == 's')
		return (ft_print_string(va_arg(*arg, char *)));
	else if (*format == 'p')
		return (ft_print_pointer(va_arg(*arg, void *)));
	else if (*format == 'd')
		return (ft_putnbr(va_arg(*arg, int)));
	else if (*format == 'i')
		return (ft_putnbr(va_arg(*arg, int)));
	else if (*format == 'u')
		return (ft_print_unsigned_dec(va_arg(*arg, unsigned int)));
	else if (*format == 'x')
		return (ft_print_hexa(va_arg(*arg, unsigned int), "0123456789abcdef"));
	else if (*format == 'X')
		return (ft_print_hexa(va_arg(*arg, unsigned int), "0123456789ABCDEF"));
	else if (*format == '%')
		return (ft_print_char('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;

	i = 0;
	if (!str || *str == '\0')
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				i += type_check(str, &args);
		}
		else
			i += ft_print_char(*str);
		str++;
	}
	va_end(args);
	return (i);
}
