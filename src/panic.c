/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:01:58 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 11:49:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	panic(int status)
{
	perror("fdf");
	data(FREE);
	exit(status);
}

void	panic_silent(int status)
{
	data(FREE);
	exit(status);
}
