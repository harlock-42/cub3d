/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:43:03 by harlock           #+#    #+#             */
/*   Updated: 2020/08/29 21:19:11 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			is_arg_save(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-' && arg[2] == 's' && arg[3] == 'a' &&
		arg[4] == 'v' && arg[5] == 'e')
		return (1);
	else
		ft_printf("Error\nThird argument is not recognized\n");
	return (-1);
}

void		create_bmp_file(t_env *env)
{

	(void)env;
}
