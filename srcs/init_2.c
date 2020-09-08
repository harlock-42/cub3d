/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:31:53 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 13:23:54 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	init_env_sprite_2(t_env *env)
{
	env->sprite.img = NULL;
	env->sprite.X = 0;
	env->sprite.Y = 0;
	env->sprite.inv_det = 0;
	env->sprite.transform_x = 0;
	env->sprite.transform_y = 0;
	env->sprite.screen_x = 0;
	env->sprite.height_sprite = 0;
	env->sprite.width_sprite = 0;
	env->sprite.draw_start_x = 0;
	env->sprite.draw_start_y = 0;
	env->sprite.draw_end_x = 0;
	env->sprite.draw_end_y = 0;
	env->sprite.width = 0;
	env->sprite.height = 0;
	env->sprite.addr = NULL;
	env->sprite.bpp = 0;
	env->sprite.line_length = 0;
	env->sprite.endian = 0;
}

static	int		init_env_sprite(t_env *env)
{
	env->sprite.z_buffer = NULL;
	env->sprite.sprite = NULL;
	if (!(env->sprite.z_buffer = (float *)ft_calloc(env->vars.res_x,
	sizeof(float))))
		return (-1);
	init_env_sprite_2(env);
	if (env->sprite.num > 0)
	{
		if (!(env->sprite.distance = (float *)ft_calloc(env->sprite.num,
			sizeof(float))))
			return (-1);
	}
	return (1);
}

void			init_env_ray(t_env *env)
{
	env->ray.camera_x = 0.0;
	env->ray.ray_dir_x = 0.0;
	env->ray.ray_dir_y = 0.0;
	env->ray.delta_dist_x = 0.0;
	env->ray.delta_dist_y = 0.0;
	env->ray.step_x = 0.0;
	env->ray.step_y = 0.0;
	env->ray.side_dist_x = 0.0;
	env->ray.side_dist_y = 0.0;
	env->ray.perp_wall_dist = 0.0;
	env->ray.map_x = 0;
	env->ray.map_y = 0;
	env->ray.side = 0;
}

void			init_check(t_env *env)
{
	env->check.r = 0;
	env->check.no = 0;
	env->check.we = 0;
	env->check.ea = 0;
	env->check.so = 0;
	env->check.s = 0;
	env->check.f = 0;
	env->check.c = 0;
}

int				init_raycaster(t_env *env)
{
	init_plane(env);
	init_dir_player(env);
	init_env_ray(env);
	if (init_env_sprite(env) < 0)
		return (aie_error("sprite alloc memory failed"));
	return (1);
}
