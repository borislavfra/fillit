/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:50:14 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 16:38:30 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*str;
	unsigned int	i;
	size_t			j;

	i = 0;
	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[i++])
		if (f(i - 1, s[i - 1]))
			len++;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < len)
	{
		if (f(i, s[i]))
			str[j++] = f(i, s[i]);
		i++;
	}
	return (str);
}
