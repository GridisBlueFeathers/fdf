/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/15 16:11:37 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	void *mlx;
	(void)argv;
	if (argc != 2)
		return (1);
	mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);
	while (1)
	{
	}
	printf("hello\n");
}
