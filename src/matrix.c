/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:05:26 by svereten          #+#    #+#             */
/*   Updated: 2024/09/24 13:46:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	matrix_get_height(void)
{
	int		fd;
	int		check;
	char	*line;

	fd = open(p_data(GET)->argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	line = NULL;
	check = 1;
	while (check)
	{
		if (!get_next_line(fd, &line))
		{
			get_next_line(fd, NULL);
			panic(1);
		}
		if (line)
			data(GET)->height++;
		else
			check = 0;
		free(line);
	}
	closer(fd);
}

static void	matrix_feed_line(char *line, int i)
{
	int		j;
	t_data	*m_data;

	m_data = data(GET);
	p_data(GET)->split_line = ft_split(line, ' ');
	if (!p_data(GET)->split_line)
		panic(1);
	m_data->matrix[i] = (int *)ft_calloc(m_data->width, sizeof(int));
	if (!data(GET)->matrix[i])
		panic(1);
	data(GET)->actual_height++;
	j = 0;
	while (p_data(GET)->split_line[j])
	{
		if (j < data(GET)->width)
			data(GET)->matrix[i][j] = ft_atoi(p_data(GET)->split_line[j]);
		j++;
	}
	if (j != data(GET)->width)
		panic_msg(1, INV_MAP);
	ft_free(STR_ARR, &p_data(GET)->split_line);
}

static void	matrix_feed(void)
{
	int	i;

	p_data(GET)->fd = open(p_data(GET)->argv[1], O_RDONLY);
	if (p_data(GET)->fd == -1)
		panic(1);
	i = 0;
	while (1)
	{
		if (!get_next_line(p_data(GET)->fd, &p_data(GET)->line))
		{
			get_next_line(p_data(GET)->fd, NULL);
			panic(1);
		}
		if (!p_data(GET)->line)
			break ;
		if (!data(GET)->width)
			data(GET)->width = ft_count_words(p_data(GET)->line, ' ');
		if ((int)ft_count_words(p_data(GET)->line, ' ') != data(GET)->width)
			panic_msg(1, "fdf: map is not rectangular\n");
		matrix_feed_line(p_data(GET)->line, i);
		ft_free(STR, &p_data(GET)->line);
		i++;
	}
	get_next_line(p_data(GET)->fd, NULL);
}

void	matrix_process(void)
{
	matrix_get_height();
	data(GET)->matrix = (int **)ft_calloc(data(GET)->height, sizeof(int *));
	if (!data(GET)->matrix)
		panic(1);
	matrix_feed();
	data(GET)->zoom = 15;
	if (data(GET)->height >= 150 || data(GET)->width >= 150)
		data(GET)->zoom = 2;
}

void	matrix_draw(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < data(GET)->height)
	{
		x = 0;
		while (x < data(GET)->width)
		{
			if (x < data(GET)->width - 1)
				line_draw(x, y, x + 1, y);
			if (y < data(GET)->height - 1)
				line_draw(x, y, x, y + 1);
			x++;
		}
		y++;
	}
}
