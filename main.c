/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:53 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/23 20:17:58 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	void	*mlx;

	if (argc != 2)
		return (0);
	read_map(argv[1], &game);

	void *mlx = mlx_init();

	return 0;
}
