/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:03:19 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/06 17:03:20 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		free_img(t_env *env)
{
	if (env->wall.img != NULL)
	{
//		ft_printf("test\n");
		mlx_destroy_image(env->vars.mlx, env->wall.img);
//		free(env->wall.img);
//		env->wall.img = NULL;
	}
}
