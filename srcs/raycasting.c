/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:39:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/14 14:25:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

/*
** Calcul la distance du rayon perpendiculaire au plan.
**
** line_height = taille de la colonne du mur en pixel a afficher.
*/

static	void	wall_size(t_env *env)
{
	if (env->ray.side == 0)
	{
		env->ray.perp_wall_dist = (env->ray.map_x - env->player.pos_x +
		(1 - env->ray.step_x) / 2) / env->ray.ray_dir_x;
	}
	else
	{
		env->ray.perp_wall_dist = (env->ray.map_y - env->player.pos_y +
		(1 - env->ray.step_y) / 2) / env->ray.ray_dir_y;
	}
	env->wall.line_height = floor(env->vars.res_y / env->ray.perp_wall_dist);
	env->wall.draw_start = (env->wall.line_height * (-1)) / 2 +
	env->vars.res_y / 2;
	if (env->wall.draw_start < 0)
		env->wall.draw_start = 0;
	env->wall.draw_end = env->wall.line_height / 2 + env->vars.res_y / 2;
	if (env->wall.draw_end >= env->vars.res_y)
		env->wall.draw_end = env->vars.res_y - 1;
}

static	void	dda(t_env *env)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->ray.side_dist_x < env->ray.side_dist_y)
		{
			env->ray.side_dist_x += env->ray.delta_dist_x;
			env->ray.map_x += env->ray.step_x;
			env->ray.side = 0;
		}
		else
		{
			env->ray.side_dist_y += env->ray.delta_dist_y;
			env->ray.map_y += env->ray.step_y;
			env->ray.side = 1;
		}
		if (env->map.map[(int)env->ray.map_y][(int)env->ray.map_x] > 0)
			hit = 1;
	}
}

static	void	init_side_dist_and_step(t_env *env, float pos_x, float pos_y)
{
	if (env->ray.ray_dir_x < 0)
	{
		env->ray.step_x = (-1);
		env->ray.side_dist_x = (pos_x - env->ray.map_x) *
		env->ray.delta_dist_x;
	}
	else
	{
		env->ray.step_x = 1;
		env->ray.side_dist_x = (env->ray.map_x + 1 - pos_x) *
		env->ray.delta_dist_x;
	}
	if (env->ray.ray_dir_y < 0)
	{
		env->ray.step_y = (-1);
		env->ray.side_dist_y = (pos_y - env->ray.map_y) *
		env->ray.delta_dist_y;
	}
	else
	{
		env->ray.step_y = 1;
		env->ray.side_dist_y = (env->ray.map_y + 1 - pos_y) *
		env->ray.delta_dist_y;
	}
}

/*
** camera_x = indice (-1; 1) du placement des la camera en x.
**
** h = resolution de l ecran en hauteur (height).
** w = resolution de l ecran en largeur (width).
**
** map_x = positionnement du player servant au calcul
** de la taille du rayon par les x.
** map_y = positionnement du player servant au calcul
** de la taille du rayon par les y.
**
** dir_x = vecteur de la direction du player en x (-1, 0 ou 1).
** dir_y = vecteur de la direction du player en y (-1, 0 ou 1).
**
** ray_dir_x = calcule la direction du rayon sur l ecran en x.
** ray_dir_y = calcule la direction du rayon sur l ecran en y.
**
** plane_x = vecteur du placement de la camera en x (-1; 1).
** plane_y = vecteur du placement de la camera en y (-1; 1).
**
** delta_dist_x = Si j avance de 1 en y, de combien j avance en x ?
** delta_dist_x = Si j avance de 1 en x, de combien j avance en y ?
*/
static	void	init_env_ray(t_env *env, float x, float w)
{
	env->ray.camera_x = (2 * x) / (float)w - 1;
	env->ray.ray_dir_x = env->ray.dir_x + env->ray.plane_x *
	env->ray.camera_x;
	env->ray.ray_dir_y = env->ray.dir_y + env->ray.plane_y *
	env->ray.camera_x;
	env->ray.map_x = (int)env->player.pos_x;
	env->ray.map_y = (int)env->player.pos_y;
	env->ray.delta_dist_x = fabs(1 / env->ray.ray_dir_x);
	env->ray.delta_dist_y = fabs(1 / env->ray.ray_dir_y);
}

int				raycast(t_env *env)
{
	int		x;
	int		w;

	x = 0;
	w = env->vars.res_x;
	while (x < w)
	{
		init_env_ray(env, x, w);
		init_side_dist_and_step(env, env->player.pos_x,
		env->player.pos_y);
		dda(env);
		wall_size(env);
		draw_column_px(env, x, env->wall.draw_start,
		env->wall.draw_end);
		++x;
	}
	return (1);
}
