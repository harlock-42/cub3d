/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:56:50 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/02 17:47:29 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_vars(t_env *env)
{
	int		i;

	i = 0;
	env->vars.save = 0;
	env->vars.res_x = 0;
	env->vars.res_y = 0;
	env->sprite.num = 0;
	if (!(env->vars.path_tex = (char **)malloc(sizeof(char *) * 4)))
		return (aie_error("texture alloc memory failed"));
	while (i < 4)
	{
		env->vars.path_tex[i] = NULL;
		++i;
	}
	return (1);
}

static	int	init_env_tex(t_env *env)
{
	int		i;

	i = 0;
	if (!(env->tex.tex = (unsigned int **)malloc(sizeof(unsigned int *) * 4)))
		return (aie_error("texture alloc memory failed"));
	if (!(env->tex.addr = (unsigned int **)malloc(sizeof(unsigned int *) * 4)))
		return (aie_error("texture alloc memory failed"));
	if (!(env->tex.img = (void **)malloc(sizeof(void *) * 4)))
		return (aie_error("texture alloc memory failed"));
	while (i < 4)
	{
		env->tex.width[i] = 0;
		env->tex.height[i] = 0;
		env->tex.tex[i] = NULL;
		env->tex.addr[i] = NULL;
		++i;
	}
	env->tex.bpp = 0;
	env->tex.line_length = 0;
	env->tex.endian = 0;
	env->tex.line_height = 0;
	env->tex.tex_x = 0;
	env->tex.tex_y = 0;
	env->tex.wall_x = 0.0;
	env->tex.step = 0.0;
	return (1);
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

int		init_env(t_env *env)
{
	init_env_wall(env);
	init_env_key(env);
	init_dir_player(env);
	if (init_env_tex(env) < 0)
		return (aie_error("texture alloc memory failed"));
	init_plane(env);
	init_check(env);
	return (1);
}
