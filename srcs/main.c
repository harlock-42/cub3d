/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:35:24 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/02 18:14:00 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

static	void	init_env(t_env *env)
{
	env->vars.escape = 0;
	env->player.move_x = 0.0;
	env->player.move_y = 0.0;
}


static	int	start_game(t_env *env)
{
	init_env(env);
	env->vars.mlx = mlx_init();
	env->vars.win = mlx_new_window(env->vars.mlx,
	env->vars.res_x, env->vars.res_y, "Cub3d");
	dist_ray(env);
	mlx_loop(env->vars.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 2)
		return (0);
	if (get_file(&env, argv[1]) < 0)
		return (0);
	if (parsing_file(&env) < 0)
		return (0);
	start_game(&env);
	return (0);
}
