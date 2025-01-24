/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:04:20 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/24 23:07:53 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(t_game *game)
{
	int	coins;
	int	x;
	int	y;

	coins = 0;
	x = 0;
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'C')
				coins++;
			else
				x++;
		}
		y++;
	}
	if (coins <= 0)
	{
		ft_printf("There's not a single coin");
		return (-1);
	}
	else if (coins >= 1)
		return (coins);
}

int	count_coins_fill(t_game *game)
{
	int	coins;
	int	x;
	int	y;

	coins = 0;
	x = 0;
	y = 0;
	while (game->grid_two[y])
	{
		x = 0;
		while (game->grid_two[y][x])
		{
			if (game->grid_two[y][x] == 'C')
				coins++;
			else
				x++;
		}
		y++;
	}
	if (coins <= 0)
	{
		ft_printf("There's not a single coin");
		return (-1);
	}
	else if (coins >= 1)
		return (coins);
}

int	count_lines(int fd)
{
	int	line_count;
	char	*line;

	line_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		else
		{
			line_count++;
			free(line);
		}
		if (line_count <= 2)
			return (-1)
	}
	return (line_count);
}
