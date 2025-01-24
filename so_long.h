/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:30:21 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/24 22:12:54 by thofstet         ###   ########.fr       */
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

#endif
