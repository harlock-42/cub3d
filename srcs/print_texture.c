/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:36:49 by harlock           #+#    #+#             */
/*   Updated: 2020/08/12 19:48:30 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	float			step_y_calcul(t_env *env)
{
	float	step_y;
	int		diviseur;

	diviseur = env->vars.res_y - (env->wall.draw_start * 2);
	step_y = env->tex.height / diviseur;
	return (step_y);
}

static	int			tex_x_calcul(t_env *env)
{
	int		tex_x;
	float	wall_x;

	tex_x = 0;
	wall_x = 0;
	if (env->ray.side == 0)
		wall_x = env->player.pos_y + env->ray.perp_wall_dist * env->ray.ray_dir_y;
	else
		wall_x = env->player.pos_x + env->ray.perp_wall_dist * env->ray.ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * env->tex.width);
	if (env->ray.side == 0 && env->ray.dir_x > 0)
		tex_x = env->tex.width - tex_x - 1;
	if (env->ray.side == 1 && env->ray.dir_x < 0)
		tex_x = env->tex.width - tex_x - 1;
	return (tex_x);
}

void				print_texture(t_env *env, int x, int start, int end)
{
	int		y;
	int			tex_x;
	float			tex_y;
	unsigned	int	color;
	(void)x;
	float	step_y;

	y = 0;
	tex_x = tex_x_calcul(env);
	tex_y = 0.0;
	step_y = step_y_calcul(env);
	color = 0;
		while (y < start)
		{
			my_mlx_pixel_put(env, x, y, env->vars.ceil_color);
			++y;
		}
		while (y >= start && y <= end)
		{
			tex_y += step_y;
			color = env->tex.buffer[(int)floor(step_y)][tex_x];
			my_mlx_pixel_put(env, x, y, color);
			++y;
		}
		while (y > end && y < env->vars.res_y)
		{
			my_mlx_pixel_put(env, x, y, env->vars.floor_color);
			++y;
		}
}
