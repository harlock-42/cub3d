/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_id_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:35:27 by tallaire          #+#    #+#             */
/*   Updated: 2020/05/28 16:35:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	static	get_res(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	env->vars.res_x = 0;
	env->vars.res_y = 0;
	while (str && str[i] && str[i] != ' ')
		++i;
	while (str && str[i] && str[i] == ' ')
		++i;
	while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		env->vars.res_x = env->vars.res_x * 10;
		env->vars.res_x = env->vars.res_x + (str[i] - '0');
		++i;
	}
	while (str && str[i] && str[i] == ' ')
		++i;
	while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		env->vars.res_y = env->vars.res_y * 10;
		env->vars.res_y = env->vars.res_y + (str[i] - '0');
		++i;
	}
	return (1);
}

int	get_data_id(t_env *env, char *str)
{
	int	ret;

	ret = 0;
	if (*str == 'R')
		ret = get_res(env, str);
	if (env->vars.res_x == 0 || env->vars.res_y == 0)
		return (-1);
	if (env->vars.res_x > 1920)
		env->vars.res_x = 1920;
	if (env->vars.res_y > 1080)
		env->vars.res_y = 1080;
	return (ret);
}
