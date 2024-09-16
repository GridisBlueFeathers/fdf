/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:55:51 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 10:05:56 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "libft/get_next_line.h"

typedef	enum	e_option
{
	GET,
	FREE,
	EXIT,
}	t_option;

typedef struct	s_point
{
	struct s_point	*next;
	int				x;
	int				y;
	int				z;
	int				color;

}	t_point;

typedef struct	s_line
{
	struct s_line	*next;
	t_point			*head;
	t_point			*tail;
}	t_line;

typedef struct	s_data
{
	size_t	width;
	size_t	height;
	t_line	*head;
}	t_data;

t_data	*data(t_option op);

void	panic(int status);

#endif
