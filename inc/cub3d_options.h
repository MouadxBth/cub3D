/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_options.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:16:43 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/21 12:24:20 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_OPTIONS_H
# define CUB3D_OPTIONS_H

typedef struct s_options
{
	int		scale;
	int		color;
	int		row_gap;
	int		column_gap;
	int		x_offset;
	int		y_offset;
	float	angle;
}			t_options;

#endif
