# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/02/15 15:27:07 by agiordan     #+#   ##    ##    #+#        #
#    Updated: 2019/02/28 00:55:54 by gal         ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = Wolf3D

SRCS_PATH =		src
SRCS_PATH_1 =	parsing
SRCS_PATH_2 =	physics
SRCS_PATH_3 =	window
SRCS_PATH_4 =	map_editor
SRCS_FILES =	main.c \
				error.c \
				$(SRCS_PATH_1)/parser.c \
				$(SRCS_PATH_2)/collision.c \
				$(SRCS_PATH_2)/raycasting.c \
				$(SRCS_PATH_2)/sum_x.c \
				$(SRCS_PATH_3)/open_window.c \
				$(SRCS_PATH_3)/window_loop.c \
				$(SRCS_PATH_3)/draw.c \
				$(SRCS_PATH_3)/draw_rect.c \
				$(SRCS_PATH_3)/line_put.c \
				$(SRCS_PATH_3)/quit.c \
				$(SRCS_PATH_4)/map_editor.c \
				$(SRCS_PATH_4)/ed_export.c \
				$(SRCS_PATH_4)/ed_put_grid.c \
				$(SRCS_PATH_4)/ed_window_loop.c \
				$(SRCS_PATH_4)/ed_put_map.c \
				$(SRCS_PATH_4)/ed_is_in_map.c \
				$(SRCS_PATH_4)/ed_add_tile.c

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJ = $(SRCS:%.c=%.o)

INCLUDE_PATH = include
CC = gcc
CFLAGS += -Wall -Wextra -Werror -I./$(INCLUDE_PATH)

LIBFT = libft
LIBMATH = libmath
LIBSDL2 = `sdl2-config --cflags --libs`
LIBCMATH = -lm

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBCMATH) $(LIBFT)/$(LIBFT).a $(LIBMATH)/$(LIBMATH).a -o $(NAME) $(LIBSDL2)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)
	make clean -C $(LIBMATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(LIBMATH)

re: fclean all

norme:
		@norminette $(LIBFT)
		@norminette $(LIBMATH)
		@norminette $(SRC_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, fclean, re
