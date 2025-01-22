/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:41:48 by thofstet          #+#    #+#             */
/*   Updated: 2024/10/13 17:24:28 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_mem(char **result, size_t i)
{
	while (i--)
		free(result[i]);
	free(result);
	return (NULL);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*result;

	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s, n);
	result[n] = '\0';
	return (result);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char		**results;
	size_t		i;
	const char	*start;

	i = 0;
	results = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !results)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				++s;
			results[i] = ft_strndup(start, s - start);
			if (!results[i])
				return (free_mem(results, i));
			i++;
		}
		else
			++s;
	}
	results[i] = 0;
	return (results);
}
