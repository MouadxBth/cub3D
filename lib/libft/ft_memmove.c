/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:40:57 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/18 08:48:43 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* memory-overlap aware version of memcpy */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;	
	char		*d;	

	s = (char *)src;
	d = (char *)dst;
	if (d == s)
		return (NULL);
	while (s < d && len--)
		*(d + len) = *(s + len);
	while (s >= d && len--)
		*(d++) = *(s++);
	return (dst);
}
