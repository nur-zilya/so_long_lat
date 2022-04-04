/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:19:56 by hfast             #+#    #+#             */
/*   Updated: 2022/03/31 17:52:32 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(int y, int x, t_game	*game, char c)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall, \
			x * 110, y * 110);
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->back, \
			x * 110, y * 110);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->hero_i, \
			x * 110, y * 110);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->exit_i, \
			x * 110, y * 110);
	if (c == 'V')
		put_image_help(y, x, game);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collectib, \
			x * 110, y * 110);
}

void	put_image_help(int y, int x, t_game	*game)
{
	if (game->anim < 100)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->enemy_0, \
			x * 110, y * 110);
		game->anim++;
	}
	else if (game->anim >= 100)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->enemy_1, \
			x * 110, y * 110);
		game->anim++;
		if (game->anim > 200)
			game->anim = 0;
	}
}

void	write_map(t_game	*game)
{
	int	y;
	int	x;

	mlx_clear_window(game->mlx, game->window);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image(y, x, game, game->map[y][x]);
			x++;
		}
		y++;
	}
}
