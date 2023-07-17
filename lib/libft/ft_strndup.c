/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:12:24 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/21 00:12:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t l)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s1);
	if (len < l)
		l = len;
	p = ft_calloc(l + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, l);
	return (p);
}
