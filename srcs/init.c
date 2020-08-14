/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:56:50 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/14 16:32:50 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	init_env_other(t_env *env)
{
	env->vars.res_x = 0;
	env->vars.res_y = 0;
}

static	void	init_env_tex(t_env *env)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		env->tex.addr[i] = 0;
		++i;
	}
	env->tex.img = NULL;
	env->tex.bpp = 0;
	env->tex.line_length = 0;
	env->tex.endian = 0;
	env->tex.line_height = 0;
	env->tex.width = 0;
	env->tex.height = 0;
	env->tex.tex_x = 0;
	env->tex.tex_y = 0;
	env->tex.wall_x = 0.0;
	env->tex.step = 0.0;
}

static	void	init_env_key(t_env *env)
{
	env->key.forward = 0;
	env->key.back = 0;
	env->key.left = 0;
	env->key.right = 0;
	env->key.rot_left = 0;
	env->key.rot_right = 0;
	env->key.escape = 0;
}

static	void	init_env_wall(t_env *env)
{
	env->wall.img = NULL;
	env->wall.addr = 0;
	env->wall.bpp = 0;
	env->wall.line_length = 0;
	env->wall.endian = 0;
	env->wall.line_height = 0;
	env->wall.draw_start = 0;
	env->wall.draw_end = 0;
	env->wall.color = 0;
	env->wall.ceil_color = 0;
	env->wall.floor_color = 0;
}

void		init_env(t_env *env)
{
	init_env_wall(env);
	init_env_key(env);
	init_dir_player(env);
	init_env_tex(env);
	init_env_other(env);
	init_plane(env);
	init_check(env);
}
