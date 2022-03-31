/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:47:02 by hfast             #+#    #+#             */
/*   Updated: 2022/03/26 19:00:22 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->hero = 0;
	game->exit = 0;
	game->collect = 0;
	game->steps = 0;
	game->win = 0;
}

void	init_image(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"pict/cloud.xpm",
			&game->h, &game->y);
	game->back = mlx_xpm_file_to_image(game->mlx,
			"pict/Bg.xpm",
			&game->h, &game->y);
    game->exit_i = mlx_xpm_file_to_image(game->mlx,
			"pict/door.xpm",
			&game->h, &game->y);
    game->collectib = mlx_xpm_file_to_image(game->mlx,
			"pict/crystal.xpm",
			&game->h, &game->y);
    game->hero_i = mlx_xpm_file_to_image(game->mlx,
			"pict/fox.xpm",
			&game->h, &game->y);
	game->hero_left = mlx_xpm_file_to_image(game->mlx,
			"pict/fox_left.xpm",
			&game->h, &game->y);
}
