/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/10 17:26:12 by jhallama         ###   ########.fr       */
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
# define WINDOW_W 800
# define WINDOW_H 600
# define BORDER 100

typedef struct	s_pixel {
	int				x;
	int				y;
	int				z;
	struct s_pixel	*next;
}				t_pixel;

typedef struct	s_map {
	void	*mlx_ptr;
	void	*win_ptr;
	char	***xy;
	int		w;
	int		h;
	int		ratio;
}				t_map;

t_map			*file_reader(char *input);
int				***create_int_array(t_map *map);
void			error_exit(char *reason);
int				width(t_map *map);
int				height(t_map *map);
void			draw_map(t_map *map);
#endif
