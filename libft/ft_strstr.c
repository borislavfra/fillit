/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:13:20 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/28 17:39:13 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	if (*needle == '\0')
		return ((char *)(haystack));
	while (haystack[k])
	{
		j = 0;
		i = k++;
		if (needle[j] == haystack[i])
			while (needle[j] && needle[j] == haystack[i])
			{
				j++;
				i++;
			}
		else
			i++;
		if (!needle[j])
			return ((char *)(&haystack[i - j]));
	}
	return (NULL);
}
