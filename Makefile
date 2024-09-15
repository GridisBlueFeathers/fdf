# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 14:15:06 by svereten          #+#    #+#              #
#    Updated: 2024/09/15 16:07:15 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf

CC = cc

MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Wextra 

INCLUDE = -I./include -I./libft/include

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
SRC_DIR = src
OBJ_DIR = obj

FILES = main

SRCS = ${FILES:%=${SRC_DIR}/%.c}
OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	${CC} ${CFLAGS} ${MLXFLAGS} ${MATHFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${MLX}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@

clean: 
	rm -rf obj
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

norm:
	norminette ${SRCS}
