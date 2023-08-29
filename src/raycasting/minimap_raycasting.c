/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:56:23 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:56:24 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// choose colors for minimap
static int	choose_color(t_game *game, char c)
{
	(void)game;
	if (c == '0' || ft_strchr("NSWE", c))
		return (gen_trgb(10, 237, 255, 237));
	else if (c == '1')
		return (gen_trgb(10, 255, 0, 0));
	else
		return (gen_trgb(10, 0, 0, 0));
}

// returns the x position of the minimap
static int	minimap_xs(t_game *game)
{
	int	xs;

	xs = 0;
	if (game->player->width < game->img_map->w)
		return (0);
	if ((game->player->point.x / MAP_SCALE) + (game->img_map->w / 2)
		< game->width * game->map_tile_size)
		xs = (game->player->point.x / MAP_SCALE) - (game->img_map->w / 2);
	else
		xs = (game->width * game->map_tile_size) - game->img_map->w;
	if ((game->player->point.x / MAP_SCALE) < (game->img_map->w / 2))
		xs = 0;
	return (xs);
}

// returns the y position of the minimap
static int	minimap_ys(t_game *game)
{
	int	ys;

	ys = 0;
	if (game->player->height < game->img_map->h)
		return (0);
	if ((game->player->point.y / MAP_SCALE) + (game->img_map->h / 2)
		< game->height * game->map_tile_size)
		ys = (game->player->point.y / MAP_SCALE) - (game->img_map->h / 2);
	else
		ys = (game->height * game->map_tile_size) - game->img_map->h;
	if ((game->player->point.y / MAP_SCALE) < (game->img_map->h / 2))
		ys = 0;
	return (ys);
}

// casts rays in the minimap
static void	minimap_ray_cast(t_game *game)
{
	int		m;
	int		a;
	int		xx;
	int		yy;
	t_point	point;

	a = r_angle(30);
	while (a >= -r_angle(30))
	{
		m = magic_distance(game, a) / MAP_SCALE;
		while (--m > 2)
		{
			point = add_vec(p(game->player->point.x / MAP_SCALE,
						game->player->point.y / MAP_SCALE),
					vec(game->player->angle + a, m));
			xx = point.x - minimap_xs(game);
			yy = point.y - minimap_ys(game);
			if (xx > 0 && yy > 0 && xx
				< game->img_map->w && yy < game->img_map->h)
				put_pixel_img(game->img_map, xx, yy, gen_trgb(0, 130, 240, 66));
		}
		a--;
	}
}

// paints the minimap
void	paint_map(t_game *game)
{
	int	x;
	int	y;
	int	xs;
	int	ys;
	int	color;

	xs = minimap_xs(game);
	ys = minimap_ys(game);
	y = -1;
	while (++y < game->img_map->h && y / game->map_tile_size
		< game->height && y + ys < game->height * game->map_tile_size)
	{
		x = -1;
		while (++x < game->img_map->w && x / game->map_tile_size
			< game->width && x + xs < game->width * game->map_tile_size)
		{
			color = choose_color(game, game->map[(int)((y + ys)
						/ game->map_tile_size)]
				[(int)((x + xs) / game->map_tile_size)]);
			put_pixel_img(game->img_map, x, y, color);
			if (norm(game, x + xs, y + ys))
				put_pixel_img(game->img_map, x, y, gen_trgb(0, 240, 30, 100));
		}
	}
	minimap_ray_cast(game);
}
