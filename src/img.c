/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:17:26 by svereten          #+#    #+#             */
/*   Updated: 2024/09/23 15:39:59 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	img_init(void)
{
	void	*mlx;
	t_img	*img;

	mlx = data(GET)->mlx;
	img = data(GET)->img;
	img->img = mlx_new_image(mlx, WIN_W, WIN_H);
	if (!img->img)
		panic(1);
	img->addr = mlx_get_data_addr(img->img,
			&img->bpp, &img->line_len, &img->endian);
}

void	img_pix_put(int x, int y)
{
	char	*pixel;
	t_img	*img;

	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
	img = data(GET)->img;
	pixel = img->addr + (y * img->line_len + x * 4);
	*(int *)pixel = 0xFFFFFF;
}
