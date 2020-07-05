/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_id_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:51:52 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/04 17:55:38 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture_path(t_env *env, char *str)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	(void)env;
	while (str && str[i] && str[i] == ' ')
	{
		if (str[i] != '.' && (str[i] < 'a' || str[i] > 'z'))
			return (-1);
		++i;
	}
	return (1);
}
