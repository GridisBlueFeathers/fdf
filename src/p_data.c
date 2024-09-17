/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:03:27 by svereten          #+#    #+#             */
/*   Updated: 2024/09/18 00:55:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_p_data	*p_data_init(void)
{
	t_p_data	*data;

	data = (t_p_data *)ft_calloc(1, sizeof(t_p_data));
	if (!data)
		panic(1);
	data->gnl_line = NULL;
	return (data);
}

static void	p_data_free(t_p_data *data)
{
	close(data->fd);
	get_next_line(data->fd, NULL, 1);
	free(data->gnl_line);
	free(data);
}

t_p_data	*p_data(t_option op)
{
	static t_p_data	*data;
	if (op == GET)
	{
		if (!data)
			data = p_data_init();
		return (data);
	}
	if (op == FREE)
	{
		if (!data)
			return (NULL);
		p_data_free(data);
		data = NULL;
	}
	return (NULL);
}
