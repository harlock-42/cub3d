/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_id_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:51:52 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/16 20:19:57 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** verifie que les chemins des textures ont ete referencee qu une seul fois.
*/

static	int	check_several_reference(t_env *env, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
	{
		if (env->check.no == 1)
			return (aie_error("several north texture path refered\n"));
		env->check.no = 1;
	}
	if (str[0] == 'S' && str[1] == 'O')
	{
		if (env->check.so == 1)
			return (aie_error("several south texture path refered\n"));
		env->check.so = 1;
	}
	if (str[0] == 'W' && str[1] == 'E')
	{
		if (env->check.we == 1)
			return (aie_error("several west texture path refered\n"));
		env->check.we = 1;
	}
	if (str[0] == 'E' && str[1] == 'A')
	{
		if (env->check.ea == 1)
			return (aie_error("several east texture path refered\n"));
		env->check.ea = 1;
	}
	return (1);
}

int	get_texture_path(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	if (check_several_reference(env, str) < 0)
		return (-1);
	while (str[i] && str[i] != ' ')
		++i;
	while (str[i] && str[i] == ' ')
		++i;
	if (str[i] == '\0')
		return (-1);
	if (check_path(str + i) < 0)
		return (-1);
	if (*str == 'N' && *(str + 1) == 'O')
		if (!(env->vars.path_tex[2] = strdup_path(str + i)))
			return (aie_error("invalid north texture path name\n"));
	if (*str == 'S' && *(str + 1) == 'O')
		if (!(env->vars.path_tex[0] = strdup_path(str + i)))
			return (aie_error("invalid south texture path name\n"));
	if (*str == 'E' && *(str + 1) == 'A')
		if (!(env->vars.path_tex[1] = strdup_path(str + i)))
			return (aie_error("invalid east texture path name\n"));
	if (*str == 'W' && *(str + 1) == 'E')
		if (!(env->vars.path_tex[3] = strdup_path(str + i)))
			return (aie_error("invalid west texture path name\n"));
	return (1);
}
