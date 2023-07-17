/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:01:55 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/08 16:25:09 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;		
	char	*p;

	len = ft_strlen(s1);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len + 1);
	return (p);
}
