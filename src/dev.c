/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:10:00 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 16:42:11 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "dev.h"

void	dev_put_lines(t_dev_op op)
{
	t_line	*cur_l = data(GET)->head_l;
	t_point	*cur_p;

	while (cur_l)
	{
		cur_p = cur_l->head_p;
		while (cur_p)
		{
			switch (op) {
				case (X):
					ft_printf("%d ", cur_p->x);
					break ;
				case (Y):
					ft_printf("%d ", cur_p->y);
					break ;
				case (Z):
					ft_printf("%d ", cur_p->z);
					break ;
				case (COLOR):
					printf("%x ", cur_p->color);
					break ;
			}
			cur_p = cur_p->next_p;
		}
		printf("\n");
		cur_l = cur_l->next_l;
	}
}
