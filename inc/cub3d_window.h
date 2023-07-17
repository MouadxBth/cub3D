/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_window.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:35:13 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 23:16:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_WINDOW_H
# define CUB3D_WINDOW_H

# include "cub3d_map.h"
# include <mlx.h>

typedef struct s_image
{
	void	*id;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_window
{
	void	*mlx;
	void	*id;
	int		width;
	int		height;
	int		current_img;
	t_image	*images;
}			t_window;

void		ft_clear_image(t_image *img, int width, int height);
void		ft_fill_image(t_image *img, int color, int width, int height);

int			ft_free_image(void *mlx, t_image *img);
int			ft_free_window(t_window *window);

int			ft_is_valid_image(t_image *img);
int			ft_is_point_in_image(t_point *point, t_image *img);
int			ft_collision(t_point *first, t_point *second);

int			ft_new_image(t_image *img, void *mlx, int width, int height);

void		ft_new_window(t_window *window, int width, int height);

int			ft_load_image(t_image *result, void *mlx, char *path);

#endif
