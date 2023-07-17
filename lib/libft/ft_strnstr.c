/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:55:10 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/19 10:28:20 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ih;
	size_t	in;

	if (!*needle)
		return ((char *)haystack);
	if (!len && !haystack)
		return ((char *)haystack);
	else if (!len)
		return (NULL);
	ih = 0;
	while (haystack[ih])
	{
		in = 0;
		while (ih + in < len && haystack[ih + in] == needle[in] && needle[in])
		{
			in++;
			if (needle[in] == '\0')
				return ((char *)&haystack[ih]);
		}
		ih++;
	}
	return (NULL);
}
