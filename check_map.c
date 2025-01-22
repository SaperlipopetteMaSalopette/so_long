/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:46:40 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/21 22:47:26 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	read_map(char *file, t_game *game)
{
	int	fd;

	fd = open(file, 0_RDONLY);
	open(fd, 0_RDONLY);
	if (fd < 0)
		return (-1);
	game->height = count_lines(fd);
	if (game->height <= 2)
		return (-1);
	close (fd);
	fd = (open(file, 0_RDONLY));
	if (!fill_grid(fd, game))


}

int	fill_grid(int fd, t_game *game)
{
	char	**grid;
	int		i;
	char	*line;

	i = 0;
	game->grid = (char **)malloc(sizeof(char *) * game->height + 1);
	if (!game->grid)
		return (-1);
	while (i != game->height)
	{
		line = get_next_line(fd);
		if (!line)
			return (-1);
		game->grid[i] = ft_strdup(line);
		if (!game->grid[i])
		{
			/* creer une fonction pour free une grille */
			return (-1);
		}
		free (line);
		i++;
	}
	game->grid[i] = 0;
	return (1);
}

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

int	get_line_length(t_game *game);
{
	int	length;

	length = ft_strlen(game->grid[0]);
	if (length > 0 && line [size -1] == '\n')
		length--;
	return (length);
}

int	size_map(t_game *game)
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
