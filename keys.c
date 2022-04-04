/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:34:59 by hfast             #+#    #+#             */
/*   Updated: 2022/03/31 17:30:04 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	write_steps(t_game	*game)
{
	printf("Steps: %d\n", game->steps);
}

static void	step_to(int y, int x, t_game	*game)
{
	game->map[game->y_st + y][game->x_st + x] = 'P';
	game->map[game->y_st][game->x_st] = '0';
	game->y_st = game->y_st + y;
	game->x_st = game->x_st + x;
	game->steps += 1;
	write_steps(game);
}

static void	steps_manage(int y, int x, t_game *game)
{
	if (game->map[game->y_st + y][game->x_st + x] != 1)
	{
		if (game->collect == 0)
			game->win = 1;
		if (game->win == 1 && game->map[game->y_st + y][game->x_st + x] == 'E')
			for_e(game);
		else if (game->map[game->y_st + y][game->x_st + x] == 'C')
		{
			game->collect -= 1;
			step_to(y, x, game);
		}
		else if (game->map[game->y_st + y][game->x_st + x] == 'V')
			game_over(game);
		else if (game->map[game->y_st + y][game->x_st + x] == '0')
			step_to(y, x, game);
		if (y == 0 && x == -1)
			game->hero_i = game->hero_left;
		else if (y == 0 && x == 1)
			game->hero_i = mlx_xpm_file_to_image(game->mlx, "pict/fox.xpm", \
			&game->h, &game->y);
		write_map(game);
	}
}

void	for_e(t_game *game)
{
	game->steps += 1;
	write_steps(game);
	game_over(game);
}

int	hot_keys(int keycode, t_game *game)
{
	char	*s;

	s = ft_itoa(game->steps);
	if (keycode == 0)
		steps_manage(0, -1, game);
	if (keycode == 2)
		steps_manage(0, 1, game);
	if (keycode == 13)
		steps_manage(-1, 0, game);
	if (keycode == 1)
		steps_manage(1, 0, game);
	if (keycode == 53)
		exit(0);
	mlx_put_image_to_window(game->mlx, game->window, game->wall, \
		0 * 110, 0 * 110);
	mlx_put_image_to_window(game->mlx, game->window, game->wall, \
		1 * 110, 0 * 110);
	mlx_string_put(game->mlx, game->window, 3, 1, 0x4B0082, "Steps: ");
	mlx_string_put(game->mlx, game->window, 65, 1, 0x4B0082, s);
	free(s);
	return (0);
}
