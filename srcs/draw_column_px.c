/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:57:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/05 22:57:46 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->wall.addr +
	(y * env->wall.line_length + x * (env->wall.bits_per_px / 8));
	*(unsigned int *)dst = color;
}

void		draw_column_px(t_env *env, int x, int start, int end)
{
	int	y;

	y = 0;
	x = abs(x - env->vars.res_x + 1);
	while (y < env->vars.res_y)
	{
		if (y >= start && y <= end)
			my_mlx_pixel_put(env, x, y, env->wall.color);
		++y;
	}
}
