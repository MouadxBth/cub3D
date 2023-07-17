/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:13:04 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 23:53:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_raycaster.h"
#include "cub3d_renderer.h"



void	ft_print_ray(t_ray *ray)
{
	 printf("step_size: (%f, %f)\n"
           "direction: (%f, %f)\n"
           "x_length: %f\n"
           "y_length: %f\n"
           "length: %f\n"
           "x_map_check: %d\n"
           "y_map_check: %d\n"
           "x_step: %d\n"
           "y_step: %d\n"
           "side: %d\n",
           ray->step_size.x, ray->step_size.y,
           ray->direction.x, ray->direction.y,
           ray->x_length, ray->y_length, ray->length,
           ray->x_map_check, ray->y_map_check, ray->x_step, ray->y_step,
           ray->side);
}

void	ft_print_raycaster(t_raycaster *raycaster)
{
	int	index = -1;

	while (++index < raycaster->player->rays)
		ft_print_ray(&raycaster->rays[index]);
	printf("\n");

	//ft_print_player(raycaster->player);
}

void	ft_raycast_single(t_raycaster *raycaster, int index)
{
	t_point	current;
	int		current_dof;
	float	camera_x;

	camera_x = 2 * index / (float)raycaster->player->rays - 1;
	ft_setup_ray(&raycaster->rays[index], raycaster->map, raycaster->player,
		camera_x);
	ft_setup_ray_step(&raycaster->rays[index]);
	ft_setup_ray_length(&raycaster->rays[index], raycaster->map,
		raycaster->player);
	current.x = raycaster->rays[index].x_map_check;
	current.y = raycaster->rays[index].y_map_check;
	current.content = '1';
	current_dof = -1;
	raycaster->rays[index].length = 0.0;
	while (++current_dof < raycaster->player->dof
		&& !ft_check_content(raycaster->map, &current))
		ft_step_ray(&raycaster->rays[index], raycaster->map, &current);
}

void	ft_raycast(t_raycaster *raycaster)
{
	int	index;

	if (!raycaster->rays)
		return ;
	index = -1;
	while (++index < raycaster->player->rays)
		ft_raycast_single(raycaster, index);

	//ft_print_raycaster(raycaster);
}
