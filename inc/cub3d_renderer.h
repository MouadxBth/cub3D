/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_renderer.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:42:04 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 09:59:50 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDERER_H
# define CUB3D_RENDERER_H

# include "cub3d_map.h"
# include "cub3d_options.h"
# include "cub3d_player.h"
# include "cub3d_raycaster.h"
# include "cub3d_texture.h"
# include "cub3d_window.h"

typedef struct s_bresenham_point
{
	int					x;
	int					y;
	int					content;
}						t_bresenham_point;

typedef struct s_bresenham_vector
{
	t_bresenham_point	start;
	t_bresenham_point	end;
	t_bresenham_point	delta;
	int					x_direction;
	int					y_direction;
}						t_bresenham_vector;

typedef struct s_wall
{
	t_ray				*ray;
	t_texture			*texture;
	float				distance;
	float				wall_x;
	int					index;
	int					texture_x;
	int					line_height;
	int					vertical_start;
	int					vertical_end;
	float				step;
	float				texture_position;
	int					texture_y;
	int					color;
}						t_wall;

typedef struct s_rendering_info
{
	t_image				*img;
	t_player			*player;
	t_map				*map;
	t_wall				wall;
}						t_rendering_info;

float					ft_fix_angle(float angle);

void					ft_draw_point_light(t_image *img, t_point *point,
							int color);

int						ft_is_valid_options(t_options *options);

void					ft_process_vector(t_bresenham_vector *vector);

void					ft_draw_point(t_image *img, t_point *point, int color);

void					ft_render_point(t_image *img, t_point *point,
							t_options *options);

void					ft_render_vector(t_image *img,
							t_bresenham_vector *vector,
							t_options *options);

void					ft_draw_line(t_image *img, t_point *start, t_point *end,
							t_options *options);

void					ft_render_player(t_image *img, t_player *player);

void					ft_render_map(t_image *img, t_map *map);

void					ft_render_ray(t_rendering_info *info, t_ray *ray,
							t_options *options, float camera_x);

void					ft_render_wall(t_rendering_info *info);

void					ft_draw_point_elight(t_image *img, t_point *point,
							int color);

void					ft_render_floor_ceiling(t_image *img, t_map *map);

#endif
