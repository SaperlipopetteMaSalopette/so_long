/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 06:33:42 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/22 17:33:49 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (nbr >= 16)
		ft_putnbr_base(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
}

int	ft_print_hexa(unsigned int nbr, char *base)
{
	unsigned int	count;
	unsigned int	tmp;

	count = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	ft_putnbr_base(nbr, base);
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	return (count);
}
