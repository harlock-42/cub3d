/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:57:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/18 16:03:34 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = env->wall.addr + (y * env->vars.res_x + x);
	*(unsigned int *)dst = color;
}

void		draw_column_px(t_env *env, int x, int start, int end)
{
	int	y;

	y = 0;
	x = abs(x - env->vars.res_x + 1);
	return (print_texture(env, x, start, end));
}
