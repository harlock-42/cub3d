/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:58:33 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/06 12:19:38 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	wall_size(t_env *env)
{
	if (env->ray.side == 0)
	{
		env->ray.size = (env->ray.map_x - env->player.pos_x +
		(1 - env->ray.step_x) / 2) / env->ray.ray_dir_x;
	}
	else
	{
		env->ray.size = (env->ray.map_y - env->player.pos_y +
		(1 - env->ray.step_y) / 2) / env->ray.ray_dir_y;
	}
	env->wall.line_height = round(env->vars.res_y / env->ray.size);
	env->wall.draw_start = (env->wall.line_height * (-1)) / 2 +
	env->vars.res_y / 2;
	if (env->wall.draw_start < 0)
		env->wall.draw_start = 0;
	env->wall.draw_end = env->wall.line_height / 2 + env->vars.res_y / 2;
	if (env->wall.draw_end >= env->vars.res_y)
		env->wall.draw_end = env->vars.res_y - 1;
}

static	void	dda(t_env *env)
{
	int		hit;

	hit = 0;
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
			env->ray.map_y += env->ray.step_y;
			env->ray.side = 1;
		}
		if (env->map.map[(int)env->ray.map_y][(int)env->ray.map_x] > 0)
			hit = 1;
	}
}

static	void	init_side_dist_and_step(t_env *env, float pos_x, float pos_y)
{
	if (env->ray.ray_dir_x < 0)
	{
		env->ray.step_x = (-1);
		env->ray.side_dist_x = (pos_x - env->ray.map_x) *
		env->ray.delta_dist_x;
	}
	else
	{
		env->ray.step_x = 1;
		env->ray.side_dist_x = (env->ray.map_x + 1 - pos_x) *
		env->ray.delta_dist_x;
	}
	if (env->ray.ray_dir_y < 0)
	{
		env->ray.step_y = (-1);
		env->ray.side_dist_y = (pos_y - env->ray.map_y) *
		env->ray.delta_dist_y;
	}
	else
	{
		env->ray.step_y = 1;
		env->ray.side_dist_y = (env->ray.map_y + 1 - pos_y) *
		env->ray.delta_dist_y;
	}
}

static	void	init_env_ray(t_env *env, float x, float w)
{
	env->ray.map_x = (int)env->player.pos_x;
	env->ray.map_y = (int)env->player.pos_y;
	env->ray.camera_x = (2 * x) / (float)w - 1;
	env->ray.ray_dir_x = env->ray.dir_x + env->ray.plane_x *
	env->ray.camera_x;
	env->ray.ray_dir_y = env->ray.dir_y + env->ray.plane_y *
	env->ray.camera_x;
	env->ray.delta_dist_x = fabs(1 / env->ray.ray_dir_x);
	env->ray.delta_dist_y = fabs(1 / env->ray.ray_dir_y);
}

int				raycast(t_env *env)
{
	int		buffer[env->vars.res_y][env->vars.res_x];
	int		x;
	int		w;

	x = 0;
	w = env->vars.res_x;
	(void)buffer;
	while (x < w)
	{
		init_env_ray(env, x, w);
		init_side_dist_and_step(env, env->player.pos_x,
		env->player.pos_y);
		dda(env);
		wall_x(env);
		wall_size(env);
		draw_column_px(env, x, env->wall.draw_start,
		env->wall.draw_end);
		++x;
	}
	return (1);
}
