/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_player.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:35:04 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 20:04:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PLAYER_H
# define CUB3D_PLAYER_H

# include "cub3d_map.h"
# include "cub3d_vector.h"

typedef struct s_movement
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			escape;
	float		speed;
	float		rotation_speed;
}				t_movement;

typedef struct s_player
{
	t_point		position;
	t_vector	direction;
	t_vector	plane;
	t_movement	movement;
	t_options	options;
	int			rays;
	int			dof;
	int			fov;
	float		angle;
}				t_player;

void			ft_player_coordinates(t_map *map, t_player *player);

int				ft_key_press(int key, t_movement *movement);
int				ft_key_release(int key, t_movement *movement);

void			ft_key_update(t_player *player, t_map *map);

void			ft_rotate_player(t_player *player, float speed);

#endif
