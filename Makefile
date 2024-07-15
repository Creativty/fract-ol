# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aindjare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 20:09:58 by aindjare          #+#    #+#              #
#    Updated: 2024/07/15 11:05:57 by aindjare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -O3 -Ilib/mlx
LFLAGS	:=	-Llib/mlx -lmlx_Linux -lXext -lX11 -lm -lz

NAME	:=	fractol
OBJECTS	:=	atof.o string.o memory.o complex.o image.o state.o fractol.o \
			color.o color_hsl.o math.o julia.o mandelbrot.o destroy.o \
			easing.o arguments.o events.o program.o main.o

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CC) $(CFLAGS)	-o $@ $^ $(LFLAGS)

clean:
	rm -rf $(OBJECTS)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

.SECONDARY: $(OBJECTS)
