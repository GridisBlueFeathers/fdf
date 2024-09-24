/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/24 11:36:53 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

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
	fdf_mlx_run();
	p_data(FREE);
	data(EXIT);
}
