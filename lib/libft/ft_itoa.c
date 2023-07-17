/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:06:27 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/13 11:02:06 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* calculate the needed len for the string*/
static size_t	ft_callen(int n)
{
	size_t	l;

	l = 0;
	if (n < 0)
	{
		n *= -1;
		l++;
	}
	while (n > 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}	

char	*ft_itoa(int n)
{
	size_t	l;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	l = ft_callen(n);
	s = ft_calloc(l + 1, sizeof(*s));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[--l] = 48 + (n % 10);
		n /= 10;
	}
	return (s);
}
