/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:46:43 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 12:47:11 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			wall_x(t_env *env, int tex_width)
{
	(void)env;
	(void)tex_width;
}

static	void	init(t_env *env)
{
	env->ray.plane_x = 0.0;
	env->ray.plane_y = 0.0;
}

void			init_plane(t_env *env)
{
	float	dir;

	dir = env->player.dir;
	init(env);
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		env->ray.plane_x = 0.0;
		env->ray.plane_y = (0.66);
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		env->ray.plane_x = 0.66;
		env->ray.plane_y = 0.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		env->ray.plane_x = 0.0;
		env->ray.plane_y = (-0.66);
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		env->ray.plane_x = (-0.66);
		env->ray.plane_y = 0.0;
	}
}

void			init_dir_player(t_env *env)
{
	float	dir;

	dir = env->player.dir;
	env->ray.dir_x = 0.0;
	env->ray.dir_y = 0.0;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		env->ray.dir_x = (-1.0);
		env->ray.dir_y = 0.0;
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		env->ray.dir_x = 0.0;
		env->ray.dir_y = 1.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		env->ray.dir_x = 1.0;
		env->ray.dir_y = 0.0;
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		env->ray.dir_x = 0.0;
		env->ray.dir_y = (-1.0);
	}
}
