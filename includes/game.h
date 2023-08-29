/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:10:03 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/26 18:10:05 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

struct	s_player;

typedef struct s_map {
	char			**map;
	int				width;
	int				height;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_window;

typedef struct s_image
{
	t_window	*win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}		t_image;

typedef struct s_file
{
	char	*filename;
	int		fd;
}		t_file;

typedef struct s_walls
{
	char			*no_path;
	t_image			*no_textu;
	char			*so_path;
	t_image			*so_textu;
	char			*ea_path;
	t_image			*ea_textu;
	char			*we_path;
	t_image			*we_textu;
}				t_walls;

typedef struct s_game
{
	int				scene_fd;
	int				player_count;
	int				map_start;
	char			*scene;
	struct s_player	*player;
	struct s_image	*img_map;
	struct s_image	*img_game;
	int				floor;
	int				ceiling;
	int				width;
	int				height;
	char			**map;
	double			map_tile_size;
	t_map			*maps;
	t_walls			walls;
	t_file			file;
}		t_game;

typedef struct s_player
{
	t_point		point;
	int			dtp;
	int			center;
	int			width;
	int			height;
	int			angle;
	int			mag;
	int			n_down;
	int			s_down;
	int			e_down;
	int			w_down;
	int			a_down;
	int			d_down;
}		t_player;

typedef struct s_sprite
{
	double	x;
	double	y;
	int		texture;
}				t_sprite;

typedef struct s_ray
{
	int		angle;
	double	height;
	double	dist_wall;
	int		color;
	t_point	end;
}				t_ray;

#endif
