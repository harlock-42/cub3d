/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:30:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/22 21:11:37 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


static	void	calcul_draw(t_env *env, int i)
{
	(void)i;
	env->sprite.height_sprite =
	(int)fabs(env->vars.res_y / env->sprite.transform_y);
	env->sprite.draw_start_y = (env->sprite.height_sprite * (-1)) / 2 +
	env->vars.res_y / 2;
	if (env->sprite.draw_start_y < 0)
		env->sprite.draw_start_y = 0;
	env->sprite.draw_end_y = env->sprite.height_sprite / 2 +
	env->vars.res_y / 2;
	if (env->sprite.draw_end_y >= env->vars.res_y)
		env->sprite.draw_end_y = env->vars.res_y - 1;


//	erreur du tuto ?
	env->sprite.width_sprite =
	(int)fabs(env->vars.res_y / env->sprite.transform_y);

//	env->sprite.width_sprite =
//	(int)fabs(env->vars.res_x / env->sprite.transform_x);
	env->sprite.draw_start_x = (env->sprite.width_sprite * (-1)) / 2 +
	env->sprite.screen_x;
	if (env->sprite.draw_start_x < 0)
		env->sprite.draw_start_x = 0;
	env->sprite.draw_end_x = env->sprite.width_sprite / 2 + env->sprite.screen_x;
	if (env->sprite.draw_end_x >= env->vars.res_x)
		env->sprite.draw_end_x = env->vars.res_x - 1;
//	ft_printf("%d | %d\n", env->sprite.draw_start_x, env->sprite.draw_end_x);
}

static	void	calcul_screen(t_env *env, int i)
{
	env->sprite.X = env->sprite.x[env->sprite.order[i]] -
	env->player.pos_x;
	env->sprite.Y = env->sprite.y[env->sprite.order[i]] -
	env->player.pos_y;
	env->sprite.inv_det = 1 / (env->ray.plane_x * env->ray.dir_y -
	env->ray.dir_x * env->ray.plane_y);
	env->sprite.transform_x = env->sprite.inv_det *
	(env->ray.dir_y * env->sprite.X - env->ray.dir_x * env->sprite.Y);
	env->sprite.transform_y = env->sprite.inv_det *
	((env->ray.plane_y * (-1)) * env->sprite.X +
	env->ray.plane_x * env->sprite.Y);
	env->sprite.screen_x = (int)(env->vars.res_x / 2) *
	(1 + env->sprite.transform_x / env->sprite.transform_y);
	env->sprite.height_sprite =
	(int)fabs(env->vars.res_y / env->sprite.transform_y);
}

void		sprite(t_env *env)
{
	int		i;
	int		d;
	int		stripe;
	int		y;
	int		tex_x;
	int		tex_y;
	unsigned	int	color;
	float	nb;

	i = 0;
	nb = 0;
	tex_x = 0;
	tex_y = 0;
	color = 0;
	calcul_screen(env, i);
	calcul_draw(env, i);
	stripe = env->sprite.draw_start_x;
	while (stripe < env->sprite.draw_end_x)
	{
		tex_x = (int)(stripe - ((env->sprite.width_sprite * (-1)) / 2 +
		env->sprite.screen_x) * env->sprite.width / env->sprite.width_sprite);
		y = env->sprite.draw_start_y;
		if (env->sprite.transform_y > 0 && stripe > 0 && stripe < env->vars.res_x &&
		env->sprite.transform_y < env->sprite.z_buffer[stripe])
		{
			while (y < env->sprite.draw_end_y)
			{
				d = y - env->vars.res_y / 2 + env->sprite.height_sprite;
				tex_y = (d * env->sprite.height) / env->sprite.height_sprite;
				color = env->sprite.sprite[env->sprite.width * tex_y + tex_x];
				my_mlx_pixel_put(env, stripe, y, color);
				++y;
			}
		}
//		ft_printf("tex_x = %d\n", tex_x);
		++stripe;
	}
}



















