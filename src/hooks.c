/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:28:40 by svereten          #+#    #+#             */
/*   Updated: 2024/09/20 18:29:00 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	hook_key(int key, void	*ptr)
{
	(void)ptr;
	if (key == 65307)
		mlx_destroy_window(data(GET)->mlx, data(GET)->mlx_win);
	return (0);
}

int	hook_close(void	*ptr)
{
	(void)ptr;
	mlx_destroy_window(data(GET)->mlx, data(GET)->mlx_win);
	return (0);
}

int	hook_idle(void	*ptr)
{
	(void)ptr;
	return (0);
}
