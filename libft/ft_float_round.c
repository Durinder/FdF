/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:24:29 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/17 12:18:42 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*rounding(char *s, int precision)
{
	char	*tmp;
	size_t	carry;
	size_t	i;

	carry = 0;
	i = 0;
	if (s[precision] >= '5')
	{
		carry++;
		i = precision;
		while (i >= 0 && s[--i] >= '9')
			carry++;
	}
	tmp = ft_strsub(s, 0, precision);
	while (precision--)
		if (carry)
		{
			tmp[precision] = s[precision] + 1;
			if (tmp[precision] == 58)
				tmp[precision] = '0';
			carry--;
		}
	ft_strdel(&s);
	return (tmp);
}

static char		*decimal_assignment(char *s, int precision)
{
	char	*tmp;
	size_t	i;

	if ((int)ft_strlen(s) < precision)
	{
		if (!(tmp = ft_strnew(precision)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			tmp[i] = s[i];
			i++;
			precision--;
		}
		while (precision--)
			tmp[i++] = '0';
		ft_strdel(&s);
		return (tmp);
	}
	else
		return (s = rounding(s, precision));
}

static char		*decimal_overflow_assignment(char *s, long long i, size_t carry,
		char *tmp)
{
	if (i == -1 || (i == 0 && s[0] == '-'))
	{
		if (!(tmp = ft_strnew(ft_strlen(s))))
			return (NULL);
		i = 0;
		if (s[0] == '-')
			tmp[i++] = '-';
		tmp[i++] = '1';
		while (carry-- > 1)
			tmp[i++] = '0';
		ft_strdel(&s);
		return (tmp);
	}
	else
	{
		i = ft_strlen(s) - 1;
		while (carry--)
		{
			s[i--] += 1;
			if (s[i + 1] == 58)
				s[i + 1] = '0';
		}
	}
	return (s);
}

static char		*integer_assignment(char *integers, const char *decimals,
		int precision)
{
	char	*tmp;
	size_t	i;
	size_t	carry;

	if ((int)ft_strlen(decimals) <= precision)
		return (integers);
	else if (decimals[precision--] >= '5')
	{
		while (precision >= 0 && decimals[precision] == '9')
			precision--;
		if (precision == -1)
		{
			i = ft_strlen(integers) - 1;
			carry = 1;
			while (i >= 0 && integers[i] == '9')
			{
				i--;
				carry++;
			}
			tmp = NULL;
			integers = decimal_overflow_assignment(integers, i, carry, tmp);
		}
	}
	return (integers);
}

char			*ft_float_round(const char *src, int precision)
{
	char	*integers;
	char	*decimals;
	char	*result;
	size_t	i;
	size_t	j;

	if (precision == -1)
		precision = 6;
	i = 0;
	while (src[i] != '.' && src[i] != '\0')
		i++;
	integers = ft_strsub(src, 0, i);
	j = 0;
	while (src[j])
		j++;
	decimals = ft_strsub(src, i + 1, j);
	integers = integer_assignment(integers, decimals, precision);
	decimals = decimal_assignment(decimals, precision);
	if (decimals[0])
		integers = ft_strncat(integers, ".", 1);
	result = ft_strjoin(integers, decimals);
	ft_strdel(&integers);
	ft_strdel(&decimals);
	return (result);
}
