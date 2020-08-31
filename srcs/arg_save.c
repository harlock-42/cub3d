/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:43:03 by harlock           #+#    #+#             */
/*   Updated: 2020/08/31 20:19:21 by tallaire         ###   ########.fr       */
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
	unsigned	char	*buffer;
	unsigned	int		color;
	int					i;

	(void)fd;
	if (!(buffer = malloc(env->vars.res_x * env->vars.res_y * 4)))
		return (-1);
	color = 0;
	i = 0;
	while (i < env->vars.res_x * env->vars.res_y)
	{
		color = env->wall.addr[i];
		buffer[(i * 4)] = color;
		buffer[(i * 4) + 1] = color << 8;
		buffer[(i * 4) + 2] = color << 16;
		buffer[(i * 4) + 3] = color << 24;
		++i;
	}
//	ft_printf("x = %d\ny = %d\n", env->vars.res_x, env->vars.res_y);
	write(fd, buffer, env->vars.res_x * env->vars.res_y);
	free(buffer);
	return (1);
}

static	void	insert_header(t_env *env, int fd)
{
	unsigned	char	header[54];
	int					i;

	i = 0;
	while (i < 54)
	{
		header[i] = 0;
		++i;
	}
	header[0] = 'B';
	header[1] = 'M';
	header[2] = 54 + env->vars.res_x * env->vars.res_y * 4;
	header[3] = (54 + env->vars.res_x * env->vars.res_y * 4) << 8;
	header[4] = (54 + env->vars.res_x * env->vars.res_y * 4) << 16;
	header[5] = (54 + env->vars.res_x * env->vars.res_y * 4) << 24;
	header[10] = 54;
	header[14] = 40;
	header[18] = env->vars.res_x;
	header[19] = env->vars.res_x << 8;
	header[20] = env->vars.res_x << 16;
	header[21] = env->vars.res_x << 24;
	header[22] = env->vars.res_y;
	header[23] = env->vars.res_y << 8;
	header[24] = env->vars.res_y << 16;
	header[25] = env->vars.res_y << 24;
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
	if (get_texture_and_sprite(env) < 0)
		return (-1);
	new_image(env);
	raycast(env);
	insert_header(env, fd);
	if (insert_img(env, fd) < 0)
		return (-1);
	return (0);
}
