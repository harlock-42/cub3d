/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:30:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/29 21:53:29 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static		void	sprite_display(t_env *env, int y)
{
		int		stripe;
		int		tex_x;
		int		tex_y;
		int		d;
		unsigned	int	color;

		stripe = env->sprite.draw_start_x;
		tex_x = 0;
		tex_y = 0;
		d = 0;
		while (stripe < env->sprite.draw_end_x)
		{
			//	texX
			tex_x = (int)(256 * (stripe - (-env->sprite.width_sprite / 2 + env->sprite.screen_x)) * env->sprite.width / env->sprite.width_sprite) / 256;

			//	conditions d'affichage du sprite
			if (env->sprite.transform_y > 0 && stripe >= 0 && stripe < env->vars.res_x && env->sprite.transform_y < env->sprite.z_buffer[stripe])
			{
				y = env->sprite.draw_start_y;
				while (y < env->sprite.draw_end_y)
				{
					//	d
					d = y * 256 - env->vars.res_y * 128 + env->sprite.height_sprite * 128;

					//	texY
					tex_y = ((d * env->sprite.height) / env->sprite.height_sprite) / 256;

					//	color
					color = env->sprite.sprite[env->sprite.width * tex_y + tex_x];

					my_mlx_pixel_put(env, stripe, y, color);
					++y;
				}
			}
			++stripe;
		}


}

static		void	sprite_size(t_env *env)
{
		env->sprite.height_sprite = abs((int)(env->vars.res_y /
			env->sprite.transform_y));
		env->sprite.draw_start_y = -env->sprite.height_sprite / 2 +
			env->vars.res_y / 2 ;
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
		env->sprite.X = env->sprite.x[env->sprite.order[i]] -
			env->player.pos_x;
		env->sprite.Y = env->sprite.y[env->sprite.order[i]] -
			env->player.pos_y;
		env->sprite.inv_det = 1.0 / (env->ray.plane_x * env->ray.dir_y -
			env->ray.dir_x * env->ray.plane_y);
		env->sprite.transform_x = -env->sprite.inv_det * (env->ray.dir_y *
			env->sprite.X - env->ray.dir_x * env->sprite.Y);
		env->sprite.transform_y = env->sprite.inv_det * (-env->ray.plane_y *
			env->sprite.X + env->ray.plane_x * env->sprite.Y);
		env->sprite.screen_x = (int)(env->vars.res_x / 2) * (1.0 +
			env->sprite.transform_x / env->sprite.transform_y);
}



void		sprite(t_env *env)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	sprite_distance(env);
	sort_sprite(env);
	while (i < env->sprite.num)
	{
		sprite_screen(env, i);
		sprite_size(env);

		//	loop d'affichage des sprites //
		sprite_display(env, y);
		++i;
	}
}









