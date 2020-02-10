/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:36 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/10 14:24:07 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/get_next_line.h"

static int	calculate_ratio(t_map *map)
{
	int	ratio_w;
	int	ratio_h;

	ratio_w = (WINDOW_W - (2 * BORDER)) / map->w;
	ratio_h = (WINDOW_H - (2 * BORDER)) / map->h;
	if (ratio_w < ratio_h)
		return (ratio_w);
	else
		return (ratio_h);
}

static int	line_length(char ***xy)
{
	int	i;

	i = 0;
	while (xy[0][i])
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

t_map		*file_reader(char *input)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		ret;
	int		i;

	map = (t_map *)malloc(sizeof(t_map));
	if ((fd = open(input, O_RDONLY)) == -1)
		error_exit("open() failed");
	map->h = line_count(input);
	map->xy = (char ***)malloc(sizeof(char **) * map->h);
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map->xy[i++] = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	map->w = line_length(map->xy);
	if (ret == -1)
		error_exit("reading failed");
	map->xy[i] = NULL;
	if ((fd = close(fd)) == -1)
		error_exit("close() failed");
	map->ratio = calculate_ratio(map);
	return (map);
}
