# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czerini <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/22 16:43:15 by czerini           #+#    #+#              #
#    Updated: 2023/10/22 16:56:20 by czerini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC			= ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha \
			  ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr \
			  ft_memcmp ft_memcpy ft_memmove ft_memset \
			  ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
			  ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri \
			  ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi \
			  ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr \
			  ft_tolower ft_toupper

B_SRC		= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
		  ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

SRCS		= $(addsuffix .c, ${SRC})

B_SRCS		= $(addsuffix .c, ${B_SRC})

HEAD		= ./includes/ 

OBJS		= ${SRCS:.c=.o}

B_OBJS		= ${B_SRCS:.c=.o}

NAME		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

bonus:		${B_OBJS}
			${AR} ${NAME} ${B_OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re

