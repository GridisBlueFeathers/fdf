/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:30:46 by svereten          #+#    #+#             */
/*   Updated: 2024/09/20 18:31:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_mlx_init()
{
	data(GET)->mlx = mlx_init();
	if (!data(GET)->mlx)
		panic(1);
	data(GET)->mlx_win = mlx_new_window(data(GET)->mlx, 800, 500, "yo wtf");
	if (!data(GET)->mlx_win)
		panic(1);
}

