/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:33:14 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/12 16:14:50 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(s + len) == (char) c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
