/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:00 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:55:03 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

// convert angle from degrees to radians
int	r_angle(int angle)
{
	if (angle == 0)
		return (0);
	return ((angle * WIN_W) / 60);
}
