/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 09:54:40 by tallaire          #+#    #+#             */
/*   Updated: 2020/05/27 09:54:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	static	free_data_file(t_env *env)
{
	size_t	i;

	i = 0;
	while (env->vars.map && env->vars.map[i] != NULL)
	{
		free(env->vars.map[i]);
		++i;
	}
	free(env->vars.map);
}

static	int	realloc_file(t_env *env, char *line)
{
	size_t		nb_line;
	size_t		i;
	char		**new;

	nb_line = 0;
	i = 0;
	while (env->vars.map && env->vars.map[nb_line])
		++nb_line;
	if (!(new = (char **)malloc(sizeof(char *) * (nb_line + 2))))
		return (-1);
	while (i < nb_line)
	{
		new[i] = ft_strdup(env->vars.map[i]);
		++i;
	}
	new[i] = ft_strdup(line);
	new[i + 1] = NULL;
	free_data_file(env);
	env->vars.map = new;
	return (1);
}

int		get_file(t_env *env, const char *file_name)
{
	int	fd;
	int	ret;
	char	*line;

	env->vars.map = NULL;
	fd = open(file_name, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret < 0)
			return (-1);
		realloc_file(env, line);
		free(line);
	}
	if (env->vars.map == NULL)
		return (aie_error("data.cub file empty\n"));
	free(line);
	return (1);
}
