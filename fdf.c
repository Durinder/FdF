/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:50 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/17 14:10:31 by jhallama         ###   ########.fr       */
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
	if (key == 124 || key == 123)
	{
		if (mlx->projection == 1)
			mlx->projection = 0;
		else
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
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
