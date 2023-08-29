/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:56:47 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:56:48 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// get horizontal step
double	nearest_horizontal(t_game *game, int a)
{
	t_point	intersection;
	t_point	p_const;

	if (a < r_angle(180))
		intersection.y = floor(game->player->point.y
				/ TILE_SIZE) * TILE_SIZE - 1;
	else
		intersection.y = floor(game->player->point.y
				/ TILE_SIZE) * TILE_SIZE + TILE_SIZE;
	intersection.x = game->player->point.x
		+ (game->player->point.y - intersection.y) / ftan(a);
	p_const = horizontal_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	if (intersection.x < 0 || intersection.y < 0 || intersection.x / TILE_SIZE
		> game->width || intersection.y / TILE_SIZE > game->height)
		return (INT_MAX);
	return (fabs(fabs(game->player->point.y - intersection.y) / fsin(a)));
}

// get vertical step
double	nearest_vertical(t_game *game, int a)
{
	t_point	intersection;
	t_point	p_const;

	if (a > r_angle(90) && a < r_angle(270))
		intersection.x = floor(game->player->point.x
				/ TILE_SIZE) * (TILE_SIZE) - 1;
	else
		intersection.x = floor(game->player->point.x / TILE_SIZE)
			* TILE_SIZE + TILE_SIZE;
	intersection.y = game->player->point.y
		+ ((game->player->point.x - intersection.x) * ftan(a));
	p_const = vertical_step(a);
	while (!collide(game, intersection, a))
		intersection = add_point(intersection, p_const);
	if (intersection.x < 0 || intersection.y < 0 || intersection.x / TILE_SIZE
		> game->width || intersection.y / TILE_SIZE > game->height)
		return (INT_MAX);
	return (fabs(fabs(game->player->point.x - intersection.x) / fcos(a)));
}

// get the nearest wall
double	magic_distance(t_game *game, int ray_angle)
{
	int		a;
	double	ph;
	double	pv;

	a = game->player->angle + ray_angle;
	if (a < 0)
		a = r_angle(360) + a;
	if (a >= r_angle(360))
		a = a - r_angle(360);
	ph = nearest_horizontal(game, a);
	pv = nearest_vertical(game, a);
	if (ph < pv)
		return (ph);
	else
		return (pv);
}
