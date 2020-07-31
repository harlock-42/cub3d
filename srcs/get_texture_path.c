/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_id_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:51:52 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/31 17:20:38 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture_path(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		++i;
	while (str[i] && str[i] == ' ')
		++i;
	if (str[i] == '\0')
		return (-1);
	if (check_path(str + i) < 0)
		return (-1);
	if (*str == 'N' && *(str + 1) == 'O')
		if (!(env->vars.path_north = strdup_path(str + i)))
			return (aie_error("invalid north texture path name\n"));
	if (*str == 'S' && *(str + 1) == 'O')
		if (!(env->vars.path_south = strdup_path(str + i)))
			return (aie_error("invalid south texture path name\n"));
	if (*str == 'E' && *(str + 1) == 'A')
		if (!(env->vars.path_east = strdup_path(str + i)))
			return (aie_error("invalid east texture path name\n"));
	if (*str == 'W' && *(str + 1) == 'E')
		if (!(env->vars.path_west = strdup_path(str + i)))
			return (aie_error("invalid west texture path name\n"));
	return (1);
}
