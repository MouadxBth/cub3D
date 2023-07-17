/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:26:03 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 19:02:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_map.h"
#include <math.h>
#include <stdio.h>

int	ft_check_content_raw(t_map *map, float x, float y, int content)
{
	if ((y / map->options.scale) < 0 
		|| (y / map->options.scale) >= map->height 
		|| (x / map->options.scale) < 0
		|| (x / map->options.scale) >= map->width[(int)(y / map->options.scale)])
		return (-1);
	return (map->matrix[(int)(y / map->options.scale)][(int)(x / map->options.scale)] 
		== content);
}

int	ft_check_content(t_map *map, t_point *point)
{
	if ((point->y / map->options.scale) < 0 
		|| (point->y / map->options.scale) >= map->height 
		|| (point->x / map->options.scale) < 0
		|| (point->x / map->options.scale) >= map->width[(int)(point->y / map->options.scale)])
		return (-1);
	return (map->matrix[(int)(point->y / map->options.scale)][(int)(point->x / map->options.scale)] 
		== point->content);
}

int	ft_max_width(t_map *map)
{
	int	index;
	int	result;

	result = 0;
	index = -1;
	while (++index < map->height)
	{
		if (map->width[index] > result)
			result = map->width[index];
	}
	return (result);
}
