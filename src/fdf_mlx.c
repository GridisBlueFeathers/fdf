/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:30:46 by svereten          #+#    #+#             */
/*   Updated: 2024/09/23 15:47:46 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	fdf_mlx_init(void)
{
	data(GET)->mlx = mlx_init();
	if (!data(GET)->mlx)
		panic(1);
	data(GET)->mlx_win = mlx_new_window(data(GET)->mlx, WIN_W, WIN_H, "fdf");
	if (!data(GET)->mlx_win)
		panic(1);
}

void	fdf_mlx_run(void)
{
	mlx_put_image_to_window(data(GET)->mlx,
		data(GET)->mlx_win, data(GET)->img->img, 0, 0);
	mlx_loop_hook(data(GET)->mlx, &hook_idle, NULL);
	mlx_key_hook(data(GET)->mlx_win, &hook_key, NULL);
	mlx_hook(data(GET)->mlx_win, 17, 0, &hook_close, NULL);
	mlx_loop(data(GET)->mlx);
	mlx_destroy_image(data(GET)->mlx, data(GET)->img->img);
	mlx_destroy_display(data(GET)->mlx);
}
