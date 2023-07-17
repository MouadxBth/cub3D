/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:06:32 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/18 08:48:57 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* copy `n` bytes from memory location pointed 
 * to by `src` to memory location pointed to by `dest` */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	if (d == s)
		return (NULL);
	while (n--)
		*(d++) = *(s++);
	return (dst);
}
