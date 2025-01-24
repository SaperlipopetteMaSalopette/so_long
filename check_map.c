/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:46:40 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/25 00:15:05 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		return (-1);
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
			while (game->grid[y])
			{
				x = 0;
				while (game->grid[y][x])
				{
					free(game->grid[y][x]);
					x++;
				}
				y++;
			}
			return (-1);
		}
		free (line);
		i++;
	}
	game->grid[i] = 0;
	return (1);
}

int	get_line_length(t_game *game)
{
	int	length;

	length = ft_strlen(game->grid[0]);
	if (length > 0 && line [size -1] == '\n')
		length--;
	return (length);
}
