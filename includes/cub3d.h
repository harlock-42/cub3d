/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 17:04:10 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/10 15:22:29 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_CUB3D_H
# define DEF_CUB3D_H
# define RES_MAX_X			2560
# define RES_MAX_Y			1440
# define FOV				1.1780972
# define MOVE_SPEED			0.1
# define ROT_SPEED			0.05
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"

/*
** key for mac
*/

/*
# define KEY_A				0
# define KEY_D				2
# define KEY_S				1
# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define KEY_EXPOSE_HOOK	12
# define KEY_EXIT_HOOK		53
*/

/*
** key for linux
*/


# define KEY_A				97
# define KEY_D				100
# define KEY_S				115
# define KEY_W				119
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_EXIT_HOOK		65307


typedef	struct		s_sprite
{
	int				num;
	void			*img;
	float			*x;
	float			*y;
	float			x_s;
	float			y_s;
	float			inv_det;
	float			transform_x;
	float			transform_y;
	int				screen_x;
	int				height_sprite;
	int				width_sprite;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				width;
	int				height;
	unsigned	int	*addr;
	int				bpp;
	int				line_length;
	int				endian;
	unsigned	int	*sprite;
	float			*z_buffer;
	float			*distance;
	int				*order;
}					t_sprite;

typedef	struct		s_tex
{
	void			**img;
	unsigned int	**addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				line_height;
	int				width[4];
	int				height[4];
	unsigned int	**tex;
	int				tex_x;
	int				tex_y;
	float			wall_x;
	float			step;
}					t_tex;

typedef	struct		s_key
{
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rot_left;
	int				rot_right;
	int				escape;
}					t_key;

typedef	struct		s_wall
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	int				ceil_color;
	int				floor_color;
}					t_wall;

typedef	struct		s_ray
{
	float			camera_x;
	float			ray_dir_x;
	float			ray_dir_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			step_x;
	float			step_y;
	float			side_dist_x;
	float			side_dist_y;
	float			perp_wall_dist;
	float			map_x;
	float			map_y;
	int				side;
}					t_ray;

typedef	struct		s_vars
{
	void			*mlx;
	void			*win;
	char			**map;
	int				save;
	int				res_x;
	int				res_y;
	int				floor_color;
	int				ceil_color;
	char			**path_tex;
	char			*path_sprite;
}					t_vars;

typedef	struct		s_map
{
	int				**map;
	int				size;
}					t_map;

typedef	struct		s_player
{
	float			pos_x;
	float			pos_y;
	float			dir;
}					t_player;

typedef	struct		s_check
{
	int				r;
	int				no;
	int				we;
	int				ea;
	int				so;
	int				s;
	int				f;
	int				c;
}					t_check;

typedef	struct		s_env
{
	t_sprite		sprite;
	t_check			check;
	t_vars			vars;
	t_player		player;
	t_map			map;
	t_ray			ray;
	t_wall			wall;
	t_key			key;
	t_tex			tex;
}					t_env;

/*
** aie_error.c
*/
int					aie_error(const char *str);
/*
** arg_save.c
*/
int					create_bmp_file(t_env *env);
int					is_arg_save(char *arg);
/*
** check_color_data.c
*/
int					check_color_data(char *str);
/*
** check_map.c
*/
int					check_map(char **map);
/*
** free_data.c
*/
void				free_file(void **map);
/*
** check_param_file.c
*/
int					check_param_file(t_env *env);
/*
** check_file.c
*/
int					check_path(char *str);
/*
** check_is_map_close.c
*/
int					check_is_map_close(char **map);
/*
** check_is_map_close_last_column.c
*/
int					last_column(char **map);
/*
** check_res.c
*/
int					check_res(char *str, t_env *env);
/*
** display.c
*/
void				new_image(t_env *env);
/*
** draw_column_px.c
*/
void				draw_column_px(t_env *env, int x, int start, int end);
void				my_mlx_pixel_put(t_env *env, int x, int y,
					unsigned int color);
/*
** exit_game.c
*/
int					exit_game(t_env *env);
/*
** escape_game.c
*/
int					escape_game(t_env *env);
/*
** free_data.c
*/
void				free_img(t_env *env);
/*
** parsing_map.c
*/
int					is_map_start(char *map);
int					parsing_file(t_env *env);
/*
** get_color.c
*/
int					get_color_ceil_and_floor(t_env *env, char *str);
/*
** get_data_id.c
*/
int					get_data_id(t_env *env, char *str);
/*
** get_file.c
*/
int					get_file(t_env *env, const char *file_name);
/*
** get_map.c
*/
int					get_pos_player(char **map, t_env *env);
/*
** get_texture_and_sprite.c
*/
int					get_texture_and_sprite(t_env *env);
/*
** get_texture_path.c
*/
int					get_texture_path(t_env *env, char *str);
/*
** init.c
*/
int					init_env(t_env *env);
int					init_vars(t_env *env);
/*
** init_2.c
*/
void				init_check(t_env *env);
int					init_raycaster(t_env *env);
/*
** init_3.c
*/
void				init_env_tex_2(t_env *env);
/*
** key.c
*/
int					key_pressed(int keycode, t_env *env);
int					key_released(int keycode, t_env *env);
int					red_cross(int keycode, t_env *env);
/*
** move_player.c
*/
void				move_player(t_env *env);
/*
** parsing_map.c
*/
int					parsing_file(t_env *emv);
/*
** print_texture.c
*/
int					wich_plan(t_env *env);
void				print_texture(t_env *env, int x, int start, int end);
void				wall_size(t_env *env);
/*
** raycasting.c
*/
int					raycast(t_env *env);
/*
** raycasting_2.c
*/
void				init_dir_player(t_env *env);
void				init_plane(t_env *env);
void				wall_x(t_env *env, int tex_width);
/*
** sprite_utils.c
*/
void				sort_sprite(t_env *env);
int					sprite_pos(t_env *env);
void				sprite_distance(t_env *env);
/*
** sprite.c
*/
void				sprite(t_env *env);
/*
** utils.c
*/
void				free_map(t_env *env);
void				res_max(t_env *env);
char				*strdup_path(char *str);

#endif
