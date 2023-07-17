/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:06:47 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 19:15:27 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_info.h"
#include "cub3d_init.h"
#include "cub3d_parser.h"

void	ft_center_elements(t_info *info)
{
	t_point	offset;

	if (!info)
		return ;
	offset = ft_closest_point(&info->map);
	info->player.options.x_offset -= (offset.x * info->map.options.scale);
	info->player.options.y_offset -= (offset.y * info->map.options.scale);
	info->map.options.x_offset -= offset.x * info->map.options.scale;
	info->map.options.y_offset -= offset.y * info->map.options.scale;
}

void	ft_initialize_raycaster(t_info *info)
{
	int	index;

	info->raycaster.map = &info->map;
	info->raycaster.player = &info->player;
	info->raycaster.rays = (t_ray *)malloc(sizeof(t_ray) * (info->player.rays));
	if (!info->raycaster.rays)
		return ;
	index = -1;
	while (++index < info->player.rays)
	{
		info->raycaster.rays[index] = (t_ray) {
			.step_size = (t_vector) {
				.x = 0.0,
				.y = 0.0
			},
			.direction = (t_vector) {
				.x = 0.0,
				.y = 0.0
			},
			.x_length = 0,
			.y_length = 0,
			.length = 0,
			.x_map_check = 0,
			.y_map_check = 0,
			.x_step = 0,
			.y_step = 0,
			.side = 0
		};
	}

}

int	ft_initialize_textures(t_info *info)
{
	int	result;

	result = 0;
	info->textures = (t_texture *)malloc(sizeof(t_texture) * 4);
	if (!info->textures)
		return (result);
	result |= ft_load_texture(&info->textures[0], info->window.mlx,
			info->map.north_wall_texture);
	result |= ft_load_texture(&info->textures[1], info->window.mlx,
			info->map.south_wall_texture);
	result |= ft_load_texture(&info->textures[2], info->window.mlx,
			info->map.west_wall_texture);
	result |= ft_load_texture(&info->textures[3], info->window.mlx,
			info->map.east_wall_texture);
	return (result);
}

void	ft_initialize_rendering_info(t_info *info)
{
	info->rendering_info.map = &info->map;
	info->rendering_info.player = &info->player; 
}
