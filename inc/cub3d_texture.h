/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_texture.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:26:28 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/21 14:56:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TEXTURE_H
# define CUB3D_TEXTURE_H

# include "cub3d.h"
# include "cub3d_window.h"
# include <mlx.h>

typedef struct s_texture
{
	int	*data;
	int	width;
	int	height;
}	t_texture;

int	ft_load_texture(t_texture *texture, void *mlx, char *path);

void	ft_print_texture(t_texture *texture);

void	ft_custom_texture(t_texture *texture, int color);

#endif
