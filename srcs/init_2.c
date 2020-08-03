/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 19:53:53 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/02 20:02:25 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void		init_check(t_env *env)
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

void			init_env_2(t_env *env)
{
	init_check(env);
}
