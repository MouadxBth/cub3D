/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:43:48 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 23:23:09 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_window.h"

/**
 * Check if the given point is within the window bounds.
 *
 * @param point: A pointer to a t_point structure that represents
 * the point to check.
 * @param width: An integer value representing the width of the window.
 * @param height: An integer value representing the height of the window.
 *
 * @return 1 if the point is within the window bounds, otherwise 0.
 *
*/
int	ft_is_point_in_image(t_point *point, t_image *img)
{
	return ((point->x > 0 && point->x < img->width)
		&& (point->y > 0 && point->y < img->height));
}

/**
 * Check if the two given points collide (have the same coordinates).
 *
 * @param first: A pointer to a t_point structure representing the first point.
 * @param second: A pointer to a t_point structure representing the second point.
 *
 * @return 1 if the points collide, otherwise 0.
*/
int	ft_collision(t_point *first, t_point *second)
{
	if (!first || !second)
		return (0);
	return (first->x == second->x && first->y == second->y);
}

int	ft_load_image(t_image *result, void *mlx, char *path)
{
	if (!result || !mlx || !path)
		return (0);
	result->id = mlx_xpm_file_to_image(mlx, path,
			&result->width, 
			&result->height);
	if (!result->id)
		return (0);
	result->address = mlx_get_data_addr(result->id,
			&result->bits_per_pixel,
			&result->line_length,
			&result->endian);
	if (!ft_is_valid_image(result))
		return (mlx_destroy_image(mlx, result->id), 0);
	return (1);
}
