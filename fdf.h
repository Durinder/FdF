/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:42 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/04 16:32:37 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_pixel {
	int				x;
	int				y;
	int 			z;
	struct s_pixel	*next;
}				t_pixel;

typedef struct	s_map {
	char			**xy;
	struct s_pixel	pixel;
}				t_map;

char	***file_reader(char *input);
void	error_exit(char *reason);
