/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:58:40 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/19 13:37:10 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"

static t_point	iso(t_point point, t_mlx *mlx)
{
	int old_x;
	int	old_y;

	old_x = point.x * mlx->ratio + BORDER;
	old_y = point.y * mlx->ratio + BORDER;
	point.x = (old_x - old_y) * cos(0.523598776) + WINDOW_W / 2 - 2 * BORDER;
	point.y = (old_x + old_y) * sin(0.523598776) - point.z * mlx->flatten +
		WINDOW_H / 3 - 2 * BORDER;
	point.x += mlx->move_h;
	point.y += mlx->move_v;
	return (point);
}

static t_point	top_down(t_point point, t_mlx *mlx)
{
	point.x = point.x * mlx->ratio + BORDER;
	point.y = point.y * mlx->ratio + BORDER - point.z * mlx->flatten;
	point.x += mlx->move_h;
	point.y += mlx->move_v;
	return (point);
}

t_point			project(t_point point, t_mlx *mlx)
{
	if (mlx->projection == 1)
		point = top_down(point, mlx);
	if (mlx->projection == 0)
		point = iso(point, mlx);
	return (point);
}
