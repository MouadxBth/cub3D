/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_rendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:10:34 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 19:39:52 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_info.h"
#include "cub3d_parser.h"
#include "cub3d_raycaster.h"

static int	ft_get_texture(t_ray *ray)
{
	if (ray->side)
	{
		if (ray->direction.y >= 0.0)
			return (1); // south
		return (0); // north
	}
	if (ray->direction.x >= 0.0)
		return (3); // east
	return (2); // west
}

static void	ft_render_walls_and_rays(t_info *info)
{
	int	index;

	index = -1;
	while (++index < info->player.rays)
	{
		info->rendering_info.wall.texture = &info->textures[
			ft_get_texture(&info->raycaster.rays[index])];
		info->rendering_info.wall.index = index;
		info->rendering_info.wall.ray = &info->raycaster.rays[index];

		ft_render_ray(&info->rendering_info,
			&info->raycaster.rays[index],
			&info->ray_options,
			2 * index / (float)info->player.rays - 1);

		ft_render_wall(&info->rendering_info);
	}
}

void	ft_render_info(t_info *info)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	if (!info)
		return ;
	info->window.current_img = !info->window.current_img;
	if (!info->window.images)
		return ;
	mlx_mouse_get_pos(info->window.mlx, info->window.id, &x, &y);
	info->rendering_info.img = &info->window.images[info->window.current_img];
	ft_raycast(&info->raycaster);
	ft_render_floor_ceiling(&info->window.images[info->window.current_img],
		&info->map);
	ft_render_walls_and_rays(info);
	ft_render_map(&info->window.images[info->window.current_img],
		&info->map);
	ft_render_player(&info->window.images[info->window.current_img],
		&info->player);
	mlx_put_image_to_window(info->window.mlx,
		info->window.id,
		info->window.images[info->window.current_img].id,
		0,
		0);
	ft_clear_image(&(info->window.images[!info->window.current_img]),
		info->window.width,
		info->window.height);
}

int	ft_mouse(int x, int y, t_info *info)
{
	(void) y;
	mlx_mouse_hide(info->window.mlx, info->window.id);
	while (info->current_x++ < x)
		ft_rotate_player(&info->player, info->player.movement.rotation_speed);
	while (info->current_x-- > x)
		ft_rotate_player(&info->player, -info->player.movement.rotation_speed);
	return (0);
}

void	ft_start(t_info *info)
{
	mlx_loop_hook(info->window.mlx, &ft_game_loop, info);
	
	mlx_hook(info->window.id, 2, 1L << 0, &ft_key_press,
		&info->player.movement);
	mlx_hook(info->window.id, 3, 1L << 1, &ft_key_release,
		&info->player.movement);
	mlx_hook(info->window.id, 6, 1L << 6, ft_mouse, info);

	mlx_hook(info->window.id, 17, 0, ft_clean_up_info, info);
	mlx_loop(info->window.mlx);
}
