/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/17 00:41:01 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "dev.h"
#include "libft/ft_printf.h"

void	point_process(char *line)
{
	int	i;
	int	commas;
	int	comma_loc;
	int	z_coord;
	char *itoa_res;

	i = 0;
	commas = 0;
	while (line[i] && line[i] != ' ')
	{
		if (line[i] == ',')
		{
			commas++;
			comma_loc = i;
		}
		if (line[i] == '\n')
			break ;
		i++;
	}
	if (!commas)
	{
		z_coord = ft_atoi(line);
		itoa_res = ft_itoa(z_coord);
		if (!itoa_res || ft_strncmp(itoa_res, line, i))
		{
			ft_dprintf(2, "z coordinate overflew\n");
			panic(1);
		}
		point_append();
		data(GET)->tail_l->tail_p->z = z_coord;
	}
	if (commas == 1)
	{
		z_coord = ft_atoi(line);
		itoa_res = ft_itoa(z_coord);
		if (!itoa_res || ft_strncmp(itoa_res, line, comma_loc))
		{
			ft_dprintf(2, "z coordinate overflew\n");
			panic(1);
		}
		point_append();
		data(GET)->tail_l->tail_p->z = z_coord;
	}
	if (commas >= 2)
		panic(1);
}

int	main(int argc, char **argv)
{
	void *mlx;
	(void)mlx;
	(void)argv;
	if (argc != 2 || !init_check_file_extension(argv[1]))
		return (1);
	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		panic(1);
	char *line;
	int	check;
	int	i;

	check = 1;
	line = "";
	while (check)
	{
		ft_printf("start\n");
		check = get_next_line(fd, &line, 0);
		if (!check)
		{
			get_next_line(fd, NULL, 1);
			panic(1);
		}
		if (!line)
			break ;
		line_append();
		i = 0;
		while(line[i])
		{
			while(line[i] && line[i] == ' ')
				i++;
			point_process(&line[i]);
			while(line[i] && line[i] != ' ')
				i++;
		}

		/*char **line_split = ft_split(line, ' ');
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
		while (line_split[i])
		{
			if (line_split[i] && !line_split[i + 1])
				line_split[i] = ft_substr(line_split[i], 0, ft_strlen(line_split[i]) - 1);
			if (!line_split[i])
				panic(1);
			point_append();
			point = data(GET)->tail_l->tail_p;
			point_split = ft_split(line_split[i], ',');
			if (!ft_strarrlen(point_split) || ft_strarrlen(point_split) > 2)
				panic(1);
			if (!ft_atoi_check(point_split[0], &point->z))
				panic(1);
			i++;
		}*/


		free(line);
		//ft_free(STR_ARR, &line_split);
		printf("finish\n");
	}
	dev_put_lines(Z);
	/*mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);*/
	printf("hello\n");
	data(EXIT);
}
