# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 14:15:06 by svereten          #+#    #+#              #
#    Updated: 2024/09/24 14:16:05 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fdf

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I./include -I./libft/include
LDLIBS = -lmlx -lXext -lX11 -lm -lft 
LDFLAGS = -L./libft/

LIBFT = ./libft/libft.a

LIBFT_DIR = libft
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

OBJS = ${FILES:%=${OBJ_DIR}/%.o}

OBJ_DIRS = ${sort ${dir ${OBJS}}}

all: ${NAME}

${NAME}: ${OBJS} | ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o $@ ${LDLIBS} ${LDFLAGS}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR} GNL_SIZE="-D BUFFER_SIZE=4095"

${OBJ_DIRS}:
	mkdir -p $@

clean: 
	rm -rf obj
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}
	
re: fclean all

.PHONY: all clean fclean re
