#include "cub3d_color.h"
#include "cub3d_raycaster.h"
#include "cub3d_renderer.h"

void	ft_setup_ray_length(t_ray *ray, t_map *map, t_player *player)
{
	if (ray->direction.x < 0.0)
		ray->x_length = ((player->position.x - ray->x_map_check)
				/ map->options.scale) * ray->step_size.x;
	else
		ray->x_length = ((ray->x_map_check + map->options.scale
					- (player->position.x)) / map->options.scale)
			* ray->step_size.x;
	if (ray->direction.y < 0.0)
		ray->y_length = ((player->position.y - ray->y_map_check)
				/ map->options.scale) * ray->step_size.y;
	else
		ray->y_length = ((ray->y_map_check + map->options.scale
					- (player->position.y)) / map->options.scale)
			* ray->step_size.y;
}

void	ft_setup_ray_step(t_ray *ray)
{
	if (ray->direction.x < 0)
		ray->x_step = -1;
	else
		ray->x_step = 1;
	if (ray->direction.y < 0)
		ray->y_step = -1;
	else
		ray->y_step = 1;
}

void	ft_setup_ray(t_ray *ray, t_map *map, t_player *player,
		float camera_x)
{
	ray->x_map_check = (int)((player->position.x)
			/ map->options.scale) *map->options.scale;
	ray->y_map_check = (int)((player->position.y)
			/ map->options.scale) *(map->options.scale);
	ray->direction.x = player->direction.x + player->plane.x * camera_x;
	ray->direction.y = player->direction.y + player->plane.y * camera_x;

	if (player->direction.x == 0.0)
		player->direction.x = 0.003960;

	ray->step_size.x = fabs(1.0 / ray->direction.x) * map->options.scale;

	if (player->direction.y == 0.0)
		player->direction.y = 0.003960;

	ray->step_size.y = fabs(1.0 / ray->direction.y) * map->options.scale;
}

void	ft_step_ray(t_ray *ray, t_map *map, t_point *current)
{
	if (ray->x_length < ray->y_length)
	{
		current->x += ray->x_step * map->options.scale;
		ray->x_map_check += ray->x_step * map->options.scale;
		ray->length = ray->x_length;
		ray->x_length += ray->step_size.x;
		ray->side = 0;
		return ;
	}
	current->y += ray->y_step * map->options.scale;
	ray->y_map_check += ray->y_step * map->options.scale;
	ray->length = ray->y_length;
	ray->y_length += ray->step_size.y;
	ray->side = 1;
}
