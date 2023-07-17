/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:52:52 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/07 14:12:32 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* this function always return anything less than or equal to `sze` */
size_t	ft_strnlen(const char *s, size_t sze)
{
	size_t	len;

	len = 0;
	while (len++ < sze && *s)
			s++;
	return (len - 1);
}
/* 1st of all we check if we have enough space and if we don't 
 * we just return the string's length we tried to create */
/* and all that follows after is checking wether
 * we should truncate `src` or not */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;	

	slen = ft_strlen(src);
	dlen = ft_strnlen(dst, dstsize);
	if (dlen == dstsize)
		return (dlen + slen);
	if (slen + 1 < dstsize - dlen)
		ft_memcpy(dst + dlen, src, slen + 1);
	else
	{	
		ft_memcpy(dst + dlen, src, dstsize - dlen - 1);
		dst[dstsize - 1] = 0;
	}
	return (slen + dlen);
}
