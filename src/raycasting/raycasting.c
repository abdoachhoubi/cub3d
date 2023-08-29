/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:56:40 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:56:41 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// returns the correct texture
static t_image	*correct_texture(t_game *game, int i)
{
	if (i == 1)
		return (game->walls.no_textu);
	else if (i == 2)
		return (game->walls.so_textu);
	else if (i == 3)
		return (game->walls.we_textu);
	else
		return (game->walls.ea_textu);
}

// returns the color of the pixel of the texture with the shadow
static int	shade(double distance, int color, t_game *game)
{
	double	factor;
	int		div;
	int		r;
	int		g;
	int		b;

	(void)div;
	if (game->player->width < game->player->height)
		div = game->player->width;
	else
		div = game->player->height;
	factor = fabs((distance / game->player->width) - 1);
	if (factor > 1)
		factor = 1;
	r = get_r(color) * factor;
	g = get_g(color) * factor;
	b = get_b(color) * factor;
	if (r < 30)
		r = 30;
	if (g < 30)
		g = 30;
	if (b < 30)
		b = 30;
	return (gen_trgb(0, r, g, b));
}

// draws a line
static void	draw_line(t_game *game, t_ray ray, int col)
{
	int		i;
	int		x_texture_position;
	t_image	*tex;

	tex = correct_texture(game, ray.color);
	i = -1;
	if (ray.color == 1 || ray.color == 2)
		x_texture_position = (int)(floor(ray.end.x + 1)) % TILE_SIZE;
	else
		x_texture_position = (int)(floor(ray.end.y + 1)) % TILE_SIZE;
	while (++i < game->img_game->h)
	{
		if (i >= game->player->center - (ray.height / 2)
			&& i <= game->player->center + (ray.height / 2))
		{
			ray.color = texture_pixel_color(game,
					p(x_texture_position, (double)i), ray, tex);
			ray.color = shade(ray.dist_wall, ray.color, game);
			put_pixel_img(game->img_game, col, i, ray.color);
		}
		else if (i < game->player->center)
			put_pixel_img(game->img_game, col, i, game->ceiling);
		else
			put_pixel_img(game->img_game, col, i, game->floor);
	}
}

// returns the color of the wall
static int	set_wall_color(double dist, int angle, t_game *game)
{
	if (angle < 0)
		angle = r_angle(360) + angle;
	else if (angle >= r_angle(360))
		angle = angle - r_angle(360);
	if (dist == nearest_horizontal(game, angle))
	{
		if (angle < r_angle(180))
			return (1);
		else
			return (2);
	}
	else
	{
		if (angle > r_angle(90) && angle < r_angle(270))
			return (3);
		else
			return (4);
	}
}

// casts rays in the 3d game
void	raycasting3d(t_game *game)
{
	t_ray	ray;
	int		column;

	ray.angle = r_angle(30);
	column = 0;
	while (ray.angle > -r_angle(30) && column < WIN_W)
	{
		ray.dist_wall = magic_distance(game, ray.angle);
		ray.end = add_vec(game->player->point,
				vec((ray.angle + game->player->angle), ray.dist_wall));
		ray.color = set_wall_color(ray.dist_wall,
				game->player->angle + ray.angle, game);
		ray.height = ray.dist_wall * fcos(abs(ray.angle));
		ray.height = ((double)TILE_SIZE / ray.height) * game->player->dtp;
		draw_line(game, ray, column);
		column++;
		ray.angle--;
	}
}
