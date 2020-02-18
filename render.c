/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:34:17 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/18 16:01:20 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/ft_printf/ft_printf.h"

static void		pixel_put(int x, int y, t_image *image, int color)
{
	int		i;

	if (x >= 0 && x < WINDOW_W &&
			y >= 0 && y < WINDOW_H)
	{
		i = (x * image->bpp / 8) + (y * image->size_line);
		image->data_addr[i] = color;
		image->data_addr[++i] = color >> 8;
		image->data_addr[++i] = color >> 16;
	}
}

static t_point	create_point(int x, int y, t_mlx *mlx)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(mlx->map[y][x]);
	point.color = default_colors(point, mlx);
	return (point);
}

static void		draw_line(t_point p0, t_point p1, t_mlx *mlx)
{
	int	dx;
	int sx;
	int dy;
	int	sy;
	int	error[2];

	dx = abs(p1.x - p0.x);
	sx = p0.x < p1.x ? 1 : -1;
	dy = -abs(p1.y - p0.y);
	sy = p0.y < p1.y ? 1 : -1;
	error[0] = dx + dy;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		pixel_put(p0.x, p0.y, &mlx->image, p0.color); //get_color(p0, p1, mlx, dx, dy));
		error[1] = 2 * error[0];
		error[0] += error[1] >= dy ? dy : 0;
		p0.x += error[1] >= dy ? sx : 0;
		error[0] += error[1] <= dx ? dx : 0;
		p0.y += error[1] <= dx ? sy : 0;
	}
}

static t_image	init_image(t_mlx *mlx)
{
	t_image	image;

	image.ptr = mlx_new_image(mlx->mlx_ptr, WINDOW_W, WINDOW_H);
	image.data_addr = mlx_get_data_addr(image.ptr, &image.bpp,
			&image.size_line, &image.endian);
	return (image);
}

void			render(t_mlx *mlx)
{
	int		i;
	int		j;

	mlx->image = init_image(mlx);
	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j + 1])
			{
				draw_line(project(create_point(j, i, mlx), mlx),
					project(create_point(j + 1, i, mlx), mlx), mlx);
			}
			if (mlx->map[i + 1] && mlx->map[i + 1][j])
			{
				draw_line(project(create_point(j, i, mlx), mlx),
					project(create_point(j, i + 1, mlx), mlx), mlx);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->image.ptr, 0, 0);
}
