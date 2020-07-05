/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:58:33 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/04 18:55:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ray_dist(t_env *env)
{
	float	dist_ray;

	if (env->ray.side == 0)
	{
		dist_ray = (env->ray.map_x - env->player.pos_x +
		(1 - env->ray.step_x) / 2) / env->ray.ray_dir_x;
	}
	else
	{
		dist_ray = (env->ray.map_y - env->player.pos_y +
		(1 - env->ray.step_y) / 2) / env->ray.ray_dir_y;
	}
	printf("%f\n", dist_ray);
}

static	void	dda(t_env *env)
{
	int		hit;

	hit = 0;
	env->ray.map_x = env->player.pos_x;
	env->ray.map_y = env->player.pos_y;
	printf("side_dist_x = %f | side_dist_y = %f\n", env->ray.side_dist_x, env->ray.side_dist_y);
	while (hit == 0)
	{
		if (env->ray.side_dist_x < env->ray.side_dist_y)
		{
			env->ray.side_dist_x += env->ray.delta_dist_x;
			env->ray.map_x += env->ray.step_x;
			env->ray.side = 0;
		}
		else
		{
			env->ray.side_dist_y += env->ray.delta_dist_y;
			env->ray.map_x += env->ray.step_y;
			env->ray.side = 1;
		}
//		printf("x = %f | y = %f\n", env->ray.map_x, env->ray.map_x);
		if (env->map.map[(int)env->ray.map_y][(int)env->ray.map_x] > 0)
			hit = 1;
	}
}

static	void	init_side_dist_and_step(t_env *env, float pos_x, float pos_y)
{
	printf("ray_dir_x = %f | ray_dir_y = %f\n", env->ray.ray_dir_x, env->ray.ray_dir_y);
	if (env->ray.ray_dir_x < 0)
	{
		env->ray.step_x = (-1);
		env->ray.side_dist_x = (pos_x - env->ray.map_x) * env->ray.delta_dist_x;
	}
	else
	{
		env->ray.step_x = 1;
		env->ray.side_dist_x = ((pos_x + 1) - env->ray.map_x) * env->ray.delta_dist_x;
	}
	if (env->ray.ray_dir_y < 0)
	{
		env->ray.step_y = (-1);
		env->ray.side_dist_y = (pos_y - env->ray.map_y) * env->ray.delta_dist_y;
	}
	else
	{
		env->ray.step_y = 1;
		env->ray.side_dist_y = ((pos_y + 1) - env->ray.map_y) * env->ray.delta_dist_y;
	}
}

static	void	init_env_ray(t_env *env, float x, float w)
{
	env->ray.camera_x = (2 * x) / w - 1;
	env->ray.ray_dir_x = env->ray.dir_x + env->ray.plane_x * env->ray.camera_x;
	env->ray.ray_dir_y = env->ray.dir_y + env->ray.plane_y * env->ray.camera_x;
	env->ray.delta_dist_x = fabs(1 / env->ray.ray_dir_x);
	env->ray.delta_dist_y = fabs(1 / env->ray.ray_dir_y);
}

void		dist_ray(t_env *env)
{
	float	x;
	float	w;

	x = 0.0;
	w = (float)env->vars.res_x;
	init_dir_player(env);
	while (x <= w)
	{
		init_env_ray(env, x, w);
		init_plane(env);
		init_side_dist_and_step(env, env->player.pos_x, env->player.pos_y);
		dda(env);
		ray_dist(env);
		++x;
	}
}
