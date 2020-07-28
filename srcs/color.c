/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:16:55 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/07 16:16:56 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		pixel_color(t_env *env)
{
	if (env->ray.side == 0)
	{
		if (env->ray.step_x < 0)
			env->wall.color = 0X00FF0000;
		else
			env->wall.color = 0X00FFFFFF;
	}
	else
	{
		if (env->ray.step_y > 0)
			env->wall.color = 0X0000FF00;
		else
			env->wall.color = 0X000000FF;
	}
}

