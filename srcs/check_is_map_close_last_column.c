/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_map_close_last_column.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:42:58 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:43:33 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** verifie que le reste de la ligne ne comporte que des 1.
*/

static		int		is_last_one(char *line)
{
	size_t	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != '1')
			return (-1);
		++i;
	}
	return (1);
}

/*
** verifie que la gine est fermee par 1 valide.
*/

static		int		is_line_ok(char **map, size_t y, size_t x)
{
	int		k;

	k = (-1);
	while (map[y] && map[y][x])
	{
		while (ft_strlen(map[y - 1]) < x - 1 && map[y - 1][x + k] && k < 2)
		{
			k = (-1);
			if (map[y - 1][x + k] == '1')
				if (is_last_one(map[y - 1] + (x + k)) > 0)
					return (1);
			++k;
		}
		++k;
	}
	return (-1);
}

/*
** Place le compteur x sur le premier 1 adjacent a un zero
** en partant de la fin de la ligne.
*/

static		int		init_x(char *line)
{
	size_t	x;

	x = ft_strlen(line) - 1;
	while (x > 0 && line[x - 1] == '1')
		--x;
	return (x);
}

/*
** verifie que la derniere colomne de la map ne contienne que des 1.
*/

int					last_column(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map && map[y] && is_last_one(map[y]) > 0)
		++y;
	while (map && map[y])
	{
		x = init_x(map[y]);
		if (is_line_ok(map, y, x) < 0)
			return (-1);
		++y;
	}
	return (1);
}
