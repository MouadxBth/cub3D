/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:30:54 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/23 18:50:01 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_texture.h"
#include <stdio.h>

int	ft_load_texture(t_texture *texture, void *mlx, char *path)
{
	t_image	current;
	int		x;
	int		y;
	int		*data;

	if (!ft_load_image(&current, mlx, path))
		return (1);
	texture->width = current.width;
	texture->height = current.height;
	texture->data = (int *)malloc(sizeof(int) * (texture->width
				* texture->height));
	if (!texture->data)
		return (0);
	ft_bzero(texture->data, texture->height * texture->width);
	data = (int *)current.address;
	y = -1;
	while (++y < current.height)
	{
		x = -1;
		while (++x < current.width)
			texture->data[current.width * y + x] = data[current.width * y + x];
	}
	mlx_destroy_image(mlx, current.id);
	return (0);
}

void	ft_print_texture(t_texture *texture)
{
	int	x;
	int	y;

	y = -1;
	while (++y < texture->height)
	{
		x = -1;
		while (++x < texture->width)
			printf("%d ", texture->data[texture->width * y + x]);
		printf("\n");
	}
}

void	ft_custom_texture(t_texture *texture, int color)
{
	int	index;

	texture->width = 64;
	texture->height = 64;
	texture->data = (int *)malloc(sizeof(int) * (texture->width
				* texture->height));
	index = -1;
	while (++index < (texture->width * texture->height))
		texture->data[index] = color;
}
