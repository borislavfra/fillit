/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:30:08 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 16:41:49 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	norm(int num)
{
	if (num == 0)
		return (1);
	return (0);
}

int			ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (norm(ft_strcmp(s1, s2)));
	else
		return (0);
}
