/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:16:57 by jhallama          #+#    #+#             */
/*   Updated: 2019/10/30 18:36:23 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	count_length(int n)
{
	short	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char			*ft_itoa(int n)
{
	long	nb;
	short	len;
	char	*string;

	nb = n;
	len = count_length(nb);
	if (n < 0)
	{
		if (!(string = (char *)malloc(len++ + 2)))
			return (NULL);
		string[0] = '-';
		nb = -nb;
	}
	else if (!(string = (char *)malloc(len + 1)))
		return (NULL);
	string[len--] = '\0';
	if (nb == 0)
		string[0] = '0';
	while (nb != 0)
	{
		string[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (string);
}
