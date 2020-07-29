/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:28:52 by harlock           #+#    #+#             */
/*   Updated: 2020/07/29 16:00:48 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	is_eol_next(char *str)
{
	size_t		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (-1);
		++i;
	}
	return (1);
}

/*
** check le positionnement des virgules pour le floor et le ciel.
*/

static	int	check_coma(char *str)
{
	size_t		i;

	i = 0;
	while (str + i && str[i])
	{
		while (str[i] >= '0' && str[i] <= '9' && str[i])
			++i;
		if (str[i] == '\0')
			break ;
		if (str[i] == ',' && is_eol_next(str + i) < 0)
			++i;
		else
			return (aie_error("misplaced coma\n"));
		while (str[i] && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] != ' ')
				return (aie_error("character forbidden\n"));
			++i;
		}
	}
	return (1);
}

/*
** check la validite des couleur du floor et du ceil.
*/

int			check_color_data(char *str)
{
	size_t	i;
	size_t	count;
	size_t	rgb;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		rgb = 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			rgb = rgb * 10 + (str[i] - '0');
			++i;
		}
		if (rgb > 255)
			return (aie_error("wrong rgb color\n"));
		if (str[i] == ',')
			++i;
		while (str[i] && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] != ' ')
				return (aie_error("forbidden character\n"));
			++i;
		}
	}
	if (check_coma(str) < 0)
		return (-1);
	return (1);
}
