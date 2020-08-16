/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_id_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:35:27 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/16 17:10:49 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	get_sprite_path(t_env *env, char *str)
{
	size_t		i;

	i = 0;
	if (env->check.s == 1)
		return (aie_error("several sprite path refered\n"));
	env->check.s = 1;
	while (*str != ' ' && *str)
		++str;
	while (*str == ' ' && *str)
		++str;
	if (check_path(str) <= 0)
		return (aie_error("invalid sprite path in data.cub\n"));
	if (!(env->vars.path_sprite = ft_strdup(str)))
		return (aie_error("path sprite, malloc failed\n"));
	return (1);
}


static	void	get_res(t_env *env, char *str)
{
	size_t	i;

	i = 0;
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
	if (env->vars.res_x > RES_MAX_X)
		env->vars.res_x = RES_MAX_X;
	if (env->vars.res_y > RES_MAX_Y)
		env->vars.res_y = RES_MAX_Y;
}

int	get_data_id(t_env *env, char *str)
{
	if (*str == 'R')
	{
		if (check_res(str, env) < 0)
			return (aie_error("incorrect resolution data in data.cub\n"));
		get_res(env, str);
		if (env->vars.res_x == 0 || env->vars.res_y == 0)
			return (aie_error("resolution null\n"));
	}
	if (*str == 'S')
		return (get_sprite_path(env, str));
	if (*str == 'F' || *str == 'C')
		return (get_color_ceil_and_floor(env, str));
	return (1);
}
