/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:35:15 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/20 22:25:11 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void		sort_sprite(t_env *env)
{
	int			tmp;
	int			i;
	int			j;

	i = 0;
	tmp = 0;
	j = 0;
	while (i < env->sprite.num)
	{
		j = 0;
		++i;
		while (j < env->sprite.num)
		{
			if (env->sprite.distance[i] < env->sprite.distance[j])
			{
				tmp = env->sprite.order[j];
				env->sprite.order[j] = env->sprite.order[i];
				env->sprite.order[i] = tmp;
			}
			++j;
		}
	}
}

static	float	*realloc_sprite_pos(t_env *env, float *tab)
{
	float	*new;
	int		i;

	i = 0;
	if (!(new = (float *)malloc(sizeof(float) * env->sprite.num)))
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
		if (!(env->sprite.x = (float *)malloc(sizeof(float) *
		env->sprite.num)))
			return (-1);
	if (env->sprite.x != NULL)
	{
		if (!(env->sprite.y = realloc_sprite_pos(env, env->sprite.y)))
			return (-1);
	}
	else
		if (!(env->sprite.y = (float *)malloc(sizeof(float) *
		env->sprite.num)))
			return (-1);
	env->sprite.x[env->sprite.num - 1] = x + 0.5;
	env->sprite.y[env->sprite.num - 1] = y + 0.5;
	return (1);
}

void			sprite_distance(t_env *env)
{
	int		i;

	i = 0;
	(void)env;
	while (i < env->sprite.num)
	{
//		printf("x = %f | y = %f\n", env->sprite.x[i], env->sprite.y[i]);
//		printf("pos_x = %f | pos_y = %f\n", env->player.pos_x, env->player.pos_y);
		env->sprite.order[i] = i;
		env->sprite.distance[i] = ((env->player.pos_x - env->sprite.x[i]) *
		(env->player.pos_x - env->sprite.x[i])) +
		((env->player.pos_y - env->sprite.y[i]) *
		(env->player.pos_y - env->sprite.y[i]));
//		printf("%d = %f\n", i, env->sprite.distance[i]);
		++i;
	}
	sort_sprite(env);
	i = 0;
	while (i < env->sprite.num)
	{
		printf("%d = %f\n", i, env->sprite.distance[i]);
		++i;
	}
	i = 0;
	while (i < env->sprite.num)
	{
		printf("%d = %d\n", i, env->sprite.order[i]);
		++i;
	}
}








