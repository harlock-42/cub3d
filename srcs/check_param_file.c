/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:58:52 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/03 19:22:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** verifie s il y a une map dans le fichier .cub
*/

static	int		is_a_map(char **map)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (map && map[j])
	{
		if (is_map_start(map[j]) > 0)
			return (1);
		++j;
	}
	return (-1);
}

/*
** Verifie que les data dans data.cub avant la map contiennent des majuscules
** valides en guise de titre, sont suivient par au moins un espace et
** sont situee en premier character de la ligne.
*/

int		check_param_file(t_env *env)
{
	size_t		i;
	size_t		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	if (is_a_map(env->vars.map) < 0)
		return (aie_error("map missing"));
	while (env->vars.map && env->vars.map[j])
	{
		i = 0;
		while (env->vars.map[j][0] == '\0')
			++j;
		while (env->vars.map[j][i] >= 'A' &&
		env->vars.map[j][i] <= 'Z' &&
		env->vars.map[j][i] != ' ')
			++i;
		if ((i == 0 || i > 2 || env->vars.map[j][i] != ' ')
		&& (ret = is_map_start(env->vars.map[j])) < 0)
			return (aie_error("invalid data in data.cub\n"));
		if (ret > 0)
			break ;
		++j;
	}
	return (1);
}
