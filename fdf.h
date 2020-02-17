/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/17 14:23:57 by jhallama         ###   ########.fr       */
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

typedef struct	s_image {
	void	*ptr;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	char	***map;
	int		w;
	int		h;
	int		ratio;
	char	projection;
	t_image	image;
}				t_mlx;

t_mlx			*file_reader(char *input);
void			error_exit(char *reason);
void			render(t_mlx *mlx);
t_point			project(t_point point, t_mlx *mlx);
#endif
