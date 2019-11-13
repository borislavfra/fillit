/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:14:29 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/01/29 18:12:49 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*c;
	size_t	len;

	len = ft_strlen(src);
	if ((c = ft_strnew(len)) == NULL)
		return (NULL);
	len = 0;
	while (src[len])
	{
		c[len] = src[len];
		len++;
	}
	c[len] = '\0';
	return (c);
}
