/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:16:55 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/15 19:27:53 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Calcule les coordonnees de la texture a afficher.
** retourne la couleur du texel en question.
*/

void			pixel_color(t_env *env, int y, int x)
{
	(void)x;
	(void)y;
	if (env->ray.side == 0)
	{
		if (env->ray.step_x < 0)
			env->wall.color = 0X00FF0000;
		else
			env->wall.color = 0X0000FF00;
	}
	else
	{
		if (env->ray.step_y > 0)
			env->wall.color = 0X000000FF;
//		else
//		{
//			env->wall.color = 0X00000000;
//		}
	}
}
