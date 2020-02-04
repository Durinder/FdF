/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:50 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/04 16:17:41 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>

int		deal_key(int key)
{
	ft_printf("%d\n", key);
	if (key == 53)
		exit (0);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	***map;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf file.fdf");
		exit(0);
	}
	map = file_reader(argv[1]);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, argv[1]);
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
