/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 23:22:17 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/10 14:53:09 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	j;
	unsigned char	*sentence;

	j = (unsigned char)c;
	i = 0;
	sentence = (unsigned char *)str;
	while (i < n)
	{
		if (sentence[i] == j)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
