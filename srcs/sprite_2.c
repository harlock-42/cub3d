/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:30:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/23 18:49:32 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		sprite(t_env *env)
{
	//spriteX et spriteY
	env->sprite.X = env->sprite.x[0] - env->player.pos_x;
	env->sprite.Y = env->sprite.y[0] - env->player.pos_y;

	// invDet
	env->sprite.inv_det = 1.0 / (env->ray.plane_x * env->ray.dir_y -
	env->ray.dir_x * env->sprite.Y);

	// transformX et transformY
	env->sprite.transform_x = env->sprite.inv_det * (env->ray.dir_y *
	env->sprite.X - env->ray.dir_x * env->sprite.Y);

	env->sprite.transform_y = env->sprite.inv_det * (-env->ray.plane_y *
	env->sprite.X - env->ray.plane_x * env->sprite.Y);

	// spriteScreenX
	env->sprite.screen_x = (int)(env->vars.res_x / 2) *
	(1 + env->sprite.transform_x / env->sprite.transform_y);
}

