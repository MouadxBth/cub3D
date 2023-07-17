/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:43:06 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 20:08:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_player.h"
#include "cub3d_renderer.h"

static int	ft_is_direction(int c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

float	ft_angle(int c)
{
	if (c == 'N')
		return (270.0);
	else if (c == 'E')
		return (0.0);
	else if (c == 'S')
		return (90.0);
	else if (c == 'W')
		return (180.0);
	return (45.0);
}

void	ft_rotate_player(t_player *player, float speed)
{
	player->angle = ft_fix_angle(player->angle + speed);
	ft_vector_rotate(&player->direction, speed);
	ft_vector_rotate(&player->plane, speed);
}

static void	ft_initialize_plane(t_player *player)
{
	float	length;
	float	plane_length;

    player->plane.x = -player->direction.y;
	player->plane.y = player->direction.x;
	length = sqrt((player->plane.x) * (player->plane.x) 
		+ (player->plane.y) * (player->plane.y));

    plane_length = tan((player->fov * M_PI / 180.0) / 2.0);

	player->plane.x = (player->plane.x) / length * plane_length;
    player->plane.y = (player->plane.y) / length * plane_length;
}

static void	ft_set_angle(t_player *player, int c)
{
	player->angle = ft_angle(c);
	player->direction.x = cos(player->angle * M_PI / 180.0);
	player->direction.y = sin(player->angle * M_PI / 180.0);
	ft_initialize_plane(player);
}

void	ft_player_coordinates(t_map *map, t_player *player)
{
	t_point	position;
	char	current;

	if (!map || !player)
		return ;
	position = (t_point){
		.x = -1,
		.y = -1,
		.content = 0
	};
	while (++(position.y) < map->height)
	{
		position.x = -1;
		while (++(position.x) < map->width[(int)position.y])
		{
			current = map->matrix[(int)position.y][(int)position.x];
			if (ft_is_direction(current))
			{
				position.content = current;
				player->position = position;
				ft_set_angle(player, current);
				return ;
			}
		}
	}
}
