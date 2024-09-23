/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:01:58 by svereten          #+#    #+#             */
/*   Updated: 2024/09/23 15:14:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	panic_msg(int status, char *msg)
{
	if (msg)
		ft_dprintf(STDERR_FILENO, msg);
	else if (errno)
		perror("fdf");
	if (data(GET)->mlx_win)
	{
		mlx_destroy_window(data(GET)->mlx, data(GET)->mlx_win);
		data(GET)->mlx_win = NULL;
	}
	if (data(GET)->img->img)
		mlx_destroy_image(data(GET)->mlx, data(GET)->img->img);
	if (data(GET)->mlx)
		mlx_destroy_display(data(GET)->mlx);
	data(FREE);
	p_data(FREE);
	exit(status);
}

void	panic(int status)
{
	if (errno)
		perror("fdf");
	if (data(GET)->mlx_win)
		mlx_destroy_window(data(GET)->mlx, data(GET)->mlx_win);
	if (data(GET)->img->img)
		mlx_destroy_image(data(GET)->mlx, data(GET)->img->img);
	if (data(GET)->mlx)
		mlx_destroy_display(data(GET)->mlx);
	data(FREE);
	p_data(FREE);
	exit(status);
}
