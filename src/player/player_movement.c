/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:27:17 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 18:54:22 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_key_linux.h"
#include "cub3d_player.h"
#include "cub3d_raycaster.h"
#include "cub3d_renderer.h"
#include <stdio.h>

int	ft_key_press(int key, t_movement *movement)
{
	if (key == KEY_W)
		movement->up = 1;
	else if (key == KEY_S)
		movement->down = 1;
	else if (key == KEY_A)
		movement->left = 1;
	else if (key == KEY_D)
		movement->right = 1;
	else if (key == KEY_AR_L)
		movement->rotate_left = 1;
	else if (key == KEY_AR_R)
		movement->rotate_right = 1;
	else if (key == KEY_ESC)
		movement->escape = 1;
	return (0);
}

int	ft_key_release(int key, t_movement *movement)
{
	if (key == KEY_W)
		movement->up = 0;
	else if (key == KEY_S)
		movement->down = 0;
	else if (key == KEY_A)
		movement->left = 0;
	else if (key == KEY_D)
		movement->right = 0;
	else if (key == KEY_AR_L)
		movement->rotate_left = 0;
	else if (key == KEY_AR_R)
		movement->rotate_right = 0;
	else if (key == KEY_ESC)
		movement->escape = 0;
	return (0);
}

void	ft_translate_player(t_player *player, t_map *map,
float step, int strafe)
{
	float	x_speed;
	float	y_speed;

	x_speed = player->direction.x * step * player->options.scale;
	y_speed = player->direction.y * step * player->options.scale;
	if (strafe)
	{
		x_speed = ((step / 2.0) * player->options.scale) * cos(
				ft_fix_angle(player->angle + 90.0) * M_PI / 180.0);
		y_speed = ((step / 2.0) * player->options.scale) * sin(
				ft_fix_angle(player->angle + 90.0) * M_PI / 180.0);
	}
	if (!ft_check_content_raw(map, player->position.x + x_speed * 2,
			player->position.y, '1')
		&& !ft_check_content_raw(map,
			player->position.x + x_speed,
			player->position.y + y_speed, '1'))
		player->position.x += x_speed;
	if (!ft_check_content_raw(map, player->position.x,
			player->position.y + y_speed * 2, '1')
		&& !ft_check_content_raw(map, player->position.x + x_speed,
			player->position.y + y_speed, '1'))
		player->position.y += y_speed;
}

void	ft_key_update(t_player *player, t_map *map)
{
	if (!player || !map)
		return ;
	if (player->movement.up)
		ft_translate_player(player, map, player->movement.speed, 0);
	if (player->movement.down)
		ft_translate_player(player, map, -player->movement.speed, 0);
	if (player->movement.right)
		ft_translate_player(player, map, player->movement.speed, 1);
	if (player->movement.left)
		ft_translate_player(player, map, -player->movement.speed, 1);
	if (player->movement.rotate_right)
		ft_rotate_player(player, player->movement.rotation_speed);
	if (player->movement.rotate_left)
		ft_rotate_player(player, -player->movement.rotation_speed);
}
