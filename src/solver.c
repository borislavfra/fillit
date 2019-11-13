/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 11:57:17 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/04/21 12:12:37 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_place(t_tetramino *a_tetra, int map[16], int x, int y)
{
	int		num_to_check[4];

	num_to_check[0] = ((*a_tetra).content & 61440) >> x;
	if (num_to_check[0] + map[y] != (num_to_check[0] ^ map[y]))
		return (0);
	num_to_check[1] = ((*a_tetra).content & 3840) << 4 >> x;
	if (num_to_check[1] + map[y + 1] != (num_to_check[1] ^ map[y + 1]))
		return (0);
	num_to_check[2] = ((*a_tetra).content & 240) << 8 >> x;
	if (num_to_check[2] + map[y + 2] != (num_to_check[2] ^ map[y + 2]))
		return (0);
	num_to_check[3] = ((*a_tetra).content & 15) << 12 >> x;
	if (num_to_check[3] + map[y + 3] != (num_to_check[3] ^ map[y + 3]))
		return (0);
	map[y] += num_to_check[0];
	map[y + 1] += num_to_check[1];
	map[y + 2] += num_to_check[2];
	map[y + 3] += num_to_check[3];
	(*a_tetra).x = x;
	(*a_tetra).y = y;
	return (1);
}

static void	delete_last(t_tetramino *a_tetra, int map[16], int x, int y)
{
	map[y] -= ((*a_tetra).content & 61440) >> x;
	map[y + 1] -= ((*a_tetra).content & 3840) << 4 >> x;
	map[y + 2] -= ((*a_tetra).content & 240) << 8 >> x;
	map[y + 3] -= ((*a_tetra).content & 15) << 12 >> x;
}

int			check_piece(t_tetramino a_tetras[26], int map[16], int size, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (a_tetras[i].content == 0)
		return (1);
	while (y + a_tetras[i].height <= size)
	{
		x = 0;
		while (x++ + a_tetras[i].width <= size)
		{
			if (check_place(&(a_tetras[i]), map, x - 1, y))
			{
				if (check_piece(a_tetras, map, size, i + 1))
					return (1);
				else
					delete_last(&(a_tetras[i]), map, x - 1, y);
			}
		}
		y++;
	}
	return (0);
}
