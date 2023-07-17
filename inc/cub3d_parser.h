/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:34:58 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 18:18:15 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H

# include "cub3d.h"
# include "cub3d_map.h"

void	ft_extension_check(char *file, char *ext);

int		ft_map_elems_check(t_map *cub, int map);

void	ft_yell_err(char	*err, char **lines);

void	ft_resolve_textures(char *s, t_map *cub);

void	ft_resolve_floorceiling(char *s, t_map *cub);

void	ft_resolve_map(char **lines, t_map *cub);

int		set_int(int *integer, int value);

void	fre2d(char **strs);

void	ft_map(char	*file, t_map *map);

void	ft_check(char **str, char *src, int length);

#endif
