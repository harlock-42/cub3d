/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 14:09:29 by harlock           #+#    #+#             */
/*   Updated: 2020/08/03 14:36:26 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** verifie la validite de la resoution dans le fichier data.cub
*/

int			check_res(char *str, t_env *env)
{
	size_t		i;
	int			count;

	i = 1;
	count = 0;
	if (env->check.r == 1)
		return (aie_error("several data resoution are refered\n"));
	env->check.r = 1;
	while (str && str[i])
	{
		while (str && str[i] && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] != ' ')
				return (aie_error("forbidden character\n"));
			++i;
		}
		if (str[i] >= '0' && str[i] <= '9')
			++count;
		while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
			++i;
	}
	if (count != 2)
		return (aie_error("wrong number of arguments\n"));
	return (1);
}
