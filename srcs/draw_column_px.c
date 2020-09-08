/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:54:09 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:54:27 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		my_mlx_pixel_put(t_env *env, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = env->wall.addr + (y * env->vars.res_x + x);
	*(unsigned int *)dst = color;
}

void		draw_column_px(t_env *env, int x, int start, int end)
{
	return (print_texture(env, x, start, end));
}
