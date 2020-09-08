/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:08:33 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 12:15:48 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				init_vars(t_env *env)
{
	int		i;

	i = 0;
	env->vars.save = 0;
	env->vars.res_x = 0;
	env->vars.res_y = 0;
	env->sprite.num = 0;
	env->vars.path_tex = NULL;
	if (!(env->vars.path_tex = (char **)malloc(sizeof(char *) * 4)))
		return (aie_error("texture alloc memory failed"));
	while (i < 4)
	{
		env->vars.path_tex[i] = NULL;
		++i;
	}
	return (1);
}

static	int		init_env_tex(t_env *env)
{
	int		i;

	i = 0;
	env->tex.tex = NULL;
	env->tex.addr = NULL;
	env->tex.img = NULL;
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
	init_env_tex_2(env);
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

int				init_env(t_env *env)
{
	init_env_wall(env);
	init_env_key(env);
	env->player.dir = 0.0;
	env->player.pos_x = 0.0;
	env->player.pos_y = 0.0;
	env->sprite.distance = NULL;
	env->sprite.order = NULL;
	env->sprite.y = NULL;
	env->sprite.x = NULL;
	env->tex.tex = NULL;
	env->tex.img = NULL;
	env->vars.path_tex = NULL;
	env->vars.path_sprite = NULL;
	env->sprite.z_buffer = NULL;
	env->sprite.sprite = NULL;
	env->sprite.addr = NULL;
	env->map.map = NULL;
	if (init_env_tex(env) < 0)
		return (aie_error("texture alloc memory failed"));
	init_plane(env);
	init_check(env);
	return (0);
}
