/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:23:51 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/19 16:41:13 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_INIT_H
# define CUB3D_INIT_H

void	ft_initialize_map(char *file, t_info *info);
void	ft_initialize_player(t_info *info);
void	ft_init_ray_options(t_info *info);
void	ft_center_elements(t_info *info);
void	ft_init_info_window(t_info *info);

void	ft_initialize_raycaster(t_info *info);

int	ft_initialize_textures(t_info *info);

#endif
