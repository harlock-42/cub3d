/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/07 16:30:07 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
static	void	my_mlx_px_put(t_env *env, int x, int y, int color)
{
	char *dst;

	dst = env->wall.addr + (y * 
}
*/

int			get_texture_and_sprite(t_env *env)
{
	int		x;
	int		y;
	unsigned int	*dst;

	x = 0;
	y = 0;


	dst = NULL;
// creation fenetre
	env->vars.mlx = mlx_init();
	env->vars.win = mlx_new_window(env->vars.mlx, env->vars.res_x, env->vars.res_y, "cub3d");

// creaton de l image qui sera affichee dans la fenetre
	env->wall.img = mlx_new_image(env->vars.mlx, env->vars.res_x, env->vars.res_y);

// creation image contenant la texture
	env->tex.img = mlx_xpm_file_to_image(env->vars.mlx, env->vars.path_north, &env->tex.width, &env->tex.height);

// recuperation des adresses et des donnees des images de la tex et de la fenetre.

	env->wall.addr = (unsigned int *)mlx_get_data_addr(env->wall.img, &env->wall.bpp, &env->wall.line_length, &env->wall.endian);
	env->tex.addr = (unsigned int *)mlx_get_data_addr(env->tex.img, &env->tex.bpp, &env->tex.line_length, &env->tex.endian);


	while (x < env->vars.res_x && x < env->tex.width)
	{
		y = 0;
		while (y < env->vars.res_y && y < env->tex.height)
		{
			if (x < env->tex.width && y < env->tex.height)
			{
				dst = env->wall.addr + (y * env->vars.res_x + x);
				*dst = env->tex.addr[(y * env->tex.width + x)];
			}
			else
			{
				dst = env->wall.addr + (y * env->vars.res_x + x);
				*(unsigned int*)dst = 0X00FF00FF;
			}

			++y;
		}
		x++;
	}




	mlx_put_image_to_window(env->vars.mlx, env->vars.win, env->wall.img, 0, 0);
	mlx_loop(env->vars.mlx);
	return (1);
}
