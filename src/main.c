/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/23 01:02:09 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "dev.h"
#include "libft/ft_printf.h"


void	img_pix_put(int x, int y)
{
	char	*pixel;
	
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
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

void	isometric(float *x, float *y, int z)
{
	int	x_cpy;
	int	y_cpy;

	x_cpy = *x;
	y_cpy = *y;
	*x = (x_cpy - y_cpy) * cos(0.523599);
	*y = (x_cpy + y_cpy) * sin(0.523599) - z;
	//*x = (x_cpy - y_cpy) * cos(0.8);
	//*y = (x_cpy + y_cpy) * sin(0.8) - z;
}

void	line_init(float *x1, float *y1, float *x2, float *y2)
{
	isometric(x1, y1, data(GET)->matrix[(int)*y1][(int)*x1]);
	isometric(x2, y2, data(GET)->matrix[(int)*y2][(int)*x2]);
	*x1 *= ZOOM;
	*y1 *= ZOOM;
	*x2 *= ZOOM;
	*y2 *= ZOOM;
	*x1 += WIN_W / 2;
	*x2 += WIN_W / 2;
}

void	draw_line(float x1, float y1, float x2, float y2)
{
	int	dif_x;
	int dif_y;

	line_init(&x1, &y1, &x2, &y2);
	dif_x = x2 - x1;
	dif_y = y2 - y1;
	if (absolute_int(dif_x) < absolute_int(dif_y))
		steep_slope(dif_x, dif_y, x1, y1);
	else
		gentle_slope(dif_x, dif_y, x1, y1);
}

void	matrix_draw(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < data(GET)->height)
	{
		x = 0;
		while (x < data(GET)->width)
		{
			if (x < data(GET)->width - 1)
				draw_line(x, y, x + 1, y);
			if (y < data(GET)->height - 1)
				draw_line(x, y, x, y + 1);
			x++;
		}
		y++;
	}
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


	matrix_draw();
	mlx_put_image_to_window(data(GET)->mlx, data(GET)->mlx_win, data(GET)->img.img, 0, 0);

	mlx_loop_hook(data(GET)->mlx, &hook_idle, NULL);
	mlx_key_hook(data(GET)->mlx_win, &hook_key, NULL);
	mlx_hook(data(GET)->mlx_win, 17, 0, hook_close, NULL);
	mlx_loop(data(GET)->mlx);

	mlx_destroy_image(data(GET)->mlx, data(GET)->img.img);
	mlx_destroy_display(data(GET)->mlx);

	p_data(FREE);
	data(EXIT);
}
