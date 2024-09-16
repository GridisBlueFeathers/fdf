/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:32:46 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 16:35:54 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	line_free(t_line *line)
{
	t_point	*cur;
	t_point	*tmp;

	cur = line->head_p;
	while (cur)
	{
		tmp = cur->next_p;
		free(cur);
		cur = tmp;
	}
	free(line);
}

void	line_append(void)
{
	if (!data(GET)->tail_l)
	{
		data(GET)->tail_l = (t_line *)ft_calloc(1, sizeof(t_line));
		if (!data(GET)->tail_l)
			panic(1);
		data(GET)->head_l = data(GET)->tail_l;
		data(GET)->height++;
		return ;
	}
	data(GET)->tail_l->next_l = (t_line *)ft_calloc(1, sizeof(t_line));
	if (!data(GET)->tail_l->next_l)
		panic(1);
	data(GET)->tail_l->next_l->y = data(GET)->tail_l->y;
	data(GET)->tail_l = data(GET)->tail_l->next_l;
}
