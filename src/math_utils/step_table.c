/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:08 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:55:09 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// casts rays and tracks the horizontal grid lines intersections
t_point	horizontal_step(int a)
{
	static t_point	h_step[360 * WIN_W / 60];
	int				i;

	if (h_step[0].x > 0 || h_step[0].y > 0)
		return (h_step[a]);
	i = 0;
	while (i < (int)r_angle(360))
	{
		if (i < (int)r_angle(180))
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE * -1);
		else
			h_step[i] = p(fabs(TILE_SIZE / ftan(i)), TILE_SIZE);
		if (i > r_angle(90) && i < r_angle(270))
			h_step[i].x *= -1;
		i++;
	}
	return (h_step[a]);
}

// casts rays and tracks the vertical grid lines intersections
t_point	vertical_step(int a)
{
	static t_point	v_step[360 * WIN_W / 60];
	int				i;

	if (v_step[0].x > 0 || v_step[0].y > 0)
		return (v_step[a]);
	i = 0;
	while (i < r_angle(360))
	{
		if (i < r_angle(180))
			v_step[i] = p(TILE_SIZE, fabs(TILE_SIZE * ftan(i)) * -1);
		else
			v_step[i] = p(TILE_SIZE, fabs(TILE_SIZE * ftan(i)));
		if (i > r_angle(90) && i < r_angle(270))
			v_step[i].x *= -1;
		i++;
	}
	return (v_step[a]);
}
