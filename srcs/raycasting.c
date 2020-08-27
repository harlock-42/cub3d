/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:39:44 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/27 17:33:32 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

int				raycast(t_env *env)
{
	int		x;
	int		hit;

	x = 0;
	hit = 0;

	while (x < env->vars.res_x)
	{
	//	rayDirX | rayDirY | cameraX
		env->ray.camera_x = 2.0 * (float)(env->vars.res_x - 1 - x) / (float)env->vars.res_x - 1;
		env->ray.ray_dir_x = env->ray.dir_x + env->ray.plane_x * env->ray.camera_x;
		env->ray.ray_dir_y = env->ray.dir_y + env->ray.plane_y * env->ray.camera_x;

	//	mapX | mapY
		env->ray.map_x = (int)env->player.pos_x;
		env->ray.map_y = (int)env->player.pos_y;

	//	deltaDistX | deltaDistY
		env->ray.delta_dist_x = fabs(1 / env->ray.ray_dir_x);
		env->ray.delta_dist_y = fabs(1 / env->ray.ray_dir_y);

	//	stepX | stepY
	//	sideDistX | sideDistY
		if (env->ray.ray_dir_x < 0)
		{
			env->ray.step_x = (-1);
			env->ray.side_dist_x = (env->player.pos_x - env->ray.map_x) * env->ray.delta_dist_x;
		}
		else
		{
			env->ray.step_x = 1;
			env->ray.side_dist_x = (env->ray.map_x + 1.0 - env->player.pos_x) * env->ray.delta_dist_x;
		}
		if (env->ray.ray_dir_y < 0)
		{
			env->ray.step_y = (-1);
			env->ray.side_dist_y = (env->player.pos_y - env->ray.map_y) * env->ray.delta_dist_y;
		}
		else
		{
			env->ray.step_y = 1;
			env->ray.side_dist_y = (env->ray.map_y + 1.0 - env->player.pos_y) * env->ray.delta_dist_y;
		}
		hit = 0;
		//	DDA
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
			if (env->map.map[(int)(env->ray.map_y)][(int)(env->ray.map_x)] > 0)
				hit = 1;
		}

		//perpWallDist
		if (env->ray.side == 0)
			env->ray.perp_wall_dist = (env->ray.map_x - env->player.pos_x + (1.0 - (int)env->ray.step_x) / 2.0) / env->ray.ray_dir_x;
		else
			env->ray.perp_wall_dist = (env->ray.map_y - env->player.pos_y + (1 - (int)env->ray.step_y) / 2) / env->ray.ray_dir_y;

		//	lineHeight
		env->wall.line_height = (int)(env->vars.res_y / env->ray.perp_wall_dist);
		//	drawStart | drawEnd
		env->wall.draw_start = -env->wall.line_height / 2 + env->vars.res_y / 2;
		if (env->wall.draw_start < 0)
			env->wall.draw_start = 0;
		env->wall.draw_end = env->wall.line_height / 2 + env->vars.res_y / 2;
		if (env->wall.draw_end >= env->vars.res_y)
			env->wall.draw_end = env->vars.res_y - 1;

		// texture //
		/***********/
		print_texture(env, x, env->wall.draw_start, env->wall.draw_end);

		// zBuffer[x] = perpWallDist
		env->sprite.z_buffer[x] = env->ray.perp_wall_dist;
		++x;
	}


	// spritre //
	/***********/

	int		i;
	int		y;
	int		v_move_screen;

	i = 0;
	y = 0;
	while (i < env->sprite.num)
	{
		printf("%d\n", env->sprite.order[i]);
//		printf("%d = x : %f\n", i, env->sprite.x[env->sprite.order[i]]);
//		printf("%d = y : %f\n", i, env->sprite.y[env->sprite.order[i]]);
		++i;
	}
	i = 0;

	sort_sprite(env);
	while (i < env->sprite.num)
	{
		//	spriteX | spriteY
		env->sprite.X = env->sprite.x[env->sprite.order[i]] - env->player.pos_x;
		env->sprite.Y = env->sprite.y[env->sprite.order[i]] - env->player.pos_y;

//printf("puting text n[%d] at x[%f] y[%f]\n", i, env->sprite.x[env->sprite.order[i]], env->sprite.y[env->sprite.order[i]]);
		//	invDet
		env->sprite.inv_det = 1.0 / (env->ray.plane_x * env->ray.dir_y - env->ray.dir_x * env->ray.plane_y);

		//	transformX | transformY
		env->sprite.transform_x = -env->sprite.inv_det * (env->ray.dir_y * env->sprite.X - env->ray.dir_x * env->sprite.Y);
		env->sprite.transform_y = env->sprite.inv_det * (-env->ray.plane_y * env->sprite.X + env->ray.plane_x * env->sprite.Y);

		//	spriteScreenX
		env->sprite.screen_x = (int)(env->vars.res_x / 2) * (1.0 + env->sprite.transform_x / env->sprite.transform_y);

		v_move_screen = (int)(0 / env->sprite.transform_y);

		//	spriteHeight
		env->sprite.height_sprite = abs((int)(env->vars.res_y / env->sprite.transform_y));

		//	drawStartY | drawEndY
		env->sprite.draw_start_y = -env->sprite.height_sprite / 2 + env->vars.res_y / 2 + v_move_screen;
		if (env->sprite.draw_start_y < 0)
			env->sprite.draw_start_y = 0;
		env->sprite.draw_end_y = env->sprite.height_sprite / 2 + env->vars.res_y / 2 + v_move_screen;
		if (env->sprite.draw_end_y >= env->vars.res_y)
			env->sprite.draw_end_y = env->vars.res_y - 1;

		//	spriteWidth
		env->sprite.width_sprite = abs((int)(env->vars.res_y / env->sprite.transform_y));

		//	drawStartX | drawEndY
		env->sprite.draw_start_x = -env->sprite.width_sprite / 2 + env->sprite.screen_x;
		if (env->sprite.draw_start_x < 0)
			env->sprite.draw_start_x = 0;
		env->sprite.draw_end_x = env->sprite.width_sprite / 2 + env->sprite.screen_x;
		if (env->sprite.draw_end_x >= env->vars.res_x)
			env->sprite.draw_end_x = env->vars.res_x - 1;


		//	loop d'affichage des sprites //

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
			if (env->sprite.transform_y > 0 && stripe > 0 && stripe < env->vars.res_x && env->sprite.transform_y < env->sprite.z_buffer[stripe])
			{
				y = env->sprite.draw_start_y;
				while (y < env->sprite.draw_end_y)
				{
					//	d
					d = (y - v_move_screen) * 256 - env->vars.res_y * 128 + env->sprite.height_sprite * 128;

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


		++i;
	}
	return (1);
}














