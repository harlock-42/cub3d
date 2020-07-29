/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:34:28 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/29 16:01:16 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_color_ceil_and_floor(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	(void)env;
	if (*str == 'F' || *str == 'C')
		++i;
	else
		return (aie_error("invalid ceil or floor data in data.cub\n"));
	while (str[i] && str[i] == ' ')
		++i;
	if (check_color_data(str + i) < 0)
		return (aie_error("invalid ceil or floor data in data.cub\n"));
	ft_printf("success\n");
	return (-1);
	return (1);
}

