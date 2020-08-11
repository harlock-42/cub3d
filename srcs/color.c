/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:16:55 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/09 19:22:30 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	size_t	get_x_tex(t_env *env)
{
	float		wall_x;
	int			tex_x;

	wall_x = 0.0;
	tex_x = 0;
	if (env->ray.side == 0)
		wall_x = env->player.pos_y + env->ray.perp_wall_dist * env->ray.ray_dir_y;
	else
		wall_x = env->player.pos_x + env->ray.perp_wall_dist * env->ray.ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)floor(wall_x * env->tex.width);
	if (env->ray.side == 0 && env->ray.ray_dir_x > 0)
		tex_x = env->tex.width - tex_x - 1;
	if (env->ray.side == 1 && env->ray.ray_dir_y < 0)
		tex_x = env->tex.width - tex_x - 1;
	return (tex_x);
}

void			texture_column(t_env *env, int x)
{
	int				tex_x;
	int				tex_y;
	int				y;
	unsigned	int	color;
	float			step;
	float			tex_pos;

	y = env->wall.draw_start;;
	tex_x = get_x_tex(env);
	step = 1.0 * env->tex.height / env->wall.line_height;
	tex_pos =
	(env->wall.draw_start - env->vars.res_y / 2 + env->wall.line_height / 2) * step;
	while (y < env->wall.draw_end)
	{
		tex_y = (int)floor(tex_pos) & (env->tex.height - 1);
		tex_pos += step;
		color = env->tex.addr[env->tex.height * tex_y + tex_x];
		env->tex.buffer[y][x] = color;
		++y;
	}
}

/*
** Calcule les coordonnees de la texture a afficher.
** retourne la couleur du texel en question.
*/

void			pixel_color(t_env *env, int y, int x)
{
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
		else
			env->wall.color = env->tex.buffer[y][x];
	}
}
