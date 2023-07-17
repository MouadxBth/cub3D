/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:08:30 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 08:56:54 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_color.h"
#include "cub3d_renderer.h"
#include "cub3d_window.h"

/**
 * Renders a scaled point (square) of a given color, size,
 * vertical and horizontal gaps and offsets, starting from the
 * provided point onto an image.
 *
 * If NULL or invalid, default options with white color, no scaling, no gaps,
 * and no offset are used.
 *
 * @param img The image to render the point onto.
 * @param point The center point of the square to render.
 * @param options Optional rendering options to modify the color
 * and size of the square.
 *
 *
 * @return void
 */
void	ft_render_point(t_image *img, t_point *point, t_options *options)
{
	t_point	end;
	t_point	current;

	if (!img || !point)
		return ;
	end.x = (point->x + options->scale) - options->column_gap;
	end.y = (point->y + options->scale) - options->row_gap;
	current.y = point->y - 1 + options->y_offset;
	while (++current.y < end.y + options->y_offset)
	{
		current.x = point->x - 1 + options->x_offset;
		while (++current.x < end.x + options->x_offset)
			ft_draw_point_light(img, &current, options->color);
	}
}

void	ft_draw_line(t_image *img, t_point *start, t_point *end,
		t_options *options)
{
	t_point	current;

	current = *start;
	while (!ft_collision(&current, end))
	{
		if ((end->x - start->x) != 0.0)
			current.x += 1;
		if ((end->y - start->y) != 0.0)
			current.y += 1;
		ft_draw_point_light(img, &current, options->color);
	}
}

/**
 * Renders a vector on the given image using the
 * Bresenham's line algorithm.
 *
 * This function iterates over the vector using
 * Bresenham's line algorithm.
 *
 * It renders the current point if it falls within the
 * image bounds and breaks the loop if the current point is
 * the end point of the vector.
 *
 * It calculates the error using the delta values of
 * the vector and updates the current point and error value based
 * on the x direction and the y direction.
 *
 * This process is repeated until the end point is reached,
 * and the entire vector is rendered on the image.
 *
 * @param img The image to render the vector on.
 * @param vector The vector to render.
 *
 * @return void
 */
void	ft_render_vector(t_image *img, t_bresenham_vector *vector,
		t_options *options)
{
	int		error;
	t_point	current;

	if (!img || !vector)
		return ;
	current.x = vector->start.x;
	current.y = vector->start.y;
	while (current.x != vector->end.x || current.y != vector->end.y)
	{
		if (ft_is_point_in_image(&current, img))
			ft_render_point(img, &current, options);
		if (current.x == vector->end.x && current.y == vector->end.y)
			break ;
		error = vector->delta.content * 2;
		if (error >= vector->delta.y)
		{
			vector->delta.content += vector->delta.y;
			current.x += vector->x_direction;
		}
		if (error <= vector->delta.x)
		{
			vector->delta.content += vector->delta.x;
			current.y += vector->y_direction;
		}
	}
}

void	ft_render_player(t_image *img, t_player *player)
{
	t_point	current;

	if (!img || !player)
		return ;
	current = player->position;
	current.x = (int)current.x;
	current.y = (int)current.y;
	ft_render_point(img, &current, &player->options);
}

/**
 * Renders the given map onto the given image with the given options,
 * scaling each point.
 *
 * @param img The image to render the map onto.
 * @param map The map to render.
 * @param options The options to use for rendering the map.
 *
 * @return void.
 */
void	ft_render_map(t_image *img, t_map *map)
{
	int		y;
	int		x;
	t_point	current;

	if (!img || !map)
		return ;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width[y])
		{
			current.x = x * map->options.scale;
			current.y = y * map->options.scale;
			current.content = map->matrix[y][x];
			if (current.content == '1')
				ft_render_point(img, &current, &map->options);
		}
	}
}
