/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 01:06:41 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/03 01:33:49 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*j1;
	const unsigned char	*j2;
	size_t				i;

	j1 = (const unsigned char *)ptr1;
	j2 = (const unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (j1[i] != j2[i])
			return (j1[i] - j2[i]);
		i++;
	}
	return (0);
}
