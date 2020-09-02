/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 14:50:58 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/02 18:46:07 by tallaire         ###   ########.fr       */
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
			return (-1);
		while (str[i] && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] != ' ')
				return (-1);
			++i;
		}
	}
	return (1);
}

/*
** check si la couleur rgb contient un int avec pour valeur entre 0 et 255.
*/

static		int	check_rgb_size(char *str, size_t *i)
{
	size_t		rgb;

	rgb = 0;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		rgb = rgb * 10 + (str[*i] - '0');
		if (rgb > 255)
			return (-1);
		++*i;
	}
	return (1);
}

/*
** check le nombre d arguments pour les couleurs rgb.
** il ne doit y en avoir seulement 3.
*/

static	int	check_arg_number(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			++count;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			++i;
		++i;
	}
	if (count < 3)
		return (-1);
	if (count > 3)
		return (-1);
	return (1);
}

/*
** check la validite des couleur du floor et du ceil.
*/

int			check_color_data(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (check_arg_number(str) < 0)
		return (-1);
	while (str && str[i])
	{
		if (check_rgb_size(str, &i) < 0)
			return (-1);
		if (str[i] == ',')
			++i;
		while (str[i] && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] != ' ')
				return (-1);
			++i;
		}
	}
	if (check_coma(str) < 0)
		return (-1);
	return (1);
}
