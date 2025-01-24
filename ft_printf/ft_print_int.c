/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:35:01 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/25 14:04:35 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int				nb;
	unsigned int	i;

	i = 1;
	nb = n;
	if (!n)
		return (-1);
	if (n < 0 && n != -2147483648)
	{
		nb = -n;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	ft_print_int(nb);
	if (nb == -2147483648)
		return (11);
	return (i);
}
