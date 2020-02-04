/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:44:36 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/04 16:32:42 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/get_next_line.h"

static size_t	line_count(char *input)
{
	int		fd;
	int		ret;
	size_t	i;
	char	*line;

	if ((fd = open(input, O_RDONLY)) == -1)
		error_exit("open() failed");
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
		i++;
	if ((fd = close(fd)) == -1)
		error_exit("close() failed");
	ft_putnbr(i);
	ft_strdel(&line);
	return (i);
}

char	***file_reader(char *input)
{
	char	***map;
	char	*line;
	int		fd;
	int		ret;
	size_t	i;

	if ((fd = open(input, O_RDONLY)) == -1)
		error_exit("open() failed");
	i = line_count(input);
	map = (char ***)malloc(sizeof(char **) * i);
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map[i++] = ft_strsplit(line, ' ');
	}
	if (ret == -1)
		error_exit("reading failed");
	map[i] = NULL;
	if ((fd = close(fd)) == -1)
		error_exit("close() failed");
	ft_strdel(&line);
	return (map);
}
