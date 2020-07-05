/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:58:52 by tallaire          #+#    #+#             */
/*   Updated: 2020/05/27 19:58:53 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_param_file(t_env *env)
{
	size_t		i;
	size_t		j;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (env->vars.map && env->vars.map[j])
	{
		i = 0;
		if (env->vars.map[j][0] == '\0')
			++j;
		while (env->vars.map[j][i] != '\0'
		&& (env->vars.map[j][i] >= 'A' && env->vars.map[j][i] <= 'Z'))
			++i;
		if ((i > 2 || env->vars.map[j][i] != ' ')
		&& (ret = is_map_start(env->vars.map[j])) < 0)
			return (-1);
		if (ret > 0)
			break ;
		++j;
	}
	return (1);
}
