/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:18:16 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/16 14:15:08 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sum;
	int	sgn;
	int	inx;

	sum = 0;
	sgn = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn *= -1;
		str++;
	}
	inx = 0;
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - 48);
		if (inx >= 19)
			return (-(sgn > 0));
		inx++;
		str++;
	}
	return (sum * sgn);
}
