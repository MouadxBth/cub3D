/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_info.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 23:34:05 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/26 19:14:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INFO_H
# define CUB3D_INFO_H

# include "cub3d.h"
# include "cub3d_map.h"
# include "cub3d_player.h"
# include "cub3d_raycaster.h"
# include "cub3d_renderer.h"
# include "cub3d_texture.h"
# include "cub3d_window.h"

typedef struct s_info
{
	t_window			window;
	t_player			player;
	t_map				map;
	t_options			ray_options;
	t_raycaster			raycaster;
	t_texture			*textures;
	t_rendering_info	rendering_info;
	int	current_x;
}						t_info;

void					ft_start(t_info *info);

int						ft_game_loop(t_info *info);

void					ft_render_info(t_info *info);

int						ft_clean_up_info(t_info *info);

void					ft_initialize_rendering_info(t_info *info);

void	ft_free_texture_paths(t_map *map);

void	ft_clean_up_window(t_info *info);

void	ft_clean_up_map(t_info *info);

#endif
