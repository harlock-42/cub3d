/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:59:40 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 12:00:46 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	free_data_file(t_env *env)
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

static	int		realloc_file(t_env *env, char *line)
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

/*
** Verifie que le fichier passer en paramettre possede l extention .cub
*/

static	int		file_is_cub(const char *str)
{
	size_t		i;

	i = ft_strlen(str);
	if (i <= 4)
		return (-1);
	if (str[i - 1] != 'b')
		return (-1);
	if (str[i - 2] != 'u')
		return (-1);
	if (str[i - 3] != 'c')
		return (-1);
	if (str[i - 4] != '.')
		return (-1);
	return (1);
}

int				get_file(t_env *env, const char *file_name)
{
	int		fd;
	int		ret;
	char	*line;

	env->vars.map = NULL;
	if (file_is_cub(file_name) < 0)
		return (aie_error("wrong file type"));
	if (!(fd = open(file_name, O_RDONLY)))
		return (aie_error("Impossible to read data file"));
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ret < 0)
			return (aie_error("reading file failed"));
		if (realloc_file(env, line) < 0)
			return (aie_error("failed realloc memory data file"));
		free(line);
	}
	if (env->vars.map == NULL)
		return (aie_error("data file empty\n"));
	free(line);
	return (1);
}
