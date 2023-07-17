/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:43:06 by mbouthai          #+#    #+#             */
/*   Updated: 2023/06/24 23:51:42 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_vector.h"
#include "libft.h"

void	ft_vector_rotate(t_vector *vector, float angle)
{
	float	old_x;

	old_x = vector->x;
	vector->x = old_x * cos(angle * M_PI / 180.0)
		- vector->y * sin(angle * M_PI / 180.0);
	vector->y = old_x * sin(angle * M_PI / 180.0)
		+ vector->y * cos(angle * M_PI / 180.0);
}

int	ft_count_chars(char *str, int c)
{
	int		result;
	int		index;

	if (!str)
		return (0);
	result = 0;
	index = -1;
	while (++index < (int)ft_strlen(str))
	{
		if (str[index] == c )
		{
			if ((str[index + 1] && str[index + 1] == ',') || !str[index + 1])
				return (0);
			index++;
			while (str[index] && ft_isspace(str[index]))
				index++;
			if (str[index] == ',' || !str[index])
				return (0);
			result++;
		}
	}
	return (result);
}
