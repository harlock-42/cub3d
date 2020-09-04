

#include "../includes/cub3d.h"

static	void	free_texture_sprite(t_env *env)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(env->tex.tex[i]);
		free(env->tex.img[i]);
		free(env->vars.path_tex[i]);
		++i;
	}
	free(env->tex.tex);
	free(env->tex.img);
	free(env->vars.path_tex);
	free(env->sprite.z_buffer);
	free(env->sprite.sprite);
	free(env->tex.addr);
	free(env->vars.path_sprite);
	free(env->sprite.x);
	free(env->sprite.y);
	free(env->sprite.order);
	if (env->sprite.num > 0)
	{
		free(env->sprite.distance);
	}
}


void		exit_game(t_env *env)
{
	free_texture_sprite(env);
	free_map(env);
}
