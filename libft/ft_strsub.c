/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:30:42 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/01/29 16:35:58 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	while (j < start)
		j++;
	while (i < len)
		str[i++] = s[j++];
	return (str);
}
