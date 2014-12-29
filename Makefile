# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaggery <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 14:19:12 by aaggery           #+#    #+#              #
#    Updated: 2014/12/29 16:04:31 by aaggery          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bin/fdf

SOURCES = src/fdf.c \
		  src/map.c \
		  src/draw.c \
		  src/events.c \
		  src/tools.c \
		  src/get_next_line.c

INCLUDES = inc/

OBJECTS = $(subst src,obj,$(subst .c,.o,$(SOURCES)))

LIBSDIR = -L ./lib
LIBS = -lft -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

LIBFT = libft/libft.a
MLX = mlx/libmlx.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) $(FRAMEWORK) $(LIBSDIR) $(LIBS) -o $(NAME)

$(LIBFT): ./libft
	@(cd ./libft && $(MAKE))
	cp ./libft/bin/libft.a ./lib
	cp ./libft/inc/libft.h ./inc

$(MLX): ./mlx
	@(cd ./mlx && $(MAKE))
	cp ./mlx/libmlx.a ./lib
	cp ./mlx/mlx.h ./inc

obj/%.o: src/%.c
	gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	@(cd ./libft && $(MAKE) clean)
	@(cd ./mlx && $(MAKE) clean)

fclean: clean
	rm -rf $(NAME)
	rm -rf ./lib/libft.a
	rm -rf ./lib/libmlx.a
	rm -rf ./inc/libft.h
	rm -rf ./inc/mlx.h

re: fclean all

.PHONY: all clean fclean re
