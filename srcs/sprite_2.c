/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:30:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/21 16:53:33 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		sprite(t_env *env)
{
	int		i;
	float	nb;

	i = 0;
	nb = 0;
	env->sprite.X = env->sprite.x[env->sprite.order[i]] -
	env->player.pos_x;
	env->sprite.Y = env->sprite.y[env->sprite.order[i]] -
	env->player.pos_y;
	env->sprite.inv_det = 1 / (env->ray.plane_x * env->ray.dir_y -
	env->ray.dir_x * env->ray.plane_y);
}
