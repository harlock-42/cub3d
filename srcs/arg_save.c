/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harlock <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:43:03 by harlock           #+#    #+#             */
/*   Updated: 2020/09/03 18:31:13 by tallaire         ###   ########.fr       */
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
	int				color;
	int				x;
	int				y;

	y = env->vars.res_y - 1;
	x = 0;
	if (!(buffer = ft_calloc(env->vars.res_x *
		env->vars.res_y, sizeof(unsigned int))))
		return (aie_error("bmp file alloc memory failed"));
	color = 0;
	while (y >= 0)
	{
		write(fd, &env->wall.addr[y * env->vars.res_x], env->vars.res_x * 4);
		y--;
	}
	free(buffer);
	return (1);
}

static	int		insert_header(t_env *env, int fd)
{
	unsigned	char	*header;

	if (!(header = ft_calloc(sizeof(char), 54)))
		return (aie_error("Header bmp file alloc memory failed"));
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)(54 + env->vars.res_x * (env->vars.res_y - 1) * 4);
	header[3] = (unsigned char)((54 + env->vars.res_x * (env->vars.res_y - 1) * 4) >> 8);
	header[4] = (unsigned char)((54 + env->vars.res_x * (env->vars.res_y - 1) * 4) >> 16);
	header[5] = (unsigned char)((54 + env->vars.res_x * (env->vars.res_y - 1) * 4) >> 24);
	header[10] = 54;
	header[14] = 40;
	header[18] = (unsigned char)(env->vars.res_x);
	header[19] = (unsigned char)(env->vars.res_x >> 8);
	header[20] = (unsigned char)(env->vars.res_x >> 16);
	header[21] = (unsigned char)(env->vars.res_x >> 24);
	header[22] = (unsigned char)(env->vars.res_y);
	header[23] = (unsigned char)(env->vars.res_y >> 8);
	header[24] = (unsigned char)(env->vars.res_y >> 16);
	header[25] = (unsigned char)(env->vars.res_y >> 24);
	header[26] = 1;
	header[28] = 32;
	write(fd, header, 54);
	free(header);
	return (1);
}

int			create_bmp_file(t_env *env)
{
	int		fd;

	env->vars.save = 1;
	if ((fd = open("./screen_shot.bmp", O_CREAT | O_WRONLY, S_IRWXU)) < 0)
		return (aie_error("bmp file opening failed"));
	env->vars.mlx = mlx_init();
	res_max(env);
	new_image(env);
	if (get_texture_and_sprite(env) < 0)
		return (-1);
	raycast(env);
	if (insert_header(env, fd) < 0)
		return (-1);
	if (insert_img(env, fd) < 0)
		return (-1);
	free_img(env);
	free(env->vars.mlx);
	exit_game(env);
	return (0);
}
