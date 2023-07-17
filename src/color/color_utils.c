/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:06:50 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/22 19:25:02 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"

/**
 * Returns the red component of the given color value.
 *
 * @param color The color value to extract the red component from.
 * @return The red component of the given color value.
 */
int	ft_get_red(int color)
{
	return ((color >> 16) & 0xff);
}

/**
 * Returns the green component of the given color value.
 *
 * @param color The color value to extract the green component from.
 * @return The green component of the given color value.
 */
int	ft_get_green(int color)
{
	return ((color >> 8) & 0xff);
}

/**
 * Returns the blue component of the given color value.
 *
 * @param color The color value to extract the blue component from.
 * @return The blue component of the given color value.
 */
int	ft_get_blue(int color)
{
	return (color & 0xff);
}

/**
 * Returns the opacity/alpha component of the given color value.
 *
 * @param color The color value to extract the opacity component from.
 * @return The opacity component of the given color value.
 */
int	ft_get_opacity(int color)
{
	return ((color >> 24) & 0xff);
}

/**
 * Determines if the given color value is a valid RGB color.
 *
 * @param color The color value to check.
 * @return 1 if the color is a valid RGB color, 0 otherwise.
 */
int	ft_is_valid_rgb(int color)
{
	return ((ft_get_red(color) >= 0 && ft_get_red(color) <= 255)
		&& (ft_get_green(color) >= 0 && ft_get_green(color) <= 255)
		&& (ft_get_blue(color) >= 0 && ft_get_blue(color) <= 255));
}
