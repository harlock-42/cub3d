/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:12:18 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/04 17:58:25 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_map_start(char *map)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return (-1);
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '1')
			return (-1);
		++i;
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == '1')
			return (1);
		++i;
	}
	return (-1);
}

int	static	get_param_id(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0' || is_map_start(str) > 0)
		return (1);
	while (str && str[i] && str[i] == ' ')
		++i;
	if (str[i] < 'A' || str[i] > 'Z')
		return (-1);
	while (str && str[i] && (str[i] >= 'A' && str[i] <= 'Z'))
		++i;
	if (str[i] != ' ')
		return (-1);
	if (i == 1)
		return (get_data_id(env, str + i - 1));
	if (i == 2)
		return (get_texture_path(env, str + i - 1));
	return (-1);
}

void		free_file(void **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		++i;
	}
	free(map);
	map = NULL;
}

int	static	parsing_param(t_env *env)
{
	size_t	i;

	i = 0;
	if (check_param_file(env) < 0)
		return (-1);

	while (env->vars.map[i])
	{
		if (get_param_id(env, env->vars.map[i]) < 0)
			return (-1);
		if (is_map_start(env->vars.map[i]) > 0)
		{
			if (get_pos_player(env->vars.map + i, env) < 0)
				return (-1);
			break ;
		}
		++i;
	}
	return (1);
}

int		parsing_file(t_env *env)
{
	if (parsing_param(env) < 0)
		return (-1);
	free_file((void **)env->vars.map);
	return (1);
}