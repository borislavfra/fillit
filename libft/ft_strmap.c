/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:08:57 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 16:34:02 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*str;
	int		i;
	size_t	j;

	i = 0;
	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		if (f(s[i++]))
			len++;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (j < len)
		if (f(s[++i]))
			str[j++] = f(s[i]);
	return (str);
}
