/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_dec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 06:08:02 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/21 15:43:08 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_utoa(unsigned int i)
{
	char			*str;
	unsigned int	len;
	unsigned int	n;

	len = ft_numlen(i);
	n = i;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = n % 10 + 48;
		n /= 10;
	}
	str[ft_numlen(i)] = '\0';
	return (str);
}

int	ft_print_unsigned_dec(unsigned int i)
{
	char	*str;
	int		size;

	if (i == 0)
		return (write(1, "0", 1));
	str = ft_utoa(i);
	ft_putstr(str);
	size = ft_strlen(str);
	free(str);
	return (size);
}
