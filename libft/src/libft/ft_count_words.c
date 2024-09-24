/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:44:08 by svereten          #+#    #+#             */
/*   Updated: 2024/09/19 10:46:22 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	if (s[0] && s[0] != c)
		res++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			res++;
		i++;
	}
	return (res);
}
