/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:53:32 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:53:57 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		new_image(t_env *env)
{
	if (!(env->wall.img = mlx_new_image(env->vars.mlx, env->vars.res_x,
	env->vars.res_y)))
	{
		ft_printf("Error\nGenerating new image failed\n");
		exit_game(env);
		exit(1);
	}
	env->wall.addr = (unsigned int *)mlx_get_data_addr(env->wall.img,
	&env->wall.bpp, &env->wall.line_length, &env->wall.endian);
}
