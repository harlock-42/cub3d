/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 18:29:21 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/19 13:38:52 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			is_space_correct(char **map, size_t y, size_t x)
{
	if (map[y][x + 1] != '\0' && map[y][x + 1] != ' ' && map[y][x + 1] != '1')
		return (-1);
	if (map[y + 1] && ft_strlen(map[y + 1]) > x)
		if (map[y + 1][x] != ' ' && map[y + 1][x] != '1')
			return (-1);
	if (x > 0 && map[y][x - 1] != ' ' && map[y][x - 1] != '1')
		return (-1);
	if (y > 0 && ft_strlen(map[y - 1]) > x)
		if (map[y - 1][x] != ' ' && map[y - 1][x] != '1')
			return (-1);
	map[y][x] = '1';
	return (1);
}

/*
** check si les espaces sont entouree par des 1.
** Si c est le cas, ils sont remplace par des 1.
*/

static	int	check_space(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y] && map[y][x])
		{
			if (map[y][x] == ' ')
				if (is_space_correct(map, y, x) < 0)
				{
					ft_printf("line %d\nchar %d\n", (int)y, (int)x);
					return (-1);
				}
			++x;
		}
		++y;
	}
	return (1);
}

/*
** check si les characteres de la map sont des characteres autorises.
*/

static	int	map_char_isok(char **map, size_t *count)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (map && map[j])
	{
		i = 0;
		while (map[j] && map[j][i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' ||
			map[j][i] == 'W')
				++*count;
			if (map[j][i] != '0' && map[j][i] != '1' && map[j][i] != '2' &&
			map[j][i] != ' ' && map[j][i] != 'N' && map[j][i] != 'S' &&
			map[j][i] != 'E' && map[j][i] != 'W')
				return (-1);
			++i;
		}
		++j;
	}
	return (1);
}

/*
** check la validite de la map.
*/

int			check_map(char **map)
{
	size_t		count;
	size_t		y;

	count = 0;
	y = 0;
	if (map_char_isok(map, &count) < 0)
		return (aie_error("character forbidden\n"));
	if (count == 0)
		return (aie_error("player position missing\n"));
	if (count > 1)
		return (aie_error("too many position player\n"));
	if (check_space(map) < 0)
		return (aie_error("invalid space position\n"));
	if (check_is_map_close(map) < 0)
		return (aie_error("map is not close in .cub file\n"));
	return (1);
}
