/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:51:37 by dwalda-r          #+#    #+#             */
/*   Updated: 2018/12/27 17:32:59 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wn(char const *s, char c)
{
	int		wn;

	wn = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			wn++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (wn);
}

static size_t	nextword(char const **s, char c)
{
	size_t	len;

	if (!s || !*s)
		return (0);
	len = 0;
	while (**s == c && **s != '\0')
		(*s)++;
	while (**s != c && **s != '\0')
	{
		(*s)++;
		len++;
	}
	return (len);
}

static char		**addmemory(char const *s, char c)
{
	size_t	k;
	size_t	won;
	char	**a;

	if (!s)
		return (NULL);
	k = 0;
	won = wn(s, c);
	if ((a = (char **)malloc((won + 1) * sizeof(char *))) == NULL)
		return (NULL);
	while (k < won)
		if ((a[k++] = ft_strnew(nextword(&s, c))) == NULL)
			return (NULL);
	if ((a[k] = ft_strnew(0)) == NULL)
		return (NULL);
	a[k] = NULL;
	return (a);
}

static void		mkthemfull(char ***a, char const *s, char c)
{
	size_t	won;
	size_t	i;
	size_t	j;

	i = 0;
	if (!a || !s || !*a || !**a)
		return ;
	won = wn(s, c);
	while (i < won)
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			(*a)[i][j++] = *s;
			s++;
		}
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;

	if (!s)
		return (NULL);
	a = addmemory(s, c);
	mkthemfull(&a, s, c);
	return (a);
}
