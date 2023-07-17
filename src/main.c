/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:47:07 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 09:53:13 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_color.h"
#include "cub3d_info.h"
#include "cub3d_init.h"
#include "cub3d_parser.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		return (printf("Usage:\n %s <the .cub file>\n", argv[0]), 1);
	ft_initialize_map(argv[1], &info);
	ft_init_info_window(&info);
	if (ft_initialize_textures(&info))
		return (printf("Invalid xpm file\n"), 
			ft_clean_up_map(&info),
			ft_clean_up_window(&info), 1);
	ft_initialize_player(&info);
	ft_print_map(&info.map);
	ft_center_elements(&info);
	ft_init_ray_options(&info);
	ft_initialize_raycaster(&info);
	ft_initialize_rendering_info(&info);
	ft_start(&info);
	return (0);
}
