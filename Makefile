# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 14:15:06 by svereten          #+#    #+#              #
#    Updated: 2024/09/24 11:21:34 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include -I./libft/include
LDLIBS = -lmlx -lXext -lX11 -lm -lft 
LDFLAGS = -L./libft/

LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a

LIBFT_DIR = libft
MLX_DIR = minilibx-linux
SRC_DIR = src
OBJ_DIR = obj

FILES = main \
		panic \
		data \
		p_data \
		init \
		matrix \
		fdf_mlx \
		hooks \
		img \
		line \
		utils \

SRCS = ${FILES:%=${SRC_DIR}/%.c}
OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

DEV_NAME = fdf_dev
CFLAGS += -g
DEV_FILES = dev
DEV_OBJS = ${OBJS} ${DEV_FILES:%=${OBJ_DIR}/%.o}

MAP ?= test_maps/42.fdf

all: ${NAME}

${NAME}: ${OBJS} | ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o $@ ${LDLIBS} ${LDFLAGS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR} GNL_SIZE="-D BUFFER_SIZE=4096"

${OBJ_DIRS}:
	mkdir -p $@

${DEV_NAME}: ${DEV_OBJS} ${LIBFT} ${MLX}
	${CC} ${CFLAGS} ${DEV_FLAGS} ${LIBFT} ${MLXFLAGS} ${INCLUDE} $^ -o $@

run: re
	./${NAME} ${MAP}

valgrind: re
	$@ --show-leak-kinds=all --leak-check=full ./fdf ${MAP}

funcheck: re
	$@ -a ./fdf ${MAP}

print:
	echo ${DEV_OBJS}

dev: ${DEV_NAME}

fdev: fclean ${DEV_NAME}

clean: 
	rm -rf obj
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}
	
re: fclean all

norm:
	norminette ${SRCS} ./include/fdf.h

.PHONY: all clean fclean re norm
