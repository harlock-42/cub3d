/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:11:42 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/27 14:23:28 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		wall_x(t_env *env, int tex_width)
{
	(void)env;
	(void)tex_width;
}

void		init_plane(t_env *env)
{
	env->ray.plane_x = 0.0;
	env->ray.plane_y = 0.66;
}

void		init_dir_player(t_env *env)
{
	env->ray.dir_x = (-1.0);
	env->ray.dir_y = 0.0;
}
