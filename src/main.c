/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/16 12:16:22 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	data->width = 0;
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
	if (op == EXIT)
	{
		data_free();
		data = NULL;
		exit (0);
	}
	return (data);
}

void	line_append(void)
{
	if (!data(GET)->tail)
	{
		data(GET)->tail = (t_line *)ft_calloc(1, sizeof(t_line));
		if (!data(GET)->tail)
			panic(1);
		data(GET)->head = data(GET)->tail;
		return ;
	}
	data(GET)->tail->next = (t_line *)ft_calloc(1, sizeof(t_line));
	if (!data(GET)->tail->next)
		panic(1);
	data(GET)->tail = data(GET)->tail->next;
}

void	point_append(void)
{
	if (!data(GET)->tail->tail)
	{
		data(GET)->tail->tail = (t_point *)ft_calloc(1, sizeof(t_point));
		if (!data(GET)->tail->tail)
			panic(1);
		data(GET)->tail->head = data(GET)->tail->tail;
		return ;
	}
	data(GET)->tail->tail->next = (t_point *)ft_calloc(1, sizeof(t_point));
	if (!data(GET)->tail->tail->next)
		panic(1);
	data(GET)->tail->tail = data(GET)->tail->tail->next;
}

int	main(int argc, char **argv)
{
	void *mlx;
	(void)mlx;
	(void)argv;
	if (argc != 2 || !check_file_extension(argv[1]))
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	char *line;
	char *subline;
	char **point_split;
	int	check;
	int	i;

	check = 1;
	line = "";
	while (check && line)
	{
		check = get_next_line(fd, &line, 0);
		if (!check)
		{
			get_next_line(fd, NULL, 1);
			panic(1);
		}
		if (!line)
			break ;
		subline = ft_substr(line, 0, ft_strlen(line) - 1);
		if (!subline)
		{
			free(line);
			get_next_line(fd, NULL, 1);
			panic(1);
		}
		char **line_split = ft_split(subline, ' ');
		if (!line_split)
			panic(1);
		if (!data(GET)->width)
			data(GET)->width = ft_strarrlen(line_split);
		if (data(GET)->width && data(GET)->width != ft_strarrlen(line_split))
		{
			ft_dprintf(STDERR_FILENO, "Line width is not the same accross the file\n");
			panic_silent(1);
		}
		i = 0;
		line_append();
		while (line_split[i])
		{
			point_append();
			point_split = ft_split(line_split[i], ',');
			if (ft_strarrlen(point_split) > 2)
				panic(1);
			
			
		}


		free(line);
		ft_free(STR_ARR, &line_split);
	}
	/*mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);*/
	printf("hello\n");
	data(EXIT);
}
