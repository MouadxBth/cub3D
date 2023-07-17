/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:53:22 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 20:10:01 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_info.h"
#include "cub3d_init.h"
#include "cub3d_parser.h"

static t_movement	ft_movement(float movement_speed, float rotation)
{
	return ((t_movement){
		.up = 0,
		.down = 0,
		.left = 0,
		.right = 0,
		.rotate_left = 0,
		.rotate_right = 0,
		.speed = movement_speed,
		.rotation_speed = rotation,
	});
}

void	ft_initialize_map(char *file, t_info *info)
{
	ft_extension_check(file, ".cub");
	ft_map(file, &info->map);
	info->map.options.color = ft_mix_color(128, 128, 128, 0);
	info->map.options.scale = 4;
	info->map.options.row_gap = 1;
	info->map.options.column_gap = 1;
	info->map.options.x_offset = 0;
	info->map.options.y_offset = 0;
	info->map.max_width = ft_max_width(&info->map);
}

void	ft_initialize_player(t_info *info)
{
	info->player.fov = 90;
	ft_player_coordinates(&info->map, &info->player);
	ft_point_scale(&info->player.position, info->map.options.scale);
	info->player.position.x += info->map.options.scale / 2;
	info->player.position.y += info->map.options.scale / 2;
	info->player.movement.speed = 1;
	info->player.movement.up = 0;
	info->player.movement.down = 0;
	info->player.movement.left = 0;
	info->player.movement.right = 0;
	info->player.options.angle = 45.0;
	info->player.options.color = ft_mix_color(255, 128, 0, 0);
	info->player.options.scale = 1;
	info->player.options.row_gap = 0;
	info->player.options.column_gap = 0;
	info->player.options.x_offset = 0;
	info->player.options.y_offset = 0;
	info->player.rays = info->window.width;
	info->player.movement = ft_movement(0.5, 1.5);
	info->player.dof = info->map.max_width * info->map.options.scale;
}

void	ft_init_ray_options(t_info *info)
{
	info->ray_options = (t_options){
		.angle = 0,
		.color = ft_mix_color(255, 255, 255, 0),
		.scale = 1,
		.row_gap = 0,
		.column_gap = 0,
		.x_offset = info->player.options.x_offset,
		.y_offset = info->player.options.y_offset};
}

void	ft_init_info_window(t_info *info)
{
	ft_new_window(&info->window, 1300, 720);
	ft_new_image(&info->window.images[0],
		info->window.mlx,
		info->window.width,
		info->window.height);
	ft_new_image(&info->window.images[1],
		info->window.mlx,
		info->window.width,
		info->window.height);
	info->current_x = 1300 / 2;
}
