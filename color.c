/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:20:48 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/19 11:50:53 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static int		calculate(int start, int end, double percentage)
{
	return ((1 - percentage) * start + percentage * end);
}

static double	ratio(int start, int current, int end)
{
	double	result;
	int		distance;
	int		waypoint;

	distance = end - start;
	if (distance == 0)
		return (1.0);
	waypoint = current - start;
	result = waypoint / distance;
	return (waypoint / distance);
}

int				get_color(t_point start, t_point current, t_point end, int d[2])
{
	double	percentage;
	int		r;
	int		g;
	int		b;

	if (d[0] > d[1])
		percentage = ratio(start.x, current.x, end.x);
	else
		percentage = ratio(start.y, current.y, end.y);
	r = calculate(current.color >> 16 & 0xFF,
			end.color >> 16 & 0xFF, percentage);
	g = calculate(current.color >> 8 & 0xFF,
			end.color >> 8 & 0xFF, percentage);
	b = calculate(current.color & 0xFF,
			end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}

int				default_colors(t_point point, t_mlx *mlx)
{
	double	percentage;
	double	tmp_max;
	double	tmp_min;

	if (mlx->flatten == 0)
		return (0xFFFFFF);
	tmp_max = mlx->max_z / mlx->flatten;
	tmp_min = mlx->min_z / mlx->flatten;
	if (tmp_max - tmp_min == 0)
		return (0xFFFFFF);
	percentage = fabs(point.z / (tmp_max - tmp_min));
	if (percentage < 0.17)
		return (0xFDFEFE);
	if (percentage < 0.33)
		return (0xDAF7A6);
	if (percentage < 0.5)
		return (0xFFC300);
	if (percentage < 0.67)
		return (0xFF5733);
	if (percentage < 0.83)
		return (0xC70039);
	else
		return (0x900C3F);
}

void			color_ranges(t_mlx *mlx)
{
	size_t	i;
	size_t	j;

	i = -1;
	mlx->max_z = 0;
	mlx->min_z = 0;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (ft_atoi(mlx->map[i][j]) *
					(mlx->flatten) > mlx->max_z)
				mlx->max_z = ft_atoi(mlx->map[i][j]) *
					(mlx->flatten);
			if (ft_atoi(mlx->map[i][j]) *
					(mlx->flatten) < mlx->min_z)
				mlx->min_z = ft_atoi(mlx->map[i][j]) *
					(mlx->flatten);
		}
	}
}
