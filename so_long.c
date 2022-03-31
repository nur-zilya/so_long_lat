/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:44:20 by hfast             #+#    #+#             */
/*   Updated: 2022/03/25 19:13:27 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
    t_game  game;
    
	map_validation(argc, argv[1]);
	game.mlx = mlx_init();
	init_game(&game);
	read_map(argv[1], &game);
	check_map(&game);
	len_strings_map(&game);
	check_walls(&game);
	check_counts(&game);
	game.window = mlx_new_window(game.mlx, game.x * 110, \
	 	game.y * 110, "so_long");
    init_image(&game);
	write_map(&game);
	mlx_hook(game.window, 17, 0, game_over, &game);
	mlx_hook(game.window, 2, (1L << 0), hot_keys, &game);
	mlx_loop(game.mlx);
}
