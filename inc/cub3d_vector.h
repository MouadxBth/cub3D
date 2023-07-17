/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_vector.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:40:09 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/07 23:06:42 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_VECTOR_H
# define CUB3D_VECTOR_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vector
{
	float		x;
	float		y;
}			t_vector;

void	ft_vector_rotate(t_vector *vector, float angle);

int	ft_count_chars(char *str, int c);

#endif
