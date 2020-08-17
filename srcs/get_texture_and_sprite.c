/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/17 17:41:38 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		texture_copy(t_env *env)
{
	int		end;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		if (!(env->tex.img[i] = mlx_xpm_file_to_image(env->vars.mlx,
		env->vars.path_tex[i], &env->tex.width[i], &env->tex.height[i])))
			return (aie_error("tex not download\n"));
		env->tex.addr[i] = (unsigned int *)mlx_get_data_addr(env->tex.img[i],
		&env->tex.bpp, &env->tex.line_length, &env->tex.endian);
		if (!(env->tex.tex[i] = ft_calloc(env->tex.width[i] *
		env->tex.height[i], sizeof(unsigned int))))
			return (-1);
		j = 0;
		end = env->tex.width[i] * env->tex.height[i];
		while (j < end)
		{
			env->tex.tex[i][j] = env->tex.addr[i][j];
			++j;
		}
		++i;
	}
	return (1);
}

int				get_texture_and_sprite(t_env *env)
{
	if (texture_copy(env) < 0)
		return (-1);
	return (1);
}
