/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:57:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/04 15:09:29 by harlock          ###   ########.fr       */
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
	float	tex_pos;

	env->tex.step = 1.0 * env->tex.tex_height / env->wall.line_height;
	tex_pos = (env->wall.draw_start - env->vars.res_y / 2 +
	env->wall.line_height / 2) * env->tex.step;
	y = 0;
	x = abs(x - env->vars.res_x + 1);
	while (y < env->vars.res_y)
	{
		if (y < start)
			my_mlx_pixel_put(env, x, y, env->vars.ceil_color);
		else if (y >= start && y <= end)
		{
			env->tex.tex_y =
			(int)tex_pos & (env->tex.tex_height - 1);
			tex_pos += env->tex.step;
			pixel_color(env);
			my_mlx_pixel_put(env, x, y, env->wall.color);
		}
		else if (y > end)
			my_mlx_pixel_put(env, x, y, env->vars.floor_color);
		++y;
	}
}
