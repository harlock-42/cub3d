/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_map_close.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 16:19:30 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/01 18:45:14 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** verifie que la premiere colonne de la map ne contient des 1.
*/

static		int		first_column(char **map)
{
	size_t	i;

	i = 0;
	while (map && map[i])
	{
		if (map[i][0] != '1')
		{
			ft_printf("char : 0\nline : %d\n", (int)i);
			return (-1);
		}
		++i;
	}
	return (1);
}

/*
** verifie que la derniere ligne de la map ne contient que des 1.
*/

static	int			last_line(char *map)
{
	size_t		i;

	i = 0;
	while (map && map[i])
	{
		if (map[i] != '1')
		{
			ft_printf("char : %d\n", (int)i);
			return (-1);
		}
		++i;
	}
	return (1);
}

/*
** verifie que la premiere ligne de la map ne contient que des 1.
*/

static	int			first_line(char *map)
{
	size_t		i;

	i = 0;
	while (map && map[i])
	{
		if (map[i] != '1')
		{
			ft_printf("char : %d\n", (int)i);
			return (-1);
		}
		++i;
	}
	return (1);
}

/*
** verifie que la map soit entouree de 1.
*/

int			check_is_map_close(char **map)
{
	size_t	size;

	size = 0;
	while (map && map[size])
		++size;
	if (first_line(map[0]) < 0)
		return (aie_error("line : 1\n"));
	if (last_line(map[size - 1]) < 0)
	{
		ft_printf("line : %d\n", (int)size);
		return (-1);
	}
	if (first_column(map) < 0)
		return (-1);
	if (last_column(map) < 0)
		return (-1);
	return (1);
}
