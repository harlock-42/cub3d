/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:52:04 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/06 14:52:06 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		exit_game(t_env *env)
{
	free_img(env);
	mlx_clear_window(env->vars.mlx, env->vars.win);
	mlx_destroy_window(env->vars.mlx, env->vars.win);
	exit(1);
	return (1);
}
