/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:41:17 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/04/22 10:26:45 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tetramino
{
	int			content;
	int			x;
	int			y;
	int			width;
	int			height;
}				t_tetramino;

int				check_connections(char buff[22], int len);
void			generate_map(int tetra_num, t_tetramino a_tetras[26]);
int				check_piece(t_tetramino a_tetras[26], int map[16],
int size, int i);
void			output(int size, t_tetramino a_tetra[16]);
int				transform(char buff[22], t_tetramino *current_tetra);
#endif
