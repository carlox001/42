# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czerini <czerini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 15:10:41 by czerini           #+#    #+#              #
#    Updated: 2024/08/22 15:48:34 by czerini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC = test.c

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

minilibx:
	@$(MAKE) -C minilibx-linux

.c.o:
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(NAME): minilibx $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(MLX_FLAGS) -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re