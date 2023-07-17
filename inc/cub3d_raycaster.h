/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycaster.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:11:46 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 22:47:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RAYCASTER_H
# define CUB3D_RAYCASTER_H

# include "cub3d_map.h"
# include "cub3d_player.h"

typedef struct s_ray
{
	t_vector	step_size;
	t_vector	direction;
	float		x_length;
	float		y_length;
	float		length;
	int			x_map_check;
	int			y_map_check;
	int			x_step;
	int			y_step;
	int			side;
}	t_ray;

typedef struct s_raycaster
{
	t_map		*map;
	t_player	*player;
	t_ray		*rays;
}	t_raycaster;

void	ft_raycast_single(t_raycaster *raycaster, int current);

void	ft_raycast(t_raycaster *raycaster);

void	ft_setup_ray_length(t_ray *ray, t_map *map, t_player *player);

void	ft_setup_ray_step(t_ray *ray);

void	ft_setup_ray(t_ray *ray, t_map *map, t_player *player,
		float camera_x);

void	ft_step_ray(t_ray *ray, t_map *map, t_point *current);

#endif
