/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:55:39 by aachhoub          #+#    #+#             */
/*   Updated: 2023/08/26 17:55:51 by aachhoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// generate transparant rgb
int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (-1);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

// get opacity
int	get_opacity(int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

// get red
int	get_r(int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

// get green
int	get_g(int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

// get blue
int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
