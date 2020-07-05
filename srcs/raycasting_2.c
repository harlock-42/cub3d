/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:11:42 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/04 18:55:42 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_plane(t_env *env)
{
	float	a;

	a = env->player.dir;
	if (a < M_PI / 4 || a >= (7 * M_PI) / 4)
	{
		env->ray.plane_x = 0.66;
		env->ray.plane_y = 0.0;
	}
	else if (a > M_PI / 4 && a <= (3 * M_PI) / 4)
	{
		env->ray.plane_x = 0.0;
		env->ray.plane_y = (-0.66);
	}
	else if (a > (3 * M_PI) / 4 && a < (5 * M_PI) / 4)
	{
		env->ray.plane_x = (-0.66);
		env->ray.plane_y = 0.0;
	}
	else
	{
		env->ray.plane_x = 0.0;
		env->ray.plane_y = 0.66;
	}
}
void		init_dir_player(t_env *env)
{
	float	a;

	a = env->player.dir;
	if (a < M_PI / 4 || a >= (7 * M_PI) / 4)
	{
		env->ray.dir_x = 0;
		env->ray.dir_y = 1;
	}
	else if (a > M_PI / 4 && a <= (3 * M_PI) / 4)
	{
		env->ray.dir_x = 1;
		env->ray.dir_y = 0;
	}
	else if (a > (3 * M_PI) / 4 && a < (5 * M_PI) / 4)
	{
		env->ray.dir_x = 0;
		env->ray.dir_y = (-1);
	}
	else
	{
		env->ray.dir_x = (-1);
		env->ray.dir_y = 0;
	}
}
