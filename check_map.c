/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:08:02 by hfast             #+#    #+#             */
/*   Updated: 2022/03/31 16:54:06 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(char c, t_game *game)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1' && c != 'V')
	{
		fullfree(game);
		error("Character is not valid\n");
	}
}

void	check_map(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			check_char(game->map[i][j], game);
			if (game->map[i][j] == 'P')
			{
				game->hero += 1;
				game->y_st = i;
				game->x_st = j;
			}
			if (game->map[i][j] == 'E')
				game->exit += 1;
			if (game->map[i][j] == 'C')
				game->collect += 1;
		}
	}
	game->x = j;
	game->y = i;
}
