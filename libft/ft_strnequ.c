/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:59:26 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 16:43:10 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	norm(int i)
{
	if (i == 0)
		return (1);
	return (0);
}

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	s11;
	unsigned char	s22;
	size_t			i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n)
		i++;
	i = (i >= n) ? i - 1 : i;
	s11 = s1[i];
	s22 = s2[i];
	return (norm(s11 - s22));
}
