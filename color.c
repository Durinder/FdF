/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:20:48 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/18 16:10:36 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

static int	calculate(t_point p0, t_point p1,
		double percentage)
{
	return ((1 - percentage) * p0.x + percentage * p1.x);
}

int			get_color(t_point p0, t_point p1, t_mlx *mlx, int dx, int dy)
{
	double	percentage;
	int 	red;
	int		green;
	int 	blue;

	ft_putnbr(dx);
	ft_putnbr(dy);
	percentage = p0.z / (mlx->max_z - mlx->min_z);
	red = 0x000000 & calculate(p0, p1, percentage);
	blue = 0x000000 & calculate(p0, p1, percentage);
	green = 0x000000 & calculate(p0, p1, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int			default_colors(t_point point, t_mlx *mlx)
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

void		color_ranges(t_mlx *mlx)
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
//	ft_printf("min: %d, max: %d\n", mlx->min_z, mlx->max_z);
}
