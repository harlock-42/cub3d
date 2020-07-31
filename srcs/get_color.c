/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:34:28 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/31 16:21:10 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** parse le fichier pour stocker une couleur rgb dans un int.
*/

static	int		stock_color(char *str, size_t *i)
{
	int		color;

	color = 0;
	while (str && str[*i] && (str[*i] < '0' || str[*i] > '9'))
		++*i;
	while (str && str[*i] && (str[*i] >= '0' && str[*i] <= '9'))
	{
		color = color * 10 + (str[*i] - '0');
		++*i;
	}
	return (color);
}

/*
** stock la couleur reg du floor dans un int.
*/

static	int		get_color_data(char *str)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 0;
	r = 0;
	g = 0;
	b = 0;
	r = stock_color(str, &i);
	g = stock_color(str, &i);
	b = stock_color(str, &i);
	return (256 * 256 * r + 256 * g + b);
}

int				get_color_ceil_and_floor(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	if (*str == 'F' || *str == 'C')
		++i;
	else
		return (aie_error("invalid ceil or floor data in data.cub\n"));
	while (str[i] && str[i] == ' ')
		++i;
	if (check_color_data(str + i) < 0)
		return (aie_error("invalid ceil or floor data in data.cub\n"));
	if (*str == 'F')
		env->vars.floor_color = get_color_data(str + i);
	else if (*str == 'C')
		env->vars.ceil_color = get_color_data(str + i);
	return (1);
}

