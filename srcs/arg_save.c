/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:43:03 by harlock           #+#    #+#             */
/*   Updated: 2020/09/01 21:00:58 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			is_arg_save(char *arg)
{
	if (arg[0] == '-' && arg[1] == '-' && arg[2] == 's' && arg[3] == 'a' &&
		arg[4] == 'v' && arg[5] == 'e')
		return (1);
	else
		ft_printf("Error\nThird argument is not recognized\n");
	return (-1);
}

static	int		insert_img(t_env *env, int fd)
{
	unsigned	int	*buffer;
	int		color;
	int					i;
	int					x;
	int					y;

	y = env->vars.res_y;
	x = 0;
	if (!(buffer = ft_calloc(env->vars.res_x *
		env->vars.res_y, sizeof(unsigned int))))
		return (-1);
	color = 0;
	i = 0;
	while (y)
	{
//			ft_printf("y = %d | x = %d\n", y, x);
		x = 0;
//		while (x <= env->vars.res_x)
//		{
			write(fd, &env->wall.addr[y * env->vars.res_x], env->vars.res_x * 4);
//			x++;
//		}
		y--;
	}
//	write(fd, env->wall.addr, env->vars.res_x * env->vars.res_y * 4);
	free(buffer);
	return (1);
}

static	void	insert_header(t_env *env, int fd)
{
	unsigned	char	*header;

	header = ft_calloc(sizeof(unsigned char), 54);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)(54 + env->vars.res_x * env->vars.res_y * 4);
	header[3] = (unsigned char)((54 + env->vars.res_x * env->vars.res_y * 4) >> 8);
	header[4] = (unsigned char)((54 + env->vars.res_x * env->vars.res_y * 4) >> 16);
	header[5] = (unsigned char)((54 + env->vars.res_x * env->vars.res_y * 4) >> 24);
	header[10] = 54;
	header[14] = 40;
	header[18] = (unsigned char)(env->vars.res_x);
	header[19] = (unsigned char)((env->vars.res_x) >> 8);
	header[20] = (unsigned char)((env->vars.res_x) >> 16);
	header[21] = (unsigned char)((env->vars.res_x) >> 24);
	header[22] = (unsigned char)(env->vars.res_y);
	header[23] = (unsigned char)((env->vars.res_y) >> 8);
	header[24] = (unsigned char)((env->vars.res_y) >> 16);
	header[25] = (unsigned char)((env->vars.res_y) >> 24);
	header[26] = 1;
	header[28] = 32;
	write(fd, header, 54);
}

int			create_bmp_file(t_env *env)
{
	int		fd;

	if ((fd = open("./screen_shot.bmp", O_CREAT | O_WRONLY, S_IRWXU)) < 0)
		return (-1);
	env->vars.mlx = mlx_init();
	new_image(env);
	if (get_texture_and_sprite(env) < 0)
		return (-1);
	raycast(env);
	insert_header(env, fd);
	if (insert_img(env, fd) < 0)
		return (-1);
	return (0);
}
