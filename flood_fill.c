/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:06:43 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/24 23:18:13 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_flood(t_game *game)
{
	int fd;
	int	coins_fill;
	int	exits_fill;

	fd = 0;
	coins = coin_count(game->grid);
	exits = 0;
	close (fd);
	fd = (open(file, 0_RDONLY));
	if (!fill_grid_two(fd, game))
		return (-1);
	flood_fill(game, game->px, game->py);
	if (compare_coins(game) != 1 || compare_exit(game) != 1 || check_exit_fill(game) != 1)
		return (-1)
	return (1);
}

int	fill_grid_two(int fd, t_game *game)
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
		game->grid_two[i] = ft_strdup(line);
		if (!game->grid_two[i])
		{
			while (game->grid_two[y])
			{
				x = 0;
				while (game->grid_two[y][x])
				{
					if (game->grid_two[x][y])
						free(game->grid_two[x][y]);
					else
						x++;
				}
				y++;
			}
			/* creer une fonction pour free une grille */
			return (-1);
		}
		free (line);
		i++;
	}
	game->grid[i] = 0;
	return (1);
}
