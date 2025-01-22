/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:55:51 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/01 17:06:08 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int i, size_t len)
{
	size_t			j;
	unsigned char	*ptr;

	j = 0;
	ptr = (unsigned char *)str;
	while (j < len)
		ptr[j++] = (unsigned char)i;
	return (str);
}
