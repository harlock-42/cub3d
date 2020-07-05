/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:55:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/06/26 14:55:13 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		free_map(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->map.map && env->map.map[i] != NULL)
	{
		free(env->map.map[i]);
		env->map.map[i] = NULL;
		++i;
	}
	env->map.map = NULL;
}
