/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:33:59 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/06 12:10:59 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_released(int keycode, t_env *env)
{
	if (keycode == KEY_W)
		env->key.forward = 0;
	else if (keycode == KEY_S)
		env->key.back = 0;
	else if (keycode == KEY_A)
		env->key.left = 0;
	else if (keycode == KEY_D)
		env->key.right = 0;
	else if (keycode == KEY_LEFT)
		env->key.rot_left = 0;
	else if (keycode == KEY_RIGHT)
		env->key.rot_right = 0;
	else if (keycode == KEY_EXIT_HOOK)
		env->key.escape = 1;
//	printf("release = %d\n", keycode);
	return (keycode);
}

int	key_pressed(int keycode, t_env *env)
{
	if (keycode == KEY_EXIT_HOOK)
		exit_game(env);
	else if (keycode == KEY_W)
		env->key.forward = 1;
	else if (keycode == KEY_S)
		env->key.back = 1;
	else if (keycode == KEY_A)
		env->key.left = 1;
	else if (keycode == KEY_D)
		env->key.right = 1;
	else if (keycode == KEY_LEFT)
		env->key.rot_left = 1;
	else if (keycode == KEY_RIGHT)
		env->key.rot_right = 1;
//	printf("press = %d\n", keycode);
	return (keycode);
}
