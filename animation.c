/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:35:09 by hfast             #+#    #+#             */
/*   Updated: 2022/03/31 18:00:29 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update(t_game *game)
{
	int		i;
	char	*s;

	s = ft_itoa(game->steps);
	i = 0;
	write_map(game);
	mlx_string_put(game->mlx, game->window, 3, 1, 0x4B0082, "Steps: ");
	mlx_string_put(game->mlx, game->window, 65, 1, 0x4B0082, s);
	return (1);
}
