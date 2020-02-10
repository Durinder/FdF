/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:50 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/10 14:41:29 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

int		deal_key(int key)//, t_map *map)
{
	ft_printf("%d\n", key);
	if (key == 53)
		exit(0);
/*	if (key == 126)
	{
		map->ratio += 1;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	if (key == 125)
	{
		map->ratio -= 1;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}*/
	return (0);
}

int		main(int argc, char **argv)
{
	t_map	*map;
//	int		***array;

	if (argc != 2)
		error_exit("Usage: ./fdf file.fdf");
	map = file_reader(argv[1]);
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WINDOW_W + 2 * BORDER, WINDOW_H + 2 * BORDER, "fdf");
	draw_map(map);
//	mlx_pixel_put(mlx_ptr, win_ptr, 0, 0, 0xfff647);
	mlx_key_hook(map->win_ptr, deal_key, (void *)0);
/*	ft_putnbr(map->ratio);
	ft_putnbr(map->w);
	ft_putnbr(map->h);
	size_t	i = 0;
	size_t	j = 0;
	while (map->xy[i])
	{
		j = 0;
		while (map->xy[i][j])
			ft_printf(map->xy[i][j++]);
		ft_printf("\n");
		i++;
	}*/
	mlx_loop(map->mlx_ptr);
	return (0);
}
