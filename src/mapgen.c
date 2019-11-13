/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 12:00:32 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/04/22 09:34:18 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_next_square(int a)
{
	int		i;

	i = 0;
	while (i * i < a)
		i++;
	return (i);
}

static void	set_map_zero(int map[16])
{
	int		i;

	i = 0;
	while (i < 16)
		map[i++] = 0;
}

void		generate_map(int tetra_num, t_tetramino a_tetras[26])
{
	int		map[16];
	int		cur_size;

	set_map_zero(map);
	cur_size = find_next_square(tetra_num * 4);
	while (!check_piece(a_tetras, map, cur_size, 0))
	{
		cur_size++;
	}
	output(cur_size, a_tetras);
}
