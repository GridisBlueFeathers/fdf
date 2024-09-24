/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:04:47 by svereten          #+#    #+#             */
/*   Updated: 2024/09/24 09:58:24 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	line_draw_steep(int dif_x, int dif_y, int x, int y)
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

static void	line_draw_gentle(int dif_x, int dif_y, int x, int y)
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

static void	line_apply_iso(float *x, float *y, int z)
{
	int	x_cpy;
	int	y_cpy;

	x_cpy = *x;
	y_cpy = *y;
	*x = (x_cpy - y_cpy) * cos(0.9);
	*y = (x_cpy + y_cpy) * sin(0.9) - z;
}

static void	line_init(float *x1, float *y1, float *x2, float *y2)
{
	line_apply_iso(x1, y1, data(GET)->matrix[(int)*y1][(int)*x1]);
	line_apply_iso(x2, y2, data(GET)->matrix[(int)*y2][(int)*x2]);
	*x1 *= data(GET)->zoom;
	*y1 *= data(GET)->zoom;
	*x2 *= data(GET)->zoom;
	*y2 *= data(GET)->zoom;
	*x1 += WIN_W / 2;
	*x2 += WIN_W / 2;
	if (data(GET)->height < 25 || data(GET)->width < 25)
	{
		*y1 += WIN_H / 2;
		*y2 += WIN_H / 2;
	}
}

void	line_draw(float x1, float y1, float x2, float y2)
{
	int	dif_x;
	int	dif_y;

	line_init(&x1, &y1, &x2, &y2);
	dif_x = x2 - x1;
	dif_y = y2 - y1;
	if (absolute_int(dif_x) < absolute_int(dif_y))
		line_draw_steep(dif_x, dif_y, x1, y1);
	else
		line_draw_gentle(dif_x, dif_y, x1, y1);
}
