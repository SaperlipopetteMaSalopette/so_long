/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:21 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/25 00:15:03 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1000
# define KEY_W 119
# define KEY_A 197
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include "GNL/get_next_line.h"
#include "libft/libft.h"
#include "mlx/mlx.h"
#include "ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**grid;
	char	**grid_two;
	int		length;
	int		height;
	int		px;
	int		py;
	int		coin_fill;
	int		exit_fill;
} t_game;

int	check_map(t_game *game);
int	check_exit(t_game *game);
int	check_exit_fill(t_game *game);
int	check_coins(t_game *game);
int	check_spawn(t_game *game);
int	check_borders(t_game *game);
int	check_length(t_game *game);
int	read_map(char *file, t_game *game);
int	fill_grid(int fd, t_game *game);
int	get_line_length(t_game *game);
int	compare_exit(t_game *game);
int	compare_coins(t_game *game);
int	count_coins(t_game *game);
int	count_coins_fill(t_game *game);
int	count_lines(int fd);
int	check_flood(t_game *game);
int	fill_grid_two(int fd, t_game *game);

#endif
