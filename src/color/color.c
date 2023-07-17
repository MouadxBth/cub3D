/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:07:05 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 19:08:02 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"

/**
 * Mixes the given color components to create a color value.
 *
 * @param r The red component of the color value.
 * @param g The green component of the color value.
 * @param b The blue component of the color value.
 * @param a The opacity component of the color value. (DEPRACATED)
 * @return The color value created from the given color components.
 */
int	ft_mix_color(int r, int g, int b, int a)
{
	(void)a;
	if (r < 0)
		r *= -1;
	if (g < 0)
		g *= -1;
	if (b < 0)
		b *= -1;
	return (r << 16 | g << 8 | b);
}

/**
 * Calculates the percentage placement of a value
 * between a start and end point.
 *
 * @param start The starting value of the range.
 * @param end The ending value of the range.
 * @param current The value to calculate the percentage for.
 * @return The percentage placement of the given value between
 * the start and end points.
 *         Returns 1.0 if the start and end points are the same.
 */
float	ft_percentage(int start, int end, int current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

/**
 * Calculates a linear interpolation between two values based
 * on a given percentage.
 *
 * @param start The starting value of the range.
 * @param end The ending value of the range.
 * @param percentage The percentage placement between the start
 * and end points to interpolate.
 * @return The interpolated value between the start and end points
 * based on the given percentage.
 */
int	ft_lerp(int start, int end, float percentage)
{
	return ((int)(start + (end - start) * percentage));
}

int	ft_scale_color(int color, int amount)
{
	int	r;
	int	g;
	int	b;

	if (amount > 255)
		return (color);
	r = ft_get_red(color) + amount;
	g = ft_get_green(color) + amount;
	b = ft_get_blue(color) + amount;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (ft_mix_color(r, g, b, 0));
}
