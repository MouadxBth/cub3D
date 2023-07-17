/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:21:01 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 23:39:59 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_renderer.h"
#include <stdlib.h>

float	ft_fix_angle(float angle)
{
	if (angle > 360.0)
		return (angle - 360.0);
	if (angle < 0.0)
		return (360.0 + angle);
	return (angle);
}

void	ft_process_vector(t_bresenham_vector *vector)
{
	if (!vector)
		return ;
	vector->delta.x = abs((int)(vector->end.x - vector->start.x));
	vector->delta.y = -abs((int)(vector->end.y - vector->start.y));
	vector->delta.content = vector->delta.x + vector->delta.y;
	if (vector->end.x > vector->start.x)
		vector->x_direction = 1;
	else
		vector->x_direction = -1;
	if (vector->end.y > vector->start.y)
		vector->y_direction = 1;
	else
		vector->y_direction = -1;
}
