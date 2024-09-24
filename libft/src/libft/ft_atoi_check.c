/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:51:03 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 13:53:07 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

int	ft_atoi_check(char *str, int *res)
{
	char	*itoa_res;

	*res = ft_atoi(str);
	itoa_res = ft_itoa(*res);
	if (!itoa_res || ft_strcmp(str, itoa_res))
		return (free(itoa_res), 0);
	return (free(itoa_res), 1);
}
