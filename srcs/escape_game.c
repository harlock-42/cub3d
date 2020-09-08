/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:54:40 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 11:54:50 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		escape_game(t_env *env)
{
	free_img(env);
	mlx_clear_window(env->vars.mlx, env->vars.win);
	mlx_destroy_window(env->vars.mlx, env->vars.win);
	exit_game(env);
	exit(0);
	return (1);
}
