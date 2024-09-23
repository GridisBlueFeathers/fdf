/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:03:43 by svereten          #+#    #+#             */
/*   Updated: 2024/09/23 15:16:18 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	absolute_int(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	if (nbr < 0)
		panic_msg(1, "fdf: value overflew during absolute conversion\n");
	return (nbr);
}

void	closer(int fd)
{
	if (fd >= 0 && close(fd) == -1)
		panic(1);
}
