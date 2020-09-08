/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:54:58 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:57:43 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	free_texture_sprite_2(t_env *env)
{
	if (env->tex.tex)
		free(env->tex.tex);
	if (env->tex.img)
		free(env->tex.img);
	if (env->vars.path_tex)
		free(env->vars.path_tex);
	if (env->sprite.z_buffer)
		free(env->sprite.z_buffer);
	if (env->sprite.sprite)
		free(env->sprite.sprite);
	if (env->tex.addr)
		free(env->tex.addr);
	if (env->vars.path_sprite)
		free(env->vars.path_sprite);
}

static	void	free_texture_sprite(t_env *env)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (env->tex.tex)
			free(env->tex.tex[i]);
		if (env->tex.img)
			free(env->tex.img[i]);
		if (env->vars.path_tex)
			free(env->vars.path_tex[i]);
		++i;
	}
	free_texture_sprite_2(env);
	if (env->sprite.order)
	{
		free(env->sprite.distance);
		free(env->sprite.order);
		free(env->sprite.y);
		free(env->sprite.x);
	}
}

int				exit_game(t_env *env)
{
	free_texture_sprite(env);
	free_map(env);
	return (0);
}
