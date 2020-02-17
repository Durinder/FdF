/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/14 16:36:47 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define RANGE_CHANGE(x,a,b,min,max) (((b)-(a))*((x)-(min))/((max)-(min)))+(a)
# define WINDOW_W 1280
# define WINDOW_H 780
# define BORDER 10

typedef struct	s_point {
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	char	***map;
	int		w;
	int		h;
	int		ratio;
	char	projection;
}				t_mlx;

typedef struct s_image {
	void	*ptr;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

t_mlx			*file_reader(char *input);
//int				***create_int_array(t_mlx *mlx);
void			error_exit(char *reason);
//int				width(t_mlx *mlx);
//int				height(t_mlx *mlx);
void			render(t_mlx *mlx);
t_point			project(t_point point, t_mlx *mlx);
//void			draw_map(t_mlx *mlx);
#endif
