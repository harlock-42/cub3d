/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:35:15 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/08 13:38:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			sort_sprite(t_env *env)
{
	int			i;
	int			j;
	int			tmp;

	i = 0;
	tmp = 0;
	while (i < env->sprite.num)
	{
		j = 0;
		while (j < env->sprite.num - 1)
		{
			if (env->sprite.distance[j] < env->sprite.distance[j + 1])
			{
				tmp = env->sprite.distance[j];
				env->sprite.distance[j] = env->sprite.distance[j + 1];
				env->sprite.distance[j + 1] = tmp;
				tmp = env->sprite.order[j];
				env->sprite.order[j] = env->sprite.order[j + 1];
				env->sprite.order[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

static	void	sprite_pos_loop(t_env *env, int start, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (env->vars.map[start + y] != NULL)
	{
		x = 0;
		while (env->vars.map[start + y][x] != '\0')
		{
			if (env->vars.map[start + y][x] == '2')
			{
				env->sprite.x[i] = x + 0.5;
				env->sprite.y[i] = y + 0.5;
				++i;
			}
			++x;
		}
		++y;
	}
}

int				sprite_pos(t_env *env)
{
	int		start;
	int		i;

	start = 0;
	i = 0;
	if (!(env->sprite.x = (float *)malloc(sizeof(float) * env->sprite.num)))
		return (-1);
	if (!(env->sprite.y = (float *)malloc(sizeof(float) * env->sprite.num)))
		return (-1);
	if (!(env->sprite.order = (int *)malloc(sizeof(int) * env->sprite.num)))
		return (-1);
	while (is_map_start(env->vars.map[start]) < 0)
		++start;
	sprite_pos_loop(env, start, i);
	return (1);
}

void			sprite_distance(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < env->sprite.num)
	{
		env->sprite.order[i] = i;
		env->sprite.distance[i] = (int)((env->player.pos_x - env->sprite.x[i]) *
		(env->player.pos_x - env->sprite.x[i])) +
		((env->player.pos_y - env->sprite.y[i]) *
		(env->player.pos_y - env->sprite.y[i]));
		++i;
	}
}
