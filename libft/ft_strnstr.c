/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 01:34:06 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/11 15:56:56 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *huge, const char *tiny, size_t len)
{
	size_t	len_tiny;

	len_tiny = 0;
	if (!tiny[0])
		return ((char *)huge);
	len_tiny = ft_strlen(tiny);
	while (*huge && len >= len_tiny)
	{
		if (*huge == *tiny && ft_strncmp(huge, tiny, len_tiny) == 0)
			return ((char *)huge);
		huge++;
		len--;
	}
	return (NULL);
}
