/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:44:07 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/03 19:22:38 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_path(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isascii((int)str[i]) < 0)
			return (aie_error("invalid character in path\n"));
		if ((str[i] >= 9 && str[i] <= 13))
			return (aie_error("white spaces are forbidden in path\n"));
		++i;
	}
	return (1);
}
