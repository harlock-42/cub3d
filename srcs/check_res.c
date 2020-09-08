/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:53:04 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:53:11 by tallaire         ###   ########.fr       */
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
		return (-1);
	env->check.r = 1;
	while (str && str[i])
	{
		while (str && str[i] && (str[i] < '0' || str[i] > '9'))
		{
			if (str[i] != ' ')
				return (-1);
			++i;
		}
		if (str[i] >= '0' && str[i] <= '9')
			++count;
		while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
			++i;
	}
	if (count != 2)
		return (-1);
	return (1);
}
