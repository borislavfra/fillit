/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:39:35 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/26 16:33:31 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	s11;
	unsigned char	s22;
	size_t			i;

	i = 0;
	while (i < n)
	{
		s11 = ((unsigned char *)s1)[i];
		s22 = ((unsigned char *)s2)[i];
		if (s11 != s22)
			return (s11 - s22);
		i++;
	}
	return (0);
}
