/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/20 15:08:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fdf.h"
#include "dev.h"
#include "libft/ft_printf.h"


int	main(int argc, char **argv)
{
	void	*mlx;

	(void)mlx;
	(void)argv;
	if (argc != 2 || !init_check_file_extension(argv[1]))
		return (1);
	data(GET);
	p_data(GET)->argv = argv;
	matrix_process();
	dev_matrix_print();
	/*mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);
	while (1)
	{

	}*/
	p_data(FREE);
	data(EXIT);
}
