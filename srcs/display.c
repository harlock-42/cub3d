/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:29:37 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/31 14:51:24 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	new_image(t_env *env)
{
	env->wall.img = mlx_new_image(env->vars.mlx, env->vars.res_x,
	env->vars.res_y);
	env->wall.addr = mlx_get_data_addr(env->wall.img,
	&env->wall.bits_per_px, &env->wall.line_length, &env->wall.endian);
}
