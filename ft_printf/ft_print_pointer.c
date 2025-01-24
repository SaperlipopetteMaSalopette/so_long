/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:44:24 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/22 14:46:00 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbrbase(unsigned long tmp, char *base)
{
	int	count;

	count = 0;
	if (tmp >= 16)
		ft_putnbrbase(tmp / 16, base);
	count += write(1, &base[tmp % 16], 1);
	return (count);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	count;
	unsigned long	tmp;
	char			*basehexa;

	count = write(1, "0x", 2);
	tmp = (unsigned long)ptr;
	basehexa = "0123456789abcdef";
	if (tmp == 0)
		count += write(1, "0", 1);
	else
	{
		ft_putnbrbase(tmp, basehexa);
		while (tmp > 0)
		{
			tmp /= 16;
			count++;
		}
	}
	return (count);
}
