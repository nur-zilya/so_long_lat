/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfast <hfast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:42:42 by hfast             #+#    #+#             */
/*   Updated: 2022/03/31 17:30:09 by hfast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <mlx.h>

typedef struct s_game
{
	int				x;
	int				y;
	int				h;
	int				w;
	int				hero;
	int				exit;
	int				collect;
	int				steps;
	int				win;
	int				x_start;
	int				y_start;
	int				y_st;
	int				x_st;
	void			*wall;
	void			*hero_i;
	void			*hero_left;
	void			*collectib;
	void			*exit_i;
	void			*back;
	void			*empty;
	void			*mlx;
	char			**map;
	void			*window;
	void			*enemy_0;
	void			*enemy_1;
	int				anim;
}	t_game;

int			map_validation(int argc, char *file);
int			ft_strend_cmp(char *name, char *end);
void		init_game(t_game *game);
void		init_image(t_game *game);
void		read_map(char	*map, t_game	*game);
int			error(char *str);
size_t		ft_strlen(const char *str);
void		fullfree(t_game *game);
char		**ft_malloc_free(char **mass);
char		**ft_split(char const *s, char c);
void		check_map(t_game *game);
void		check_counts(t_game *game);
void		check_walls(t_game *game);
void		len_strings_map(t_game	*game);
void		write_map(t_game	*game);
int			game_over(t_game *game);
int			hot_keys(int keycode, t_game *game);
char		*ft_itoa(int n);
int			update(t_game *game);
void		put_image_help(int y, int x, t_game	*game);
void		for_e(t_game *game);

#endif