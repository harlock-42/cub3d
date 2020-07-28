/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:34:28 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/10 17:34:31 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	check_color_data(char *str)
{
	size_t	i;
	size_t	k;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		k = 0;
		while (str[i + k] && (str[i + k] >= '0' && str[i + k] <= '9'))
			++k;
		if (k >= 1 && k <= 3)
			i = i + k;
		else
			return (-1);
		if (str[i] != ',')
			return (-1);
		else
			++i;
		while (str[i] == ' ')
			++i;
		++count;
		if ((str[i] != '\0' && (str[i] < '0' || str[i] > '9')) ||
		count > 3)
			return (-1);
	}
	ft_printf("test\n");
	return (1);
}

int		get_color_ceil_and_floor(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	(void)env;
	while (str[i] && str[i] != ' ')
		++i;
	while (str[i] && str[i] == ' ')
		++i;
	if (str[i] == '\0')
		return (-1);
	if (check_color_data(str + i) < 0)
		return (
		aie_error("invalid ceil and floor color data in data.cub\n"));
	return (1);
}

