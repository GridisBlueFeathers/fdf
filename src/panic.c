/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:01:58 by svereten          #+#    #+#             */
/*   Updated: 2024/09/18 14:52:10 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "libft/ft_printf.h"
#include <errno.h>

void	panic_msg(int status, char *msg)
{
	if (errno)
		perror("fdf");
	ft_dprintf(STDERR_FILENO, msg);
	data(FREE);
	p_data(FREE);
	exit(status);
}

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
