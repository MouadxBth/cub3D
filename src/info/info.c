/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:07:20 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 19:26:02 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_info.h"
#include "cub3d_parser.h"
#include "cub3d_raycaster.h"

int	ft_game_loop(t_info *info)
{
	if (info->player.movement.escape)
		return (ft_clean_up_info(info), 0);
	ft_key_update(&info->player, &info->map);
	ft_render_info(info);
	return (0);
}

void	ft_free_texture_paths(t_map *map)
{
	if (map->north_wall_texture)
	{
		free(map->north_wall_texture);
		map->north_wall_texture = NULL;
	}
	if (map->south_wall_texture)
	{
		free(map->south_wall_texture);
		map->south_wall_texture = NULL;
	}
	if (map->west_wall_texture)
	{
		free(map->west_wall_texture);
		map->west_wall_texture = NULL;
	}
	if (map->east_wall_texture)
	{
		free(map->east_wall_texture);
		map->east_wall_texture = NULL;
	}
}

void	ft_clean_up_window(t_info *info)
{
	if (info->window.images)
	{
		ft_free_image(info->window.mlx, &info->window.images[0]);
		ft_free_image(info->window.mlx, &info->window.images[1]);
		ft_free_window(&info->window);
	}
}

void	ft_clean_up_map(t_info *info)
{
	if (info->map.width)
	{
		free(info->map.width);
		info->map.width = NULL;
	}
	if (info->map.f_lines)
	{
		fre2d(info->map.f_lines);
		info->map.f_lines = NULL;
	}
}

int	ft_clean_up_info(t_info *info)
{
	int	index;

	ft_clean_up_window(info);
	ft_clean_up_map(info);
	ft_free_texture_paths(&info->map);
	if (info->raycaster.rays)
	{
		free(info->raycaster.rays);
		info->raycaster.rays = NULL;
	}
	if (info->textures)
	{
		index = -1;
		while (++index < 4)
			free(info->textures[index].data);
		free(info->textures);
		info->textures = NULL;
	}
	if (info->window.mlx)
	{
		free(info->window.mlx);
		info->window.mlx = NULL;
	}
	return (exit(0), 0);
}
