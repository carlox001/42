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

NAME = so_long

PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

SRC = so_long.c get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -g -Ift_printf -Ilibft

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -Lft_ptintf -Llibft

all: $(NAME) $(PRINTF) $(LIBFT)

minilibx:
	@$(MAKE) -C minilibx-linux

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): minilibx $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(PRINTF) $(LIBFT) $(CFLAGS)

clean:
	rm *.o /*.o ft_printf/*.o libft/*.o

fclean: clean
	$(RM)

re: fclean all

.PHONY: all clean fclean re