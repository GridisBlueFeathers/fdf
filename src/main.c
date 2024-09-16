/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 10:14:58 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "fdf.h"

int	check_file_extension(char *filename)
{
	size_t	filename_len;

	filename_len = ft_strlen(filename);
	if (filename_len < 5)
		return (0);
	if (ft_strcmp(".fdf", &filename[ft_strlen(filename) - 4]))
		return (0);
	return (1);
}

t_data	*data_init(void)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(1);
	return (data);
}

void	line_free(t_line *line)
{
	t_point	*cur;
	t_point	*tmp;

	cur = line->head;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(line);
}


void	data_free(void)
{
	t_data	*data_var;
	t_line	*line_cur;
	t_line	*line_tmp;

	data_var = data(GET);
	line_cur = data(GET)->head;
	while (line_cur)
	{
		line_tmp = line_cur->next;
		line_free(line_cur);
		line_cur = line_tmp;
	}
	free(data_var);
}

t_data	*data(t_option op)
{
	static t_data	*data;
	if (op == GET)
	{
		if (!data)
			data = data_init();
		return (data);
	}
	if (op == FREE)
	{
		if (!data)
			return (NULL);
		data_free();
		data = NULL;
	}
	return (data);
}

int	main(int argc, char **argv)
{
	void *mlx;
	(void)argv;
	if (argc != 2 || !check_file_extension(argv[1]))
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	char *line = get_next_line(fd);
	if (!line)
		panic(1);
	char **line_split = ft_split(line, ' ');
	if (!line_split)
		panic(1);
	if (!data(GET)->width)
		data(GET)->width = ft_strarrlen(line_split);



	/*mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);*/
	printf("hello\n");
}
