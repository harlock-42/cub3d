/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:35:24 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/29 21:20:02 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

static	int	game(t_env *env)
{
	int	i;
	i = 0;
	free_img(env);
	new_image(env);
	move_player(env);
	raycast(env);
	mlx_put_image_to_window(env->vars.mlx, env->vars.win, env->wall.img, 0,
		0);
	return (1);
}

static	int	start_game(t_env *env)
{
	env->vars.mlx = mlx_init();
	env->vars.win = mlx_new_window(env->vars.mlx,
	env->vars.res_x, env->vars.res_y, "Cub3d");
	if (get_texture_and_sprite(env) < 0)
		return (0);
	mlx_hook(env->vars.win, 2, 1L << 0, key_pressed, env);
	mlx_hook(env->vars.win, 3, 1L << 1, key_released, env);
	mlx_loop_hook(env->vars.mlx, game, env);
	mlx_loop(env->vars.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2 || argc > 3)
		return (0);
	init_env(&env);
	if (get_file(&env, argv[1]) < 0)
		return (0);
	if (init_vars(&env) < 0)
		return (0);
	if (parsing_file(&env) < 0)
		return (0);
	if (init_raycaster(&env) < 0)
		return (0);
	ft_printf("argc = %d\n", argc);
	if (argc == 3)
		if (is_arg_save(argv[2]) > 0)
			create_bmp_file(&env);
	start_game(&env);
	return (0);
}
