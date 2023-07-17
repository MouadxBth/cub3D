/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:08:49 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/14 15:43:20 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_COLOR_H
# define CUB3D_COLOR_H

int		ft_is_valid_rgb(int color);

int		ft_get_red(int color);

int		ft_get_green(int color);

int		ft_get_blue(int color);

int		ft_get_opacity(int color);

int		ft_mix_color(int r, int g, int b, int a);

float	ft_lerp_percentage(int start, int end, int current);

int		ft_lerp(int start, int end, float percentage);

int		ft_scale_color(int color, int amount);

int		ft_scale_red(int color, int amount);

int		ft_scale_green(int color, int amount);

int		ft_scale_blue(int color, int amount);

#endif
