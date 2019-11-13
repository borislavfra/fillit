/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:50:38 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/04/21 12:11:44 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	find_mins_maxs(char buff[22], int xs[2], int ys[2])
{
	int		i;

	xs[0] = 10;
	ys[0] = 10;
	xs[1] = -1;
	ys[1] = -1;
	i = -1;
	while (++i < 21)
		if (buff[i] == '#')
		{
			if (i % 5 < xs[0])
				xs[0] = i % 5;
			if (i % 5 > xs[1])
				xs[1] = i % 5;
			if (i / 5 < ys[0])
				ys[0] = i / 5;
			if (i / 5 > ys[1])
				ys[1] = i / 5;
		}
}

static void	move_y(char buff[22], int ymin, int ymax)
{
	int		i;

	while (ymin-- > 0)
	{
		i = -1;
		while (++i < ymax * 5)
			buff[i] = buff[i + 5];
		ymax--;
	}
	i = (ymax + 1) * 5;
	while (buff[i] != '\0')
	{
		if (buff[i] != '\n')
			buff[i] = '.';
		i++;
	}
}

static void	move_x(char buff[22], int xmin, int xmax)
{
	int		i;
	int		j;

	while (xmin-- > 0)
	{
		j = 0;
		while (j < 4)
		{
			i = j * 5;
			while (i < xmax + j * 5)
			{
				buff[i] = buff[i + 1];
				i++;
			}
			j++;
			while (buff[i] != '\n')
				buff[i++] = '.';
		}
		xmax--;
	}
}

static int	convert_to_int(char buff[22])
{
	int		num;
	int		i;

	i = 0;
	num = 0;
	while (i < 22)
	{
		if (buff[i] == '#' || buff[i] == '.')
			num *= 2;
		if (buff[i] == '#')
			num += 1;
		i++;
	}
	return (num);
}

int			transform(char buff[22], t_tetramino *current_tetra)
{
	int		xs[2];
	int		ys[2];

	if (!check_connections(buff, ft_strlen(buff)))
		return (-1);
	find_mins_maxs(buff, xs, ys);
	if (xs[0] < 0 || xs[1] > 3 || ys[0] < 0 || ys[1] > 3)
		return (-1);
	move_y(buff, ys[0], ys[1]);
	move_x(buff, xs[0], xs[1]);
	(*current_tetra).content = convert_to_int(buff);
	(*current_tetra).x = 0;
	(*current_tetra).y = 0;
	(*current_tetra).height = ys[1] - ys[0] + 1;
	(*current_tetra).width = xs[1] - xs[0] + 1;
	return (1);
}
