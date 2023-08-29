# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 17:58:21 by aachhoub          #+#    #+#              #
#    Updated: 2023/08/26 18:37:33 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_SRC= ${addprefix src/, actions_move.c handle_keys.c\
			main.c textures.c tools.c actions_rotate.c}

PARSING_SRC = ${addprefix src/parsing/, list_utils.c parser_utils.c parser.c parse_attrs1.c\
			parse_attrs2.c parse_attrs3.c parse_map1.c parse_scene.c}

MATH_SRC = ${addprefix src/math_utils/, angles.c step_table.c trig_funcs.c vectors.c}

MLX_SRC = ${addprefix src/mlx_utils/, colors.c file_utils.c window_and_image.c}

RAYCASTING_SRC = ${addprefix src/raycasting/, collisions.c minimap_raycasting.c raycasting_distance.c raycasting.c}

SRCS = ${MAIN_SRC} ${MATH_SRC} ${MLX_SRC} ${RAYCASTING_SRC} ${PARSING_SRC}

LIBFT = lib/libft/libft.a

LIBMLX = minilibx/libmlx.a -lXext -lX11 -lm -lbsd

GNL = ${addprefix lib/get_next_line/, get_next_line.c get_next_line_utils.c}

LIBS = ${LIBFT} ${GNL}

MSG = "\
██████████████████████████████████████████\n\
█─▄▄▄─█▄─██─▄█▄─▄─▀█▄─▄─▀█▄─▄█▄─▄▄─█─▄▄▄▄█\n\
█─███▀██─██─███─▄─▀██─▄─▀██─███─▄█▀█▄▄▄▄─█\n\
▀▄▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▀▄▄▄▄▄▀▄▄▄▄▄▀\n\
\n\
Usage: ./cub3D <map.cub>\n\
"

INCS = ${addprefix includes/, cub3d.h cub.h game.h cub_math.h}

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

NAME = cub3D

all: ${NAME}

${NAME}: ${LIBS} ${LIBMLX} ${SRCS} ${INCS}
	@${CC} ${CFLAGS} ${SRCS} ${LIBS} ${LIBMLX} -o ${NAME}
	@clear
	@echo ${MSG}

${LIBFT}:
	@make -C lib/libft

${LIBMLX}:
	@make -C minilibx

clean:
	@make clean -C lib/libft
	@make clean -C minilibx

fclean: clean
	@make fclean -C lib/libft
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
