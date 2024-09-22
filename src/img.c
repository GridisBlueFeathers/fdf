/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:36:22 by svereten          #+#    #+#             */
/*   Updated: 2024/09/22 13:43:51 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	img_init(void)
{
	data(GET)->img.img = mlx_new_image(data(GET)->mlx, WIN_W, WIN_H);
	if (!data(GET)->img.img)
		panic(1);
	data(GET)->img.addr = mlx_get_data_addr(
		data(GET)->img.img, 
		&data(GET)->img.bpp, 
		&data(GET)->img.line_len, 
		&data(GET)->img.endian);
}
