/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:23:56 by svereten          #+#    #+#             */
/*   Updated: 2024/09/18 11:30:24 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "dev.h"
#include "libft/ft_printf.h"

void	point_process_no_comma(char *line, int len)
{
	int	z_coord;
	char	num[12];

	if (len > 11 || (len > 10 && line[0] != '-'))
		panic(1);
	ft_strlcpy(num, line, len + 1);
	if (!ft_isnumber(num))
		panic(1);
	if ((len == 11 && ft_strcmp("-2147483648", num) < 0)
		|| (len == 10 && ft_strcmp("2147483647", num) < 0))
		panic(1);
	z_coord = ft_atoi(line);
	point_append();
	data(GET)->tail_l->tail_p->z = z_coord;
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

int	main(int argc, char **argv)
{
	void *mlx;
	(void)mlx;
	(void)argv;
	if (argc != 2 || !init_check_file_extension(argv[1]))
		return (1);
	p_data(GET)->fd = open(argv[1], O_RDONLY);
	if (p_data(GET)->fd == -1)
		panic(1);
	int	check;
	int	i;
	static int count = 0;

	check = 1;
	while (check)
	{
		ft_printf("start\n");
		if (count != 1) {
			check = get_next_line(p_data(GET)->fd, &p_data(GET)->gnl_line, 0);
			count++;
		} else {
			check = 0;
		}
		if (!check)
			panic(1);
		if (!p_data(GET)->gnl_line)
			break ;
		line_append();
		i = 0;
		while(p_data(GET)->gnl_line[i])
		{
			while(p_data(GET)->gnl_line[i] && p_data(GET)->gnl_line[i] == ' ')
				i++;
			point_process(&p_data(GET)->gnl_line[i]);
			while(p_data(GET)->gnl_line[i] && p_data(GET)->gnl_line[i] != ' ')
				i++;
		}

		p_data_free_gnl();
		printf("%p\n", p_data(GET)->gnl_line);
		printf("finish\n");
	}
	dev_put_lines(Z);
	/*mlx = mlx_init();
	if (!mlx_new_window(mlx, 800, 500, "yo wtf"))
		return (1);*/
	printf("hello\n");
	p_data(FREE);
	data(EXIT);
}
