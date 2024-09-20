/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:33:46 by svereten          #+#    #+#             */
/*   Updated: 2024/09/19 17:23:31 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	init_check_file_extension(char *filename)
{
	size_t	filename_len;

	filename_len = ft_strlen(filename);
	if (filename_len < 5)
		panic_msg(1, INV_EXT);
	if (ft_strcmp(".fdf", &filename[ft_strlen(filename) - 4]))
		panic_msg(1, INV_EXT);
	return (1);
}
