/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/18 13:55:20 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define WINDOW_W 1280
# define WINDOW_H 780
# define BORDER 50

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
	int		move_v;
	int		move_h;
	int		flatten;
	int		max_z;
	int		min_z;
	t_image	image;
}				t_mlx;

t_mlx			*file_reader(char *input);
void			error_exit(char *reason);
void			render(t_mlx *mlx);
t_point			project(t_point point, t_mlx *mlx);
void			color_ranges(t_mlx *mlx);
int				get_color(t_point p0, t_point p1, t_mlx *mlx, int dx, int dy);
int				default_colors(t_point point, t_mlx *mlx);
#endif
