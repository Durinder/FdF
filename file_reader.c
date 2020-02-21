/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:36 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/21 11:47:19 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/get_next_line.h"

static int	calculate_ratio(t_mlx *mlx)
{
	int	ratio_w;
	int	ratio_h;

	mlx->projection = 0;
	ratio_w = (WINDOW_W - (2 * BORDER)) / mlx->w;
	ratio_h = (WINDOW_H - (2 * BORDER)) / mlx->h;
	if (ratio_w < ratio_h)
		return (ratio_w / 2);
	else
		return (ratio_h / 2);
}

static int	line_length(char ***map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static int	line_count(char *input)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	if ((fd = open(input, O_RDONLY)) == -1)
		error_exit("open() failed");
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		i++;
	}
	if ((fd = close(fd)) == -1)
		error_exit("close() failed");
	return (i);
}

t_mlx		*file_reader(char *input)
{
	t_mlx	*mlx;
	char	*line;
	int		fd;
	int		ret;
	int		i;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if ((fd = open(input, O_RDONLY)) == -1)
		error_exit("open() failed");
	mlx->h = line_count(input);
	mlx->map = (char ***)malloc(sizeof(char **) * (mlx->h + 1));
	mlx->map[mlx->h] = NULL;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		mlx->map[i++] = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	mlx->w = line_length(mlx->map);
	if (ret == -1)
		error_exit("reading failed");
	mlx->map[i] = NULL;
	if ((fd = close(fd)) == -1)
		error_exit("close() failed");
	mlx->ratio = calculate_ratio(mlx);
	return (mlx);
}
