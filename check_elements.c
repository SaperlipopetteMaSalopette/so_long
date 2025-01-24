/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:04:48 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/24 23:09:32 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(game->grid[y])
	{
		x = 0;
		while(game->grid[y][x])
		{
			if (game->grid[y][x] != '1' && game->grid != '0'
				 && game->grid != 'C' && game->grid != 'P'
				&& game->grid != 'E' && game->grid != "\n")
				return (-1);
			else
				x++;
		}
		y++;
	}
	game->length = x;
}

int	check_exit(t_game *game)
{
	int	exit_found;
	int	x;
	int	y;

	exit_found = 0;
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'E')
				exit_found++;
			else
				x++;
		}
		y++;
	}
	if (exit_found == 4)
		return (1);
	else if (exit_found > 4)
	{
		ft_printf("There's more than one exit");
		return (-1);
	}
	else
	{
		ft_printf("Y a un problème bg");
		return (-1);
	}
	return (0);
}

int	check_exit_fill(t_game *game)
{
	int	exit_found;
	int	x;
	int	y;

	exit_found = 0;
	y = 0;
	while (game->grid_two[y])
	{
		x = 0;
		while (game->grid_two[y][x])
		{
			if (game->grid_two[y][x] == 'E')
				exit_found++;
			else
				x++;
		}
		y++;
	}
	if (exit_found == 4)
		return (1);
	else if (exit_found > 4)
	{
		ft_printf("There's more than one exit");
		return (-1);
	}
	else
	{
		ft_printf("Y a un problème bg");
		return (-1);
	}
	return (0);
}

int	check_coins(t_game *game)
{
	int	coins;
	int	x;
	int	y;

	coins = 0;
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
	if (coins < 1)
	{
		ft_printf("There's not a single coin bruuh");
		return (-1);
	}
	else if (coins > 1)
	{
		ft_printf("There is/are %d coins", &coins);
		return (coins);
	}
	return (0);
}

int	check_spawn(t_game *game)
{
	int	spawn_found;
	int	x;
	int	y;

	spawn_found = 0;
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[x][y] == 'P')
				spawn_found++;
			else
				x++;
		}
		y++;
	}
	if (spawn_found == 1)
		return (1);
	else if (spawn_found > 1)
	{
		ft_printf("There's more than one spawn");
		return (-1);
	}
	else
	{
		ft_printf("Y a un problème bg");
		return (-1);
	}
	return (0);
}

int	check_borders(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = game->heigth - 1;
	j = game->length - 1;

	while (game->grid[0][x])
	{
		if (game->grid[0][x] != '1' || game->grid[game->heigth - 1][x] != '1')
			return (-1);
		x++;
	}
	while (game->grid[y][1])
	{
		if (game->grid[y][1] != '1' || game->grid[y][game->length - 1] != '1')
			return (-1);
		y++;
	}
	return (1);
}

int	check_length(t_game *game)
{
	int	i;
	int	length;
	int	next_length;

	i = 0;
	length = get_line_length(game->grid[i]);
	while (game->grid[i])
	{
		next_length = get_line_length(game->grid[i + 1]);
		i++;
		if (length != next_length)
			return (-1);
	}
	return (1);
}
