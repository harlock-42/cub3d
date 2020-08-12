/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/11 18:15:28 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
static	void	open_window(t_env *env)
{
	int		y;
	int		x;
	float	step_x;
	float	step_y;
	unsigned	int	color;
	unsigned	int	*dst;

	y = 0;
	x = 0;
	color = 0;
	step_x = (float)env->tex.width / (float)env->vars.res_x;
	step_y = (float)env->tex.height / (float)env->vars.res_y;

	env->wall.img =
	mlx_new_image(env->vars.mlx, env->vars.res_x, env->vars.res_y);
	env->wall.addr = (unsigned int *)mlx_get_data_addr(env->wall.img,
	&env->wall.bpp, &env->wall.line_length, &env->wall.endian);
	while (x < env->tex.width)
	{
		y = 0;
		while (y < env->tex.height)
		{
			if (y < env->tex.height && x < env->tex.width)
			{
				color = env->tex.addr[y * env->tex.width + x];
				env->tex.buffer[(int)floor((float)y * step_y)]
				[(int)floor((float)x * step_x)] = color;
			}
			++y;
		}
		++x;
	}
	y = 0;
	x = 0;
	while (x < env->vars.res_x)
	{
		y = 0;
		while (y < env->vars.res_y)
		{
//			if (y < env->tex.height && x < env->tex.width)
//			{
				color = env->tex.buffer[y][x];
				color = env->tex.buffer[(int)floor((float)y * step_y)]
				[(int)floor((float)x * step_x)];
				dst = env->wall.addr + (y * env->vars.res_x + x);
				*dst = color;
//			}
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(env->vars.mlx, env->vars.win, env->wall.img, 0, 0);
	mlx_loop(env->vars.mlx);
}
*/
int				get_texture_and_sprite(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;

// creation image contenant la texture
	if (!(env->tex.img = mlx_xpm_file_to_image(env->vars.mlx,
	env->vars.path_north, &env->tex.width, &env->tex.height)))
		return (aie_error("tex not download\n"));

// recuperation des adresses et des donnees des images de la tex et de la fenetre.

//	env->tex.addr = (unsigned int *)mlx_get_data_addr(env->tex.img, &env->tex.bpp, &env->tex.line_length, &env->tex.endian);

//	open_window(env);
	return (1);
}
