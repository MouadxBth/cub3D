/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:27:48 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 19:01:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_map.h"

static void	ft_print_coordinates(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width[y])
			printf("(%d,%d) ", x, y);
		printf("\n");
	}
}

void	ft_print_point(t_point *point)
{
	if (!point)
		return ;
	printf("x: %f\ny: %f\ncontent: %d\n", point->x, point->y, point->content);
}

void	ft_print_map(t_map *map)
{
	int	y;
	int	x;

	if (!map)
		return ;
	printf("North wall texture: %s\nSouth wall texture: %s\n\
East wall texture:%s\nWest wall texture : %s\n\
Floor color : % d, % d, % d\nCeiling color : % d, % d, % d\n",
		map->north_wall_texture, map->south_wall_texture,
		map->west_wall_texture, map->east_wall_texture,
		map->floor_color[0], map->floor_color[1], map->floor_color[2],
		map->ceiling_color[0], map->ceiling_color[1], map->ceiling_color[2]);
	if (!map->matrix)
		return ;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width[y])
			printf("%c", map->matrix[y][x]);
		printf("\n");
	}
	printf("\n\n");
	ft_print_coordinates(map);
}

t_point	ft_closest_point(t_map *map)
{
	int		y;
	int		x;
	t_point	result;

	result = (t_point){
		.x = INT_MAX,
		.y = INT_MAX,
		.content = '\0'};
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width[y])
		{
			if (map->matrix[y][x] == '1')
			{
				if (x < result.x || result.x == INT_MAX)
					result.x = x;
				if (y < result.y || result.y == INT_MAX)
					result.y = y;
			}
		}
	}
	return (result);
}

void	ft_point_scale(t_point *point, int scale)
{
	if (!point)
		return ;
	if (scale < 0)
	{
		point->x /= -scale;
		point->y /= -scale;
		return ;
	}
	point->x *= scale;
	point->y *= scale;
}
