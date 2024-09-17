/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:01:58 by svereten          #+#    #+#             */
/*   Updated: 2024/09/18 00:37:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <errno.h>

void	panic(int status)
{
	if (errno)
		perror("fdf");
	data(FREE);
	p_data(FREE);
	exit(status);
}

void	panic_silent(int status)
{
	data(FREE);
	exit(status);
}
