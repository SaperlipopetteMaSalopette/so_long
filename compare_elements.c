/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thofstet <thofstet@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:03:18 by thofstet          #+#    #+#             */
/*   Updated: 2025/01/24 23:04:04 by thofstet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compare_exit(t_game *game)
{
	if (check_exit_fill(game) == check_exit(game))
		return (1);
	else
		return (-1);
}

int	compare_coins(t_game *game)
{
	int	coins;
	int	coins_fil;

	coins = count_coins(game);
	coins_fill = count_coins_fill(game);
	if (coins_fill != coins)
		return (-1);
	else
		return(1);
}
