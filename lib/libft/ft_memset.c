/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:41:56 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/07 08:47:04 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* simply set `len` bytes of string pointed to by `b` to `c` */
void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((char *)b)[len] = (unsigned char)c;
	return (b);
}
