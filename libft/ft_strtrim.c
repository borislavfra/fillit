/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:32:17 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 17:07:55 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhite(const char s)
{
	if (s == ' ' || s == '\n' || s == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = -1;
	if (!s)
		return (0);
	while (iswhite(*s))
		s++;
	while (s[++i])
		if (!iswhite(s[i]))
			j = i;
	if ((str = ft_strnew((size_t)j + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i <= j && s[i])
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
