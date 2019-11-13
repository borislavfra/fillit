/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwalda-r <dwalda-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:30:19 by dwalda-r          #+#    #+#             */
/*   Updated: 2019/05/02 13:07:13 by dwalda-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	check_sides(char buff[22], int len, int *con_count, int i)
{
	if (i - 1 >= 0 && buff[i - 1] == '#')
		(*con_count)++;
	if (i + 1 <= len && buff[i + 1] == '#')
		(*con_count)++;
	if (i - 5 >= 0 && buff[i - 5] == '#')
		(*con_count)++;
	if (i + 5 <= len && buff[i + 5] == '#')
		(*con_count)++;
}

int			check_connections(char buff[22], int len)
{
	int		i;
	int		count;
	int		con_count;

	count = 0;
	con_count = 0;
	i = 0;
	if (len != 21)
		return (0);
	while (i < len)
	{
		if (buff[i] != '#' && buff[i] != '\n' && buff[i] != '\0'
		&& buff[i] != '.')
			return (0);
		else if (buff[i] == '#')
		{
			count++;
			check_sides(buff, len, &con_count, i);
		}
		i++;
	}
	return ((count == 4 && (con_count == 8 || con_count == 6)) ? 1 : 0);
}

static int	read_tetros(int fd, t_tetramino a_tetras[26])
{
	int			ret;
	char		buff[22];
	int			i;
	int			j;
	int			old_ret;

	i = 0;
	ret = 0;
	old_ret = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		if (ret == 20)
			buff[20] = '\n';
		buff[21] = '\0';
		if (i > 25 || (transform(buff, &(a_tetras[i++]))) == -1 || (ret == 21 &&
		buff[20] != '\n'))
			return (-1);
		old_ret = ret;
	}
	if (ret == -1 || (ret == 0 && old_ret == 21) || (ret == 0 && old_ret == 0))
		return (-1);
	j = i;
	while (j < 26)
		a_tetras[j++].content = 0;
	return (i);
}

int			main(int ac, char **arg)
{
	int			fd;
	t_tetramino	a[26];
	int			i;
	int			j;

	if (ac != 2)
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	j = 0;
	fd = open(arg[1], O_RDONLY);
	if ((i = read_tetros(fd, a)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	generate_map(i, a);
	return (0);
}
