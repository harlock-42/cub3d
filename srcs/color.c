/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:16:55 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/08 21:03:57 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** Calcule les coordonnees de la texture a afficher.
** retourne la couleur du texel en question.
*/

static	int	texel_coordinate(t_env *env, int y, int x)
{
	float				wall_x;
	float				step;
	int					tex_x;
	int					tex_y;
	int					color;
	float				tex_pos;

	wall_x = 0.0;
	tex_x = 0;
	step = 0.0;
	tex_y = 0;
	tex_pos = 0.0;
	color = 0;
	(void)y;
	(void)x;

//	calcul de wall_x : indice de la position de la colonne dans la case la map.
	if (env->ray.side == 0)
		wall_x = env->player.pos_y + env->ray.size * env->ray.dir_y;
	else
		wall_x = env->player.pos_x + env->ray.size * env->ray.dir_x;
	wall_x = wall_x - floor(wall_x);

//	position du texel en x
	tex_x = env->tex.width * wall_x;
	if (env->ray.side == 0 && env->ray.dir_x > 0)
		tex_x = env->tex.width - tex_x - 1;
	if (env->ray.side == 1 && env->ray.dir_y < 0)
		tex_x = env->tex.width - tex_x - 1;


	step = 1.0 * env->tex.height / env->wall.line_height;
	tex_pos = (env->wall.draw_start - env->vars.res_y + env->wall.line_height) * step;
	while (y <= env->wall.draw_end)
	{
		tex_y = (int)tex_pos & (env->tex.height - 1);
		tex_pos = tex_pos + step;
		color = env->tex.addr[env->tex.height * tex_y + tex_x];
		my_mlx_pixel_put(env, x, y, color);
		++y;
	}

	env->wall.color = 0X00FFFFFF;
	return (y);
}

int			pixel_color(t_env *env, int y, int x)
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
			y = texel_coordinate(env, y, x);
	}
	return (y);
}

