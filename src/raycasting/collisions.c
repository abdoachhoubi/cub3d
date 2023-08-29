/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:56:18 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:56:18 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// check if point is out of bounds
static int	edge_collide(t_game *game, t_point p)
{
	if (p.x < 0 || p.y < 0 || p.x / TILE_SIZE >= game->width
		|| p.y / TILE_SIZE >= game->height)
		return (1);
	return (0);
}

// check if point is inside a wall
static int	wall_collide(t_game *game, t_point p, int angle)
{
	int	my_y;
	int	my_x;

	if (angle < r_angle(180))
		my_y = ceil((p.y)) / (TILE_SIZE);
	else
		my_y = floor((p.y)) / (TILE_SIZE);
	if (angle > r_angle(90) && angle < r_angle(270))
		my_x = ceil((p.x)) / (TILE_SIZE);
	else
		my_x = floor((p.x)) / (TILE_SIZE);
	if (game->map[my_y][my_x] == '1')
		return (1);
	return (0);
}

// check if point is out of bounds or inside a wall
int	collide(t_game *game, t_point p, int angle)
{
	return (edge_collide(game, p) || wall_collide(game, p, angle));
}
