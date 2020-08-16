/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 22:57:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/16 15:57:17 by tallaire         ###   ########.fr       */
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
	if (env->ray.side == 0 && env->ray.step_y < 0)
		return (print_texture(env, x, start, end));
	while (y < env->vars.res_y)
	{
		if (y < start)
			my_mlx_pixel_put(env, x, y, env->vars.ceil_color);
		else if (y >= start && y <= end)
		{
			pixel_color(env, y, x);
			my_mlx_pixel_put(env, x, y, env->wall.color);
		}
		else if (y > end)
			my_mlx_pixel_put(env, x, y, env->vars.floor_color);
		++y;
	}
}
