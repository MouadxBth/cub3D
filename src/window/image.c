/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:44:05 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 23:23:04 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_color.h"
#include "cub3d_window.h"

/**
 * Clears the given image by setting all its pixels to 0.
 *
 * @param img The image to clear.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 */
void	ft_clear_image(t_image *img, int width, int height)
{
	if (!img || !img->address)
		return ;
	ft_bzero(img->address, width * (height * (img->bits_per_pixel / 8)));
}

/**
 * Fills the given image with a given color.
 *
 * @param img The image to fill.
 * @param color The color to fill the image with.
 * @param width The width of the image in pixels.
 * @param height The height of the image in pixels.
 */
void	ft_fill_image(t_image *img, int color, int width, int height)
{
	int	index;

	if (!img || !img->address || !ft_is_valid_rgb(color))
		return ;
	index = -1;
	while (++index < width * height)
		((int *)img->address)[index] = color;
}

/**
 * Destroys the given image and frees its allocated memory.
 *
 * @param mlx The mlx instance to use to destroy the image.
 * @param img The image to destroy.
 */
int	ft_free_image(void *mlx, t_image *img)
{
	int	result;

	if (!mlx || !img || !img->id)
		return (1);
	result = mlx_destroy_image(mlx, img->id);
	return (result);
}

/**
 * Checks if the provided image is valid.
 *
 * @param img pointer to the image to be checked
 *
 * @return 1 if the image is valid, 0 otherwise.
 */
int	ft_is_valid_image(t_image *img)
{
	if (!img || !img->id || !img->address)
		return (0);
	return ((img->endian >= 0 && img->endian <= 1) && (img->bits_per_pixel > 0)
		&& (img->height > 0 && img->width > 0) && (img->line_length > 0));
}

/**
 * Creates a new image and populates the given t_image struct
 * with relevant information
 *
 * @param result Pointer to the t_image struct to populate
 * @param mlx Pointer to the mlx instance
 * @param width Width of the new image in pixels
 * @param height Height of the new image in pixels
 *
 * @return 1 if the image was successfully created and populated, 0 otherwise
 */
int	ft_new_image(t_image *result, void *mlx, int width, int height)
{
	if (!result || !mlx || width <= 0 || height <= 0)
		return (0);
	result->id = mlx_new_image(mlx, width, height);
	result->address = mlx_get_data_addr(result->id,
			&result->bits_per_pixel,
			&result->line_length,
			&result->endian);
	result->width = width;
	result->height = height;
	if (!ft_is_valid_image(result))
		return (0);
	return (1);
}
