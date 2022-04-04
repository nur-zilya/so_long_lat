# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfast <hfast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:22:57 by hirebbec          #+#    #+#              #
#    Updated: 2022/03/31 15:42:12 by hfast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = so_long.c map_valid.c init.c read_map.c split.c utils.c check_map.c \
			parsing.c write_map.c game_over.c keys.c itoa.c animation.c

FILES_BONUS = 
					
OBJS = $(FILES:%.c=%.o)

OBJS_BONUS = $(FILES_BONUS:%.c=%.o)

MLX_FLAGS = -L . -lmlx -framework OpenGL -framework AppKit

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

.PHONY:all clean fclean re bonus
