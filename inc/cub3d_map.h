/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:15:06 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 19:02:21 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MAP_H
# define CUB3D_MAP_H

# include "cub3d_options.h"

typedef struct s_point
{
	double		x;
	double		y;
	int			content;
}				t_point;

typedef struct s_map
{
	char		*north_wall_texture;
	char		*south_wall_texture;
	char		*west_wall_texture;
	char		*east_wall_texture;

	int			floor_color[3];
	int			ceiling_color[3];

	int			height;
	int			*width;
	int			max_width;

	char		**matrix;
	char		**f_lines;
	t_options	options;
}				t_map;

void			ft_print_map(t_map *map);

void			ft_print_point(t_point *point);

void			ft_point_scale(t_point *point, int scale);

t_point			ft_closest_point(t_map *map);

int				ft_check_content(t_map *map, t_point *point);

int				ft_check_content_raw(t_map *map, float x, float y, int content);

int				ft_max_width(t_map *map);

#endif
