/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_and_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:16:00 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/06 15:01:53 by tallaire         ###   ########.fr       */
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
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
	int		color;
	void	*tex;
	char	*img;

	tex = NULL;
	img = NULL;
	bits_per_pixel = 0;
	size_line = 0;
	endian = 0;
	width = 0;
	height = 0;
	x = 0;
	y = 0;
	color = 0;

	ft_printf("test\n");
	img = mlx_xpm_file_to_image(env->vars.mlx, env->vars.path_north, &width, &height);
	ft_printf("height = %d\n", height);
	ft_printf("width = %d\n", width);
	tex = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	env->vars.mlx = mlx_init();
	env->vars.win = mlx_new_window(env->vars.mlx, env->vars.res_x, env->vars.res_y, "cub3d");
	while (y < env->vars.res_y)
	{
		x = 0;
		while (x < env->vars.res_x)
		{
			color = tex[(y * size_line + x * bits_per_pixel)];
//			my_mlx_px_put(env, x, y, color);
			++x;
		}
		++y;
	}
	mlx_loop(env->vars.mlx);
	ft_printf("bpp = %d\n", bits_per_pixel);
	return (1);
}
