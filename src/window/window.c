/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:45:46 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 08:48:00 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_window.h"

/**
 * Frees the resources associated with the given window.
 *
 * @param window Pointer to the t_window structure to be freed.
 *
 * @return void
 */
int	ft_free_window(t_window *window)
{
	int	result;

	if (!window || !window->mlx || !window->id)
		return (0);
	result = mlx_destroy_window(window->mlx, window->id);
	free(window->images);
	window->images = NULL;
	return (result);
}

/**
 * Creates a new window with the specified width and height.
 *
 * @param width Width of the window to be created.
 * @param height Height of the window to be created.
 *
 * @return Pointer to the t_window structure representing the
 * newly created window.
 * Returns NULL if the creation of the window failed.
 */
void	ft_new_window(t_window *window, int width, int height)
{
	window->width = width;
	window->height = height;
	window->current_img = 0;
	window->mlx = mlx_init();
	if (!window->mlx)
	{
		ft_free_window(window);
		return ;
	}
	window->id = mlx_new_window(window->mlx, width, height, "Cub3D");
	window->images = (t_image *)malloc(sizeof(t_image) * 2);
	if (!window->images)
		return ;
	window->images[0].id = NULL;
	window->images[1].id = NULL;
}
