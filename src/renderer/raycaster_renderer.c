/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_renderer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:50:01 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/27 13:06:08 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_color.h"
#include "cub3d_renderer.h"
#include "cub3d_window.h"

void	ft_render_ray(t_rendering_info *info, t_ray *ray, t_options *options,
		float camera_x)
{
	t_bresenham_vector	line;

	line.start.x = info->player->position.x;
	line.start.y = info->player->position.y;
	line.end.x = line.start.x + (info->player->direction.x + camera_x
			* info->player->plane.x) * (ray->length);
	line.end.y = line.start.y + (info->player->direction.y + camera_x
			* info->player->plane.y) * (ray->length);
	ft_process_vector(&line);
	ft_render_vector(info->img, &line, options);
}

void	ft_prepare_wall(t_rendering_info *info, t_wall *wall)
{
	if (wall->ray->side == 0)
		wall->distance = (wall->ray->x_length - wall->ray->step_size.x)
			/ info->map->options.scale;
	else
		wall->distance = (wall->ray->y_length - wall->ray->step_size.y)
			/ info->map->options.scale;
	wall->line_height = (int)(info->img->height / wall->distance);
	wall->vertical_start = info->img->height / 2 - wall->line_height / 2;
	if (wall->vertical_start < 0)
		wall->vertical_start = 0;
	wall->vertical_end = wall->line_height / 2 + info->img->height / 2;
	if (wall->vertical_end >= info->img->height)
		wall->vertical_end = info->img->height - 1;
	if (wall->ray->side == 0)
		wall->wall_x = (info->player->position.y / info->map->options.scale)
			+ wall->distance * wall->ray->direction.y;
	else
		wall->wall_x = (info->player->position.x / info->map->options.scale)
			+ wall->distance * wall->ray->direction.x;
	wall->wall_x -= floor(wall->wall_x);
	wall->texture_x = (int)((wall->wall_x * (double)wall->texture->width));
	/*if (wall->ray->side == 0 && wall->ray->direction.x > 0.0)
		wall->texture_x = wall->texture->width - wall->texture_x - 1;
	if (wall->ray->side == 1 && wall->ray->direction.y < 0.0)
		wall->texture_x = wall->texture->width - wall->texture_x - 1;*/
}

void	ft_render_wall(t_rendering_info *info)
{
	t_point	current;

	ft_prepare_wall(info, &info->wall);
	info->wall.step = 1.0 * info->wall.texture->height
		/ info->wall.line_height;
	info->wall.texture_position = (info->wall.vertical_start
			- info->img->height / 2 + info->wall.line_height / 2)
		* info->wall.step;
	info->wall.texture_position += info->wall.step;
	current.x = info->wall.index;
	current.y = info->wall.vertical_start;
	current.content = '0';
	while (current.y < info->wall.vertical_end)
	{
		info->wall.texture_y = (int)info->wall.texture_position
			& (info->wall.texture->height - 1);
		info->wall.texture_position += info->wall.step;
		info->wall.color = info->wall.texture->data[info->wall.texture->height
			* info->wall.texture_y + info->wall.texture_x];
		if (info->wall.ray->side == 1)
			info->wall.color = (info->wall.color >> 1) & 0x7F7F7F;
		ft_draw_point_light(info->img, &current, info->wall.color);
		current.y++;
	}
}

void	ft_render_floor_ceiling(t_image *img, t_map *map)
{
	int		x;
	int		y;
	t_point	current;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			current.x = x;
			current.y = y;
			ft_draw_point_light(img, &current, ft_mix_color(map->floor_color[0],
					map->floor_color[1], map->floor_color[2], 0));
			current.y = img->height - y - 1;
			ft_draw_point_light(img, &current,
				ft_mix_color(map->ceiling_color[0], map->ceiling_color[1],
					map->ceiling_color[2], 0));
		}
	}
}
