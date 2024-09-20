/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:36:30 by svereten          #+#    #+#             */
/*   Updated: 2024/09/20 14:27:24 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

/*void	point_append(void)
{
	t_line	*line;

	line = data(GET)->tail_l;
	line->width++;
	if (!line->tail_p)
	{
		line->tail_p = (t_point *)ft_calloc(1, sizeof(t_point));
		if (!line->tail_p)
			panic(1);
		line->tail_p->y = line->width - 1;
		line->tail_p->color = 16777215;
		line->head_p = line->tail_p;
		return ;
	}
	line->tail_p->next_p = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!line->tail_p->next_p)
		panic(1);
	line->tail_p->next_p->y = line->width - 1;
	line->tail_p->next_p->x = line->tail_p->x + 1;
	line->tail_p->next_p->color = 16777215;
	line->tail_p = line->tail_p->next_p;
}*/
