/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:38:06 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/28 17:41:27 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (k < (int)len && haystack[k])
	{
		j = 0;
		i = k++;
		if (needle[j] == haystack[i])
			while (needle[j] && needle[j] == haystack[i] && i < (int)len)
			{
				i++;
				j++;
			}
		else
			i++;
		if (!needle[j])
			return ((char *)(&haystack[i - j]));
	}
	return (NULL);
}
