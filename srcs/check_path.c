/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 13:44:07 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/10 13:44:09 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	check_path_end(char *str)
{
	size_t	i;

	i = 0;
	if (*str == '\0')
		return (-1);
	while (str[i] != '.' && str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') &&
		(str[i] < 'A' || str[i] > 'Z') && str[i] != '_')
			return (-1);
		if (str[i] == '_')
			if (str[i + 1] == '_')
				return (
				aie_error("two succecive [_] in path\n"));
		++i;
	}
	if (*str == '\0')
		return (-1);
/*
** implementer le checking de l extention du fichier sprite.
*/
	return (1);
}

static	int	check_path_2(char *str)
{
	if (*str == '.')
	{
		if (*(str + 1) == '/')
		{
			if ((*(str + 2) >= 'a' && *(str + 2) <= 'z') ||
			(*(str + 2) >= 'A' && *(str + 2) <= 'Z'))
				return (check_path_end(str + 2));
		}
		else if ((*(str + 1) >= 'a' && *(str + 1) <= 'z') ||
		(*(str + 1) >= 'A' && *(str + 1) <= 'Z'))
			return (check_path_end(str + 1));
	}
	else if (*str == '/')
		if ((*(str + 1) >= 'a' && *(str + 1) <= 'z') ||
		(*(str + 1) >= 'A' && *(str + 1) <= 'Z'))
			return (check_path_end(str + 1));
	return (-1);
}

int		check_path(char *str)
{
	if (*str == '\0')
		return (-1);
	if (*str == '.')
	{
		return (check_path_2(str + 1));
	}
	else if (*str == '/')
	{
		if ((*(str + 1) >= 'a' && *(str + 1) <= 'z') ||
		(*(str + 1) >= 'A' && *(str + 1) <= 'Z'))
			return (check_path_end(str + 1));
	}
	else if ((*str >= 'a' && *str <= 'z') ||
	(*str >= 'A' && *str <= 'Z'))
		return (check_path_end(str));
	return (-1);
}
