/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:55:51 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 16:43:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"

typedef	enum	e_option
{
	GET,
	FREE,
	EXIT,
}	t_option;

typedef struct	s_point
{
	struct s_point	*next_p;
	int				x;
	int				y;
	int				z;
	int				color;

}	t_point;

void	point_append(void);

typedef struct	s_line
{
	int				y;
	struct s_line	*next_l;
	t_point			*head_p;
	t_point			*tail_p;
}	t_line;

void	line_free(t_line *line);
void	line_append(void);

typedef struct	s_data
{
	size_t	width;
	size_t	height;
	t_line	*head_l;
	t_line	*tail_l;
}	t_data;

int	init_check_file_extension(char *filename);

t_data	*data(t_option op);


void	panic(int status);
void	panic_silent(int status);

#endif
