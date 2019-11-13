/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:48:51 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 17:33:51 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getlength(long int n)
{
	size_t		len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*zeroex(size_t len)
{
	char		*str;

	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str[0] = '0';
	return (str);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*str;
	long int	num;

	num = n;
	len = getlength(num);
	if (num == 0)
	{
		if ((str = zeroex(len)) == NULL)
			return (NULL);
		return (str);
	}
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--len] = (num % 10 + '0');
		num /= 10;
	}
	return (str);
}
