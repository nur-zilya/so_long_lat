/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:56:24 by hfast             #+#    #+#             */
/*   Updated: 2022/03/25 18:49:38 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(char *message)
{
	printf(" Error\n    %s\n", message);
	exit (1);
}

size_t	ft_strlen(const char *str)
{
	size_t		count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	fullfree(t_game *game)
{
	int		i;

	i = -1;
	while (game->map[++i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
	}
	free(game->map);
	game->map = NULL;
}

