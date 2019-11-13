/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:52:57 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/04/22 15:06:31 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_map(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size * size)
	{
		ft_putchar(str[i]);
		if (i % size == size - 1)
			ft_putchar('\n');
		i++;
	}
	ft_strdel(&str);
}

void		output(int size, t_tetramino a_tetra[16])
{
	int		i;
	int		j;
	int		num;
	char	*str;
	char	c;

	c = 'A';
	str = (char *)malloc(sizeof(char) * size * size);
	ft_memset(str, '.', size * size);
	i = 0;
	while (a_tetra[i].content != 0)
	{
		j = -1;
		num = 32768;
		while (++j < 16)
		{
			if ((a_tetra[i].content ^ num) < a_tetra[i].content)
				str[a_tetra[i].x + j % 4 + (a_tetra[i].y + j / 4) * size] = c;
			num >>= 1;
		}
		i++;
		c++;
	}
	print_map(str, size);
}
