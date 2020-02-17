/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:42:50 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/17 15:41:45 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"

int		deal_key(int key, t_mlx *mlx)
{
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
	if (key == 126 || key == 125)
	{
		mlx->ratio += (key == 126) ? 1 : -1;
		mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
		render(mlx);
	}
	return (0);
}

int		validate_map(char ***map)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			k = -1;
			while (map[i][j][++k])
			{
				if (ft_isdigit(map[i][j][k]) == 0 && map[i][j][k] != '-')
					return (-1);
			}
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		error_exit("Usage: ./fdf file.fdf");
	mlx = file_reader(argv[1]);
	if (validate_map(mlx->map) == -1)
		error_exit("Map not valid");
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WINDOW_W, WINDOW_H, "fdf");
	render(mlx);
	mlx_key_hook(mlx->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
