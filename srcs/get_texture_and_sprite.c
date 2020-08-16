/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/16 16:01:59 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	texture_copy(t_env *env)
{
	int		end;
	int		i;

	end = env->tex.width_north * env->tex.height_north;
	i = 0;
	while (i < end)
	{
		env->tex.tex_north[i] = env->tex.addr_north[i];
		++i;
	}

	end = env->tex.width_south * env->tex.height_south;
	i = 0;
	while (i < end)
	{
		env->tex.tex_south[i] = env->tex.addr_south[i];
		++i;
	}


	end = env->tex.width_east * env->tex.height_east;
	i = 0;
	while (i < end)
	{
		env->tex.tex_east[i] = env->tex.addr_east[i];
		++i;
	}

	end = env->tex.width_west * env->tex.height_west;
	i = 0;
	while (i < end)
	{
		env->tex.tex_west[i] = env->tex.addr_west[i];
		++i;
	}

}

int				get_texture_and_sprite(t_env *env)
{

// creation image contenant la texture
	if (!(env->tex.img_north = mlx_xpm_file_to_image(env->vars.mlx,
	env->vars.path_north, &env->tex.width_north, &env->tex.height_north)))
		return (aie_error("tex not download\n"));

	if (!(env->tex.img_east = mlx_xpm_file_to_image(env->vars.mlx,
	env->vars.path_east, &env->tex.width_east, &env->tex.height_east)))
		return (aie_error("tex not download\n"));

	if (!(env->tex.img_south = mlx_xpm_file_to_image(env->vars.mlx,
	env->vars.path_south, &env->tex.width_south, &env->tex.height_south)))
		return (aie_error("tex not download\n"));

	if (!(env->tex.img_west = mlx_xpm_file_to_image(env->vars.mlx,
	env->vars.path_west, &env->tex.width_west, &env->tex.height_west)))
		return (aie_error("tex not download\n"));

// recuperation des adresses et des donnees des images de la tex et de la fenetre

	env->tex.addr_north = (unsigned int *)mlx_get_data_addr(env->tex.img_north,
	&env->tex.bpp, &env->tex.line_length, &env->tex.endian);

	env->tex.addr_south = (unsigned int *)mlx_get_data_addr(env->tex.img_south,
	&env->tex.bpp, &env->tex.line_length, &env->tex.endian);

	env->tex.addr_west = (unsigned int *)mlx_get_data_addr(env->tex.img_west,
	&env->tex.bpp, &env->tex.line_length, &env->tex.endian);

	env->tex.addr_east = (unsigned int *)mlx_get_data_addr(env->tex.img_east,
	&env->tex.bpp, &env->tex.line_length, &env->tex.endian);



	env->tex.width[0] = env->tex.width_south;
	env->tex.width[1] = env->tex.width_east;
	env->tex.width[2] = env->tex.width_north;
	env->tex.width[3] = env->tex.width_west;

	env->tex.tex_north = ft_calloc(env->tex.width[2] * env->tex.height_north, sizeof(unsigned int));
	env->tex.tex_east = ft_calloc(env->tex.width[1] * env->tex.height_east, sizeof(unsigned int));
	env->tex.tex_south = ft_calloc(env->tex.width[0] * env->tex.height_south, sizeof(unsigned int));
	env->tex.tex_west = ft_calloc(env->tex.width[3] * env->tex.height_west, sizeof(unsigned int));

	texture_copy(env);
	return (1);
}
