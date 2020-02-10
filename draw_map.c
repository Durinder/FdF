/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:55:03 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/10 18:07:08 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static void	draw_line(int *p0, int *p1, t_map *map)
{
	int	dx;
	int sx;
	int dy;
	int	sy;
	int	error;
	int	e2;
	int x0;
	int x1;
	int y0;
	int y1;

	x0 = p0[0];
	x1 = p1[0];
	y0 = p0[1];
	y1 = p1[1];
	free(p0);
	free(p1);
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	error = dx + dy;
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x0, y0, 0xffffff);
		e2 = 2 * error;
		if (e2 >= dy)
		{
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			error += dx;
			y0 += sy;
		}
	}
}

static int		*rotate_z_30_clockwise(int x, int y, int z, int ratio)
{
	int	*p;

	p = (int *)malloc(sizeof(int) * 3);
	if (p == NULL)
		error_exit("malloc error");
	x *= ratio;
	y *= ratio;
	p[0] = ((sqrt(3) * x) / 2) + (y / 2) + BORDER;
	p[1] = ((sqrt(3) * y) / 2) - (x / 2) - z + BORDER * 2;
//	ft_printf("x = %d\n", p[0]);
//	ft_printf("y = %d\n", p[1]);
	p[2] = z;
	return (p);
}

void		draw_map(t_map *map)
{
	int	x;
	int y;
	int *p0;
	int *p1;

	x = 0;
	while (map->xy[x])
	{
		y = 0;
		while (map->xy[x][y])
		{
			if (map->xy[x + 1])
			{
				p0 = rotate_z_30_clockwise(x, y, ft_atoi(map->xy[x][y]), map->ratio);
				p1 = rotate_z_30_clockwise(x + 1, y, ft_atoi(map->xy[x + 1][y]), map->ratio);
				draw_line(p0, p1, map);
			}
			if (map->xy[x][y + 1])
			{
				p0 = rotate_z_30_clockwise(x, y, ft_atoi(map->xy[x][y]), map->ratio);
				p1 = rotate_z_30_clockwise(x, y + 1, ft_atoi(map->xy[x][y + 1]), map->ratio);
				draw_line(p0, p1, map);
			}
			y++;
		}
		x++;
	}
}
