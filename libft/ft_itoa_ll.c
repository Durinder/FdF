/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 14:33:40 by jhallama          #+#    #+#             */
/*   Updated: 2019/12/29 14:23:54 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*long_long_min(char *string, long long nb, short len)
{
	string[len--] = '\0';
	string[len--] = '8';
	nb = 922337203685477580;
	while (nb != 0)
	{
		string[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (string);
}

static short	count_length(long long n)
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

char			*ft_itoa_ll(long long nb)
{
	short	len;
	char	*string;

	len = count_length(nb);
	if (nb < 0)
	{
		if (!(string = (char *)malloc(len++ + 2)))
			return (NULL);
		string[0] = '-';
		if ((unsigned long long)nb == -9223372036854775808ULL)
			return (long_long_min(string, nb, len));
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
