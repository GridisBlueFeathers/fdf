/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:10:00 by svereten          #+#    #+#             */
/*   Updated: 2024/09/20 15:08:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "dev.h"

void	dev_matrix_print(void)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data(GET)->height)
	{
		j = 0;
		while (j < data(GET)->width)
		{
			printf("%3d ", data(GET)->matrix[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}
