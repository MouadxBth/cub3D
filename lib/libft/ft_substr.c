/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:54:14 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/19 09:19:53 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* beware of the boundry checking we do on line 24 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*ss;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		start = l;
	if (len > l - start)
		len = l - start;
	ss = ft_calloc(len + 1, sizeof(*ss));
	if (ss)
		ft_memcpy(ss, s + start, len);
	return (ss);
}
