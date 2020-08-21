/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:15:13 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/21 16:53:51 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		init_env_sprite(t_env *env)
{
	if (!(env->sprite.z_buffer = (int *)ft_calloc(env->vars.res_x,
	sizeof(int))))
		return (-1);
	if (!(env->sprite.order = (int *)ft_calloc(env->sprite.num, sizeof(int))))
		return (-1);
	if (!(env->sprite.distance = (int *)ft_calloc(env->sprite.num, sizeof(int))))
		return (-1);
	if (!(env->sprite.first = (int *)ft_calloc(env->sprite.num, sizeof(int))))
		return (-1);
	if (!(env->sprite.second = (int *)ft_calloc(env->sprite.num, sizeof(int))))
		return (-1);
	env->sprite.img = NULL;
	env->sprite.X = 0;
	env->sprite.Y = 0;
	env->sprite.inv_det = 0;
	env->sprite.transform_x = 0;
	env->sprite.transform_y = 0;
	env->sprite.screen_x = 0;
	env->sprite.height_sprite = 0;
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

static	int		alloc_buffer_texture(t_env *env)
{
	size_t	y;

	y = 0;
	if (!(env->tex.buffer = (unsigned int **)malloc(sizeof(unsigned int *)
	* env->vars.res_y)))
		return (aie_error("alloc memory for buffer texture failed\n"));
	while (y < (size_t)env->vars.res_y)
	{
		if (!(env->tex.buffer[y] = malloc(sizeof(unsigned int)
		* env->vars.res_x)))
			return (aie_error("alloc memory for buffer texture failed\n"));
		++y;
	}
	env->tex.buffer[y] = NULL;
	return (1);
}

int				init_raycaster(t_env *env)
{
	if (alloc_buffer_texture(env) < 0)
		return (-1);
	init_plane(env);
	init_dir_player(env);
	init_env_ray(env);
	if (init_env_sprite(env) < 0)
		return (-1);
	return (1);
}
