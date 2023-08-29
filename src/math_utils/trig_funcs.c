/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:16 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:55:17 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// reproduce cos but for a degree angle
double	fcos(int angle)
{
	static double	fcos[360 * WIN_W / 60];
	int				i;

	if (angle < r_angle(0) || angle >= r_angle(360))
		return (0.0);
	if (fcos[r_angle(0)] > 1.0)
		return (fcos[angle]);
	i = 0;
	while (i < r_angle(360))
	{
		fcos[i] = cos(i * PI / r_angle(180)) + 0.00001;
		i++;
	}
	return (fcos[angle]);
}

// reproduce sin but for a degree angle
double	fsin(int angle)
{
	static double	fsin[360 * WIN_W / 60];
	int				i;

	if (angle < r_angle(0) || angle >= r_angle(360))
		return (0.0);
	if (fsin[r_angle(90)] > 1.0)
		return (fsin[angle]);
	i = 0;
	while (i < r_angle(360))
	{
		fsin[i] = sin(i * PI / r_angle(180)) + 0.00001;
		i++;
	}
	return (fsin[angle]);
}

// reproduce tan but for a degree angle
double	ftan(int angle)
{
	static double	ftan[360 * WIN_W / 60];
	int				i;

	if (angle < r_angle(0) || angle >= r_angle(360))
		return (0.0);
	if (ftan[r_angle(45)] > 1.0)
		return (ftan[angle]);
	i = 0;
	while (i < r_angle(360))
	{
		ftan[i] = tan(i * PI / r_angle(180)) + 0.00001;
		i++;
	}
	return (ftan[angle]);
}

// returns the distance between two points
double	norm(t_game *game, int xx, int yy)
{
	return (sqrt(pow((game->player->point.x / MAP_SCALE) - (xx), 2)
			+ pow((game->player->point.y / MAP_SCALE) - (yy), 2))
		<= sqrt(game->map_tile_size));
}
