/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/05 15:30:27 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			get_texture_and_sprite(t_env *env)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	void	*tex;
	char	*img;

	tex = NULL;
	img = NULL;
	bits_per_pixel = 0;
	size_line = 0;
	endian = 0;
	width = 0;
	height = 0;
	ft_printf("%s\n", env->vars.path_north);
	ft_printf("%p\n", mlx_xpm_file_to_image(env->vars.mlx, env->vars.path_north, &width, &height));
	/*
	if ((tex = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian)) == 0)
		ft_printf("non non non\n");
	ft_printf("bpp = %d\n", bits_per_pixel);
	*/
	return (1);
}
