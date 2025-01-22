/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:25:22 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/10 14:37:40 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t		i;
	char		ch;

	i = ft_strlen(str);
	ch = (char)c;
	if (ch == '\0')
		return ((char *)&str[i]);
	while (i > '\0')
	{
		i--;
		if (str[i] == ch)
			return ((char *)&str[i]);
	}
	return (NULL);
}
