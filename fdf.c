/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:50 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/17 13:34:18 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

int		deal_key(int key, t_mlx *mlx)
{
	ft_printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 124)
	{
		ft_putendl("jep");
		mlx_destroy_image(mlx->mlx_ptr, image->ptr);
		ft_putendl("wut");
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_putendl("omg");
		mlx->projection = 0;
		ft_putendl("hello");
		render(mlx);
		ft_putendl("kek");
	}
	if (key == 123)
	{
		mlx->projection = 1;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		render(mlx);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		error_exit("Usage: ./fdf file.fdf");
	mlx = file_reader(argv[1]);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_W, WINDOW_H, "fdf");
	render(mlx);
	mlx_key_hook(mlx->win_ptr, deal_key, (void *)0);
	/*	size_t	i = 0;
	size_t	j = 0;
	while (map->xy[i])
	{
		j = 0;
		while (map->xy[i][j])
			ft_printf(map->xy[i][j++]);
		ft_printf("\n");
		i++;
	}
//	ft_putchar('\n');
	ft_putnbr(ft_atoi(map->xy[2][5]));
	ft_putnbr(ft_atoi(map->xy[2][6]));*/
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
