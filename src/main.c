/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/22 13:25:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fdf.h"
#include "dev.h"
#include "libft/ft_printf.h"


void	img_pix_put(int x, int y)
{
	char	*pixel;
	
	pixel = data(GET)->img.addr + (y * data(GET)->img.line_len + x * (data(GET)->img.bpp / 8));
	*(int *)pixel = 0xFFFFFF;
}


int	absolute_int(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 0)
		panic(1);
	return (nbr);
}

void	steep_slope(int	dif_x, int dif_y, int x, int y)
{
	int	des;
	int	i;

	i = 0;
	des = 2 * absolute_int(dif_x) - absolute_int(dif_y);
	img_pix_put(x, y);
	while (i < absolute_int(dif_y))
	{
		if (dif_y > 0)
			y++;
		else
			y--;
		if (des < 0)
			des = des + 2 * absolute_int(dif_x);
		else
		{
			if (dif_x > 0)
				x++;
			else
				x--;
			des = des + 2 * absolute_int(dif_x) - 2 * absolute_int(dif_y);
		}
		img_pix_put(x, y);
		i++;
	}
}

void	gentle_slope(int dif_x, int dif_y, int x, int y)
{
	int	des;
	int	i;

	i = 0;
	des = 2 * absolute_int(dif_y) - absolute_int(dif_x);
	img_pix_put(x, y);
	while (i < absolute_int(dif_x))
	{
		if (dif_x > 0)
			x++;
		else
			x--;
		if (des < 0)
			des = des + 2 * absolute_int(dif_y);
		else
		{
			if (dif_y > 0)
				y++;
			else
				y--;
			des = des + 2 * absolute_int(dif_y) - 2 * absolute_int(dif_x);
		}
		img_pix_put(x, y);
		i++;
	}
}

void	draw_line(int x1, int y1, int x2, int y2)
{
	int	dif_x;
	int dif_y;

	dif_x = x2 - x1;
	dif_y = y2 - y1;
	if (absolute_int(dif_x) < absolute_int(dif_y))
		steep_slope(dif_x, dif_y, x1, y1);
	else
		gentle_slope(dif_x, dif_y, x1, y1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !init_check_file_extension(argv[1]))
		return (1);
	data(GET);
	p_data(GET)->argv = argv;
	matrix_process();
	fdf_mlx_init();
	img_init();


	draw_line(100, 100, 100, 200);
	mlx_put_image_to_window(data(GET)->mlx, data(GET)->mlx_win, data(GET)->img.img, 0, 0);

	mlx_loop_hook(data(GET)->mlx, &hook_idle, NULL);
	mlx_key_hook(data(GET)->mlx_win, &hook_key, NULL);
	mlx_hook(data(GET)->mlx_win, 17, 0, hook_close, NULL);
	mlx_loop(data(GET)->mlx);

	mlx_destroy_display(data(GET)->mlx);

	p_data(FREE);
	data(EXIT);
}
