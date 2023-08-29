/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:09:55 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/26 18:09:59 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define MINIMAP_W	100
# define MINIMAP_H	100
# define WIN_W	1600
# define WIN_H	900
# define TILE_SIZE	64
# define MAP_SCALE	16
# define MAGNITUDE_ANGLE	3
# define MAGNITUDE	10
# define SPRITE_AMMOUNT	3

# define KEY_A	97
# define KEY_S	115
# define KEY_D	100
# define KEY_Q	113
# define KEY_W	119
# define KEY_E	101
# define KEY_UP	65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_ESC	65307

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "cub_math.h"
# include "game.h"
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef unsigned int	t_uint;

// Color
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
int			get_opacity(int trgb);
int			gen_trgb(int opacity, int red, int green, int blue);

// Game
int			exit_game(t_game *game);
void		free_image(t_image *image);
void		put_pixel_img(t_image *img, int x, int y, int color);
t_image		*new_image(t_window *window, int height, int width);
t_window	*new_window(int height, int width, char *str);

// maps list utils
t_map		*new_map(char **map);
void		add_map(t_map **map, t_map *new);
void		delete_node(t_map **map, t_map *node);
void		delete_list(t_map **map);
int			map_size(t_map *map);

// cool parser
int			get_scene(t_game *game);
int			parse_scene(t_game *game);
void		init_attributes(t_game *game);
int	count_lines(const char *s);
char	**free_arr(char **arr);
int	ft_iswhitespace(char c);
void	print_arr(char **arr);
int	parse_maps(t_game *game);
void	check_valid_map(t_game *game);
int		longest_line(char **arr);
char *ft_repeat(int count, char c);
char	*fill_line_with_spaces(char *line, int len);
char **fill_map_with_spaces(char **map);
char	**surround_map_with_spaces(char **map);
char **clone_arr(char **arr);
void	is_surrounded_by_walls(t_game *game);
char	*get_map(t_game *game);
int	map_list(t_game *game, char *map);
int	store_map_list(t_game *game, char *maps, int i);
int	check_files(t_game *game);
int	check_attributes(t_game *game);
int	check_attributes_i(t_game *game);
int	set_color(t_game *game, char *attr, char *value);
int	check_attr(t_game *game);
int	is_attr(t_game *game, char *s, int i);
void	send_attr_err(t_game *game);
int	get_single_attribute(t_game *game, char **scene, int i);
int	get_attributes(t_game *game);
void	close_array(int *arr, int size);
int	attr_error(t_game *game, int code, char *attr);
int	set_attr(t_game *game, char *attr, char *value);
int	check_color(char *color);
char	**split_attribute(char *attr);
int	comma_count(char *s);
int	print_error(char *s, char *arg);
void	reset_tools(t_game *game);
int	player_init(t_game *game);
int			player_prologue(t_game *game);
void		free_game(t_game *game);

// Raycasting
void		raycasting3d(t_game *game);
void		paint_map(t_game *game);

// Textures
t_uint		texture_pixel_color(t_game *game, t_point p, t_ray r, t_image *t);
void		init_walls(t_game *game, t_window *win);
void		destroy_walls(t_window *win, t_walls walls);

// Utils
int			r_angle(int angle);
int			file_exists(char *filename);
int			collide(t_game *game, t_point p, int angle);
double		magic_distance(t_game *game, int ray_angle);
double		nearest_horizontal(t_game *game, int a);
double		nearest_vertical(t_game *game, int a);
double		norm(t_game *game, int x, int y);
char		*get_next_line_no_nl(char *line);

// Actions
void		move(int key_code, t_game *game);
void		rotate(int key_code, t_game *game);
int			update(t_game *game);
int			handle_key_up(int key_code, void *params);
int			handle_key_down(int key_code, void *params);
void		rotate_right(t_game *game);
void		rotate_left(t_game *game);
void		paint_window(t_game *game);
void		move_right(t_game *game);
void		move_left(t_game *game);
void		move_up(t_game *game);
void		move_down(t_game *game);

// Utils
void		ft_arrfree(char **arr);
char		*ft_strndup(const char *s, size_t n);
int			ft_arrlen(char **arr);
int			ft_strreps(char *str, char c);
void		print_game(t_game *game);

#endif
