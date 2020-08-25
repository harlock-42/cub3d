/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:35:15 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/25 19:35:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void		sort_sprite(t_env *env)
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
			if (env->sprite.distance[j] > env->sprite.distance[j + 1])
			{
				tmp = env->sprite.distance[j];
				env->sprite.distance[j] = env->sprite.distance[j + 1];
				env->sprite.distance[j + 1] = tmp;
				tmp = env->sprite.order[j];;
				env->sprite.order[j] = env->sprite.order[j + 1];
				env->sprite.order[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}

static	int		*realloc_sprite_pos(t_env *env, int *tab)
{
	int		*new;
	int		i;

	i = 0;
	if (!(new = (int *)malloc(sizeof(int) * env->sprite.num)))
		return (NULL);
	while (i < env->sprite.num - 1)
	{
		new[i] = tab[i];
		++i;
	}
	free(tab);
	return (new);
}

int				sprite_pos(t_env *env, int x, int y)
{
	++env->sprite.num;
	if (env->sprite.x != NULL)
	{
		if (!(env->sprite.x = realloc_sprite_pos(env, env->sprite.x)))
			return (-1);
	}
	else
		if (!(env->sprite.x = (int *)malloc(sizeof(int) *
		env->sprite.num)))
			return (-1);
	if (env->sprite.x != NULL)
	{
		if (!(env->sprite.y = realloc_sprite_pos(env, env->sprite.y)))
			return (-1);
	}
	else
		if (!(env->sprite.y = (int *)malloc(sizeof(int) *
		env->sprite.num)))
			return (-1);
	env->sprite.x[env->sprite.num - 1] = x;
	env->sprite.y[env->sprite.num - 1] = y;
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
	sort_sprite(env);
}








