/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:42:58 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/18 08:57:53 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* calculate how many strings we have in `s` to 
 * allocate the right amount of pointer variables */
static size_t	ft_nump(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			n += 1;
		while (*s != c && *s)
			s++;
	}
	return (n);
}
/* free all allocations if an error occurs */

static void	*ft_freres(char	**strs, size_t l)
{				
	long long	n;

	n = (long long)l;
	while (n >= 0)
		free(strs[n--]);
	free(strs);
	return (NULL);
}
/* allocate sufficient memory for each trimmed string from `s` */
/* and copy it there, additionally null the last pointer */

static char	**ft_strput(char const *s, char c, char **strs, size_t np)
{
	size_t	inx;		
	size_t	len;		
	char	*sh;

	inx = 0;
	len = 0;
	while (*s && inx < np)
	{
		while (*s && *s == c)
			s++;
		sh = (char *)s;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		strs[inx] = ft_calloc(len + 1, sizeof(**strs));
		if (!strs[inx])
			return (ft_freres(strs, inx));
		ft_memcpy(strs[inx], sh, len);
		len = 0;
		inx++;
	}
	return (strs);
}
/* where all the magic happens :) */

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	np;

	if (!s)
		return (NULL);
	np = ft_nump(s, c);
	strs = ft_calloc(np + 1, sizeof(*strs));
	if (!strs)
		return (NULL);
	ft_strput(s, c, strs, np);
	if (!strs)
		return (NULL);
	return (strs);
}
