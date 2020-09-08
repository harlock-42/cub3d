/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:13:02 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 16:53:46 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static		void	sprite_display_stripe(t_env *env, int tex_x, int stripe)
{
	int				d;
	int				tex_y;
	int				y;
	unsigned	int	color;

	d = 0;
	tex_y = 0;
	color = 0;
	y = env->sprite.draw_start_y;
	while (y < env->sprite.draw_end_y)
	{
		d = y * 256 - env->vars.res_y * 128
			+ env->sprite.height_sprite
			* 128;
		if (d < 0)
			d = 0;
		tex_y = ((d * env->sprite.height) /
			env->sprite.height_sprite) /
			256;
		color = env->sprite.sprite[env->sprite.width
			* tex_y + tex_x];
		my_mlx_pixel_put(env, stripe, y, color);
		++y;
	}
}

static		void	sprite_display(t_env *env)
{
	int				stripe;
	int				tex_x;

	stripe = env->sprite.draw_start_x;
	tex_x = 0;
	while (stripe < env->sprite.draw_end_x)
	{
		tex_x = (int)(256 * (stripe -
			(-env->sprite.width_sprite / 2 +
			env->sprite.screen_x)) * env->sprite.width
			/ env->sprite.width_sprite) / 256;
		if (env->sprite.transform_y > 0 && stripe >= 0 &&
			stripe < env->vars.res_x &&
			env->sprite.transform_y <
			env->sprite.z_buffer[stripe])
			sprite_display_stripe(env, tex_x, stripe);
		++stripe;
	}
}

static		void	sprite_size(t_env *env)
{
	env->sprite.height_sprite = abs((int)(env->vars.res_y /
		env->sprite.transform_y));
	env->sprite.draw_start_y = -env->sprite.height_sprite / 2 +
		env->vars.res_y / 2;
	if (env->sprite.draw_start_y < 0)
		env->sprite.draw_start_y = 0;
	env->sprite.draw_end_y = env->sprite.height_sprite / 2 +
		env->vars.res_y / 2;
	if (env->sprite.draw_end_y >= env->vars.res_y)
		env->sprite.draw_end_y = env->vars.res_y;
	env->sprite.width_sprite = abs((int)(env->vars.res_y /
		env->sprite.transform_y));
	env->sprite.draw_start_x = -env->sprite.width_sprite / 2 +
		env->sprite.screen_x;
	if (env->sprite.draw_start_x < 0)
		env->sprite.draw_start_x = 0;
	env->sprite.draw_end_x = env->sprite.width_sprite / 2 +
		env->sprite.screen_x;
	if (env->sprite.draw_end_x >= env->vars.res_x)
		env->sprite.draw_end_x = env->vars.res_x;
}

static		void	sprite_screen(t_env *env, int i)
{
	env->sprite.x_s = env->sprite.x[env->sprite.order[i]] -
		env->player.pos_x;
	env->sprite.y_s = env->sprite.y[env->sprite.order[i]] -
		env->player.pos_y;
	env->sprite.inv_det = 1.0 / (env->ray.plane_x * env->ray.dir_y -
		env->ray.dir_x * env->ray.plane_y);
	env->sprite.transform_x = -env->sprite.inv_det * (env->ray.dir_y *
		env->sprite.x_s - env->ray.dir_x * env->sprite.y_s);
	env->sprite.transform_y = env->sprite.inv_det * (-env->ray.plane_y *
		env->sprite.x_s + env->ray.plane_x * env->sprite.y_s);
	env->sprite.screen_x = (int)(env->vars.res_x / 2) * (1.0 +
		env->sprite.transform_x / env->sprite.transform_y);
}

void				sprite(t_env *env)
{
	int		i;

	i = 0;
	sprite_distance(env);
	sort_sprite(env);
	while (i < env->sprite.num)
	{
		sprite_screen(env, i);
		sprite_size(env);
		sprite_display(env);
		++i;
	}
}
