/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 09:43:47 by jhallama          #+#    #+#             */
/*   Updated: 2019/11/19 12:27:33 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_line(char **s, int fd, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	if (s[fd] == NULL)
		return (0);
	while (s[fd][len] != '\0')
	{
		if (s[fd][len] == '\n')
		{
			*line = ft_strsub(s[fd], 0, len);
			tmp = ft_strdup(s[fd] + len + 1);
			ft_strdel(&s[fd]);
			s[fd] = tmp;
			return (1);
		}
		len++;
		if (s[fd][len] == '\0')
		{
			*line = ft_strdup(s[fd]);
			ft_strdel(&s[fd]);
			return (1);
		}
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*s[FD_SIZE];
	char		*tmp;

	if (fd == -1 || fd > FD_SIZE || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			ft_strdel(&s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	return (return_line(s, fd, line));
}
