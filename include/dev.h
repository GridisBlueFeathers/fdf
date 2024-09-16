/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:16:24 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 16:30:37 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEV_H
# define DEV_H

#include "fdf.h"

typedef enum e_dev_op {
	X,
	Y,
	Z,
	COLOR,
}	t_dev_op;

void	dev_put_lines(t_dev_op op);
#endif
