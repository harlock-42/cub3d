/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:36:49 by harlock           #+#    #+#             */
/*   Updated: 2020/08/16 15:49:44 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int			print_tex_wall_west(t_env *env, int side, int y, int x)
{
	float			tex_y;
	unsigned	int	color;

	tex_y = 0.0;
	color = 0;
	(void)side;
	while (y >= env->wall.draw_start && y < env->wall.draw_end)
	{
		tex_y = ((y - env->vars.res_y / 2 + env->wall.line_height / 2) *
		env->tex.height_west) / env->wall.line_height;
		color = env->tex.tex_west[env->tex.width_west * (int)floor(tex_y) +
		env->tex.tex_x];
		my_mlx_pixel_put(env, x, y, color);
		++y;
	}
	return (y);
}

static	int			print_tex_wall_south(t_env *env, int side, int y, int x)
{
	float			tex_y;
	unsigned	int	color;

	tex_y = 0.0;
	color = 0;
	(void)side;
	while (y >= env->wall.draw_start && y < env->wall.draw_end)
	{
		tex_y = ((y - env->vars.res_y / 2 + env->wall.line_height / 2) *
		env->tex.height_south) / env->wall.line_height;
		color = env->tex.tex_south[env->tex.width_south * (int)floor(tex_y) +
		env->tex.tex_x];
		my_mlx_pixel_put(env, x, y, color);
		++y;
	}
	return (y);
}

static	int			print_tex_wall_east(t_env *env, int side, int y, int x)
{
	float			tex_y;
	unsigned	int	color;

	tex_y = 0.0;
	color = 0;
	(void)side;
	while (y >= env->wall.draw_start && y < env->wall.draw_end)
	{
		tex_y = ((y - env->vars.res_y / 2 + env->wall.line_height / 2) *
		env->tex.height_east) / env->wall.line_height;
		color = env->tex.tex_east[env->tex.width_east * (int)floor(tex_y) +
		env->tex.tex_x];
		my_mlx_pixel_put(env, x, y, color);
		++y;
	}
	return (y);
}

static	int			print_tex_wall_north(t_env *env, int side, int y, int x)
{
	float			tex_y;
	unsigned	int	color;

	tex_y = 0.0;
	color = 0;
	(void)side;
	while (y >= env->wall.draw_start && y < env->wall.draw_end)
	{
		tex_y = ((y - env->vars.res_y / 2 + env->wall.line_height / 2) *
		env->tex.height_north) / env->wall.line_height;
		color = env->tex.tex_north[env->tex.width_north * (int)floor(tex_y) +
		env->tex.tex_x];
		my_mlx_pixel_put(env, x, y, color);
		++y;
	}
	return (y);
}

static	int			wich_plan(t_env *env)
{
	int		side;

	side = 0;
	if (env->ray.side == 0)
	{
		if (env->ray.step_x < 0)
			side = 0;
		else
			side = 1;
	}
	else
	{
		if (env->ray.step_y > 0)
			side = 3;
		else
			side = 2;
	}
	return (side);
}

static	int			tex_x_calcul(t_env *env)
{
	int		tex_x;
	int		side;
	float	wall_x;

	tex_x = 0;
	wall_x = 0;
	side = wich_plan(env);
	if (env->ray.side == 0)
		wall_x = env->player.pos_y + env->ray.perp_wall_dist * env->ray.ray_dir_y;
	else
		wall_x = env->player.pos_x + env->ray.perp_wall_dist * env->ray.ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * (float)env->tex.width[side]);
	if (env->ray.side == 0 && env->ray.dir_x > 0)
		tex_x = env->tex.width[side] - tex_x - 1;
	if (env->ray.side == 1 && env->ray.dir_x < 0)
		tex_x = env->tex.width[side] - tex_x - 1;
	return (tex_x);
}

void				print_texture(t_env *env, int x, int start, int end)
{
	int				y;
	int				tex_y;
	int				side;
	unsigned	int	color;

	y = 0;
	env->tex.tex_x = tex_x_calcul(env);
	tex_y = 0;
	color = 0;
	side = wich_plan(env);
	while (y < start)
	{
		my_mlx_pixel_put(env, x, y, env->vars.ceil_color);
		++y;
	}
	if (side == 0)
		y = print_tex_wall_south(env, side, y, x);
	else if (side == 1)
		y = print_tex_wall_east(env, side, y, x);
	else if (side == 2)
		y = print_tex_wall_north(env, side, y, x);
	else if (side == 3)
		y = print_tex_wall_west(env, side, y, x);
	while (y >= end && y < env->vars.res_y)
	{
		my_mlx_pixel_put(env, x, y, env->vars.floor_color);
		++y;
	}
}
