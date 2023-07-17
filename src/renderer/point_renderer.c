/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 23:38:57 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 23:40:31 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_renderer.h"
#include <stdlib.h>

/**
 * Check if given options are valid.
 *
 * @param options Pointer to the options to be validated
 * @return 1 if the options are valid, 0 otherwise.
 */
int	ft_is_valid_options(t_options *options)
{
	return (options && ft_is_valid_rgb(options->color) && options->scale >= 0
		&& options->row_gap >= 0 && options->column_gap >= 0);
}

/**
 * Draws a point of a specified color on the given image
 * at the given point coordinates.
 *
 * Calculate the step size in bytes, since the pixels data is
 * stored each one next to the other, we need to figure out how
 * many bytes the pixel occupies to get the target pixel memory address.
 *
 * Then, we calculate the index of the pixel in the image where the point
 * will be rendered, all we need is to calculate the vertical offset
 * which can be done by multiplying the target point's y by the number of
 * lines the image has, and add the target point's x offset calculated before.
 *
 * Finally, we set the color of the pixel at the calculated index based
 * on the endianness of @param img.
 *
 * @param img The image to draw on
 * @param point The point to draw on the image
 * @param color The color to draw the point in
 *
 * @return void
 */
void	ft_draw_point(t_image *img, t_point *point, int color)
{
	int	index;
	int	step;
	int	current;

	if (!img || !point || !ft_is_point_in_image(point, img))
		return ;
	step = img->bits_per_pixel / 8;
	index = (((int)point->y) * img->line_length + ((int)point->x) * step);
	current = -1;
	while (++current < step)
	{
		if (img->endian)
			img->address[index++] = color >> (((step - 1) * 8) - 8
					* current) & 0xFF;
		else
			img->address[index++] = color >> (8 * current) & 0xFF;
	}
}

static int	ft_reverse_bits(int b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return (b);
}

void	ft_draw_point_light(t_image *img, t_point *point, int color)
{
	int	step;
	int	index;

	if (!ft_is_point_in_image(point, img))
		return ;
	step = img->bits_per_pixel / 8;
	index = (((int)point->y) * img->line_length + ((int)point->x) * step);
	if (img->endian)
		color = ft_reverse_bits(color);
	img->address[index++] = color >> 0 & 0xFF;
	img->address[index++] = color >> 8 & 0xFF;
	img->address[index++] = color >> 16 & 0xFF;
}

void	ft_draw_point_elight(t_image *img, t_point *point, int color)
{
	int	step;
	int	index;

	if (!ft_is_point_in_image(point, img))
		return ;
	step = img->bits_per_pixel / 8;
	index = (((int)point->y) * img->line_length + ((int)point->x) * step);
	img->address[index++] = color;
}
