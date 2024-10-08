/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:03:52 by svereten          #+#    #+#             */
/*   Updated: 2024/09/23 15:33:39 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		panic(1);
	data->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!data->img)
	{
		ft_free(STRUCT, &data);
		panic(1);
	}
	return (data);
}

static void	data_free(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (data->matrix && i < data->actual_height)
	{
		if (data->matrix)
			free(data->matrix[i]);
		i++;
	}
	free(data->matrix);
	if (data->mlx)
		free(data->mlx);
	if (data->img)
		free(data->img);
	free(data);
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
		data_free(data);
		data = NULL;
	}
	if (op == EXIT)
	{
		data_free(data);
		data = NULL;
		exit(0);
	}
	return (data);
}
