/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:12:49 by hfast             #+#    #+#             */
/*   Updated: 2022/04/01 14:43:59 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_counts(t_game *game)
{
	if (game->hero != 1 || game->collect < 1 || game->exit < 1)
	{
		fullfree(game);
		error("There is no hero/collectib. or exit\n");
	}
}

void	check_walls(t_game *game)
{
	int		y;
	int		x;

	y = -1;
	while (game->y > ++y)
	{
		x = -1;
		while (game->x > ++x)
		{
			if (game->map[0][x] != '1' || game->map[game->y - 1][x] != '1')
			{
				fullfree(game);
				error("HOLES (in x)\n");
			}
			if (game->map[y][0] != '1' || game->map[y][game->x - 1] != '1')
			{
				printf("y = %d, x = %d\n", y, x);
				fullfree(game);
				error("HOLES (in y)\n");
			}
		}
	}
}

void	len_strings_map(t_game	*game)
{
	int		i;

	i = -1;
	while (game->y > ++i)
	{
		if (ft_strlen(game->map[i]) != ft_strlen(game->map[0]))
		{
			fullfree(game);
			error("Walls are awry\n");
		}
	}
}
