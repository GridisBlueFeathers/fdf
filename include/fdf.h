/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:55:51 by svereten          #+#    #+#             */
/*   Updated: 2024/09/22 13:50:23 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

# define INV_EXT "fdf: Invalid file extention"
# define INV_MAP "fdf: Invalid map"

# define WIN_W 1600
# define WIN_H 1200

typedef	enum	e_option
{
	GET,
	FREE,
	EXIT,
}	t_option;

typedef	struct	s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

void	img_init(void);

typedef struct	s_data
{
	int	width;
	int	height;
	int	actual_height;
	t_img	img;
	void	*mlx;
	void	*mlx_win;
	int		**matrix;
	int		**color;
}	t_data;

t_data	*data(t_option op);

void	matrix_process(void);

typedef struct	s_p_data
{
	int		fd;
	char	*line;
	char	**split_line;
	char	**argv;
}	t_p_data;

t_p_data	*p_data(t_option op);

int		init_check_file_extension(char *filename);

void	fdf_mlx_init();
int		hook_key(int key, void	*ptr);
int		hook_close(void	*ptr);
int		hook_idle(void	*ptr);

void	panic(int status);
void	panic_msg(int status, char *msg);
void	panic_silent(int status);

#endif
