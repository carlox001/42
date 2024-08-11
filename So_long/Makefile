# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czerini <czerini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 15:10:41 by czerini           #+#    #+#              #
#    Updated: 2024/08/11 19:12:17 by czerini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

minilibx:
	@$(MAKE) -C minilibx-linux

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): minilibx $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(CFLAGS)

clean:
	rm *.o /*.o

fclean: clean
	$(RM)

re: fclean all

.PHONY: all clean fclean re