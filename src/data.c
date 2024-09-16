/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:03:52 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 16:38:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(1);
	return (data);
}

static void	data_free(void)
{
	t_data	*data_var;
	t_line	*line_cur;
	t_line	*line_tmp;

	data_var = data(GET);
	line_cur = data(GET)->head_l;
	while (line_cur)
	{
		line_tmp = line_cur->next_l;
		line_free(line_cur);
		line_cur = line_tmp;
	}
	free(data_var);
}

t_data	*data(t_option op)
{
	static t_data	*data;
	if (op == GET)
	{
		if (!data)
			data = data_init();
		return (data);
	}
	if (op == FREE)
	{
		if (!data)
			return (NULL);
		data_free();
		data = NULL;
	}
	if (op == EXIT)
	{
		data_free();
		data = NULL;
		exit(0);
	}
	return (data);
}
