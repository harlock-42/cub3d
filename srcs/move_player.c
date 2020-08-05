/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:11:07 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/05 15:42:30 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	move_rot(t_env *env)
{
	float	old_dir_x;
	float	old_plane_x;
	int	rot;

	if (env->key.rot_left == 1)
		rot = (-1);
	else
		rot = 1;
	old_dir_x = env->ray.dir_x;
	old_plane_x = env->ray.plane_x;
	env->ray.dir_x = env->ray.dir_x * cos(ROT_SPEED * rot) -
	env->ray.dir_y * sin(ROT_SPEED * rot);
	env->ray.dir_y = old_dir_x * sin(ROT_SPEED * rot) + env->ray.dir_y *
	cos(ROT_SPEED * rot);
	env->ray.plane_x = env->ray.plane_x * cos(ROT_SPEED * rot) -
	env->ray.plane_y * sin(ROT_SPEED * rot);
	env->ray.plane_y = old_plane_x * sin(ROT_SPEED * rot) +
	env->ray.plane_y * cos(ROT_SPEED * rot);
}

static	void	move_back_forward(t_env *env)
{
	if (env->key.forward == 1)
	{
		if (env->map.map[(int)env->player.pos_y]
		[(int)(env->player.pos_x + env->ray.dir_x * MOVE_SPEED)] == 0)
			env->player.pos_x += env->ray.dir_x * MOVE_SPEED;
		if (env->map.map[(int)(env->player.pos_y + env->ray.dir_y *
		MOVE_SPEED)][(int)env->player.pos_x] == 0)
			env->player.pos_y += env->ray.dir_y * MOVE_SPEED;
	}
	else if (env->key.back == 1)
	{
		if (env->map.map[(int)env->player.pos_y]
		[(int)(env->player.pos_x - env->ray.dir_x * MOVE_SPEED)] == 0)
			env->player.pos_x -= env->ray.dir_x * MOVE_SPEED;
		if (env->map.map[(int)(env->player.pos_y - env->ray.dir_y *
		MOVE_SPEED)][(int)env->player.pos_x] == 0)
			env->player.pos_y -= env->ray.dir_y * MOVE_SPEED;
	}
}

void		move_player(t_env *env)
{
	if (env->key.forward == 1 || env->key.back == 1)
		move_back_forward(env);
	if (env->key.rot_left == 1 || env->key.rot_right == 1)
		move_rot(env);
}

