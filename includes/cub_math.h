/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:10:18 by aanouari          #+#    #+#             */
/*   Updated: 2023/08/26 18:10:19 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_MATH_H
# define CUB_MATH_H

# include <math.h>

# define PI 3.14159265

// point struct, it has the x and y coordinates
typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

// vector struct, it has the angle and the magnitude
typedef struct s_vector
{
	int		angle;
	double	mag;
}	t_vector;

// refactored math functions to use degrees instead of radians
double		fcos(int angle);
double		fsin(int angle);
double		ftan(int angle);
t_point		p(double x, double y);
t_point		add_point(t_point p1, t_point p2);
t_vector	vec(int angle, double mag);
t_point		add_vec(t_point p, t_vector v);
t_point		vertical_step(int a);
t_point		horizontal_step(int a);

#endif
