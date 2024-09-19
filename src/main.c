/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/19 15:42:47 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
#include "fdf.h"
#include "dev.h"
#include "libft/ft_printf.h"

/*void	point_process_no_comma(char *line, int len)
{
	int		z;
	char	num[12];

	if (len > 11 || (len > 10 && line[0] != '-'))
		panic(1);
	ft_strlcpy(num, line, len + 1);
	if (!ft_isnumber(num))
		panic(1);
	if ((len == 11 && ft_strcmp("-2147483648", num) < 0)
		|| (len == 10 && ft_strcmp("2147483647", num) < 0))
		panic_msg(1, "fdf: one of the numbers will over/underflow\n");
	z = ft_atoi(line);
	point_append();
	data(GET)->tail_l->tail_p->z = z;
}

void	point_process(char *line)
{
	int	line_len;
	int	commas;
	int	comma_loc;

	line_len = 0;
	commas = 0;
	while (line[line_len] && line[line_len] != ' ')
	{
		if (line[line_len] == ',')
		{
			commas++;
			comma_loc = line_len;
		}
		if (line[line_len] == '\n')
			break ;
		line_len++;
	}
	if (!commas)
		point_process_no_comma(line, line_len);
	if (commas == 1)
	{
		point_process_no_comma(line, comma_loc);
	}
	if (commas >= 2)
		panic(1);
}

void	map_open(void)
{
	p_data(GET)->fd = open(p_data(GET)->argv[1], O_RDONLY);
	if (p_data(GET)->fd == -1)
		panic(1);
}

void	map_parse(void)
{
	int	check;
	int	i;

	check = 1;
	while (check)
	{
		check = get_next_line(p_data(GET)->fd, &p_data(GET)->gnl_line, 0);
		if (!check)
			panic(1);
		if (!p_data(GET)->gnl_line)
			break ;
		line_append();
		i = 0;
		while (p_data(GET)->gnl_line[i])
		{
			while (p_data(GET)->gnl_line[i] && p_data(GET)->gnl_line[i] == ' ')
				i++;
			point_process(&p_data(GET)->gnl_line[i]);
			while (p_data(GET)->gnl_line[i] && p_data(GET)->gnl_line[i] != ' ')
				i++;
		}
		ft_free(STR, &p_data(GET)->gnl_line);
	}
}

void	map_process(void)
{
	map_open();
	map_parse();
}*/

void	get_height(void)
{
	int		fd;
	char	*line;

	fd = open(data(GET)->argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	line = "";
	while (line)
	{
		if (!get_next_line(fd, &line))
		{
			get_next_line(fd, NULL);
			panic(1);
		}
		if (line)
			data(GET)->height++;
		free(line);
	}
	close(fd);
}

void	get_width(void)
{
	int		fd;
	char	*line;

	fd = open(data(GET)->argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	if (!get_next_line(fd, &line))
		panic(1);
	data(GET)->width = ft_count_words(line, ' ');
	get_next_line(fd, NULL);
	free(line);
	close(fd);
}

void	matrix_feed(void)
{
	size_t	i;
	int		fd;
	char	*line;

	(void)line;
	fd = open(data(GET)->argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	i = 0;
	while (i < data(GET)->height)
	{

	}
}

int	main(int argc, char **argv)
{
	void	*mlx;

	(void)mlx;
	(void)argv;
	if (argc != 2 || !init_check_file_extension(argv[1]))
		return (1);
	/*data(GET)->argv = argv;
	get_height();
	data(GET)->matrix = (int **)ft_calloc(data(GET)->height, sizeof(int *));
	if (!data(GET)->matrix)
		panic(1);
	get_width();*/
	mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);
	while (1)
	{

	}
	data(EXIT);
}
