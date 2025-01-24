/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:10:33 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/25 00:04:47 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr_2(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (-1);
		str++;
	}
	return (1);
}
