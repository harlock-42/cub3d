/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:14:15 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 13:39:19 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_env_tex_2(t_env *env)
{
	env->tex.bpp = 0;
	env->tex.line_length = 0;
	env->tex.endian = 0;
	env->tex.line_height = 0;
	env->tex.tex_x = 0;
	env->tex.tex_y = 0;
	env->tex.wall_x = 0.0;
	env->tex.step = 0.0;
}
