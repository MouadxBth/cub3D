/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:03:57 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/22 11:34:08 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_dupextnd(char *src, size_t len, char	*ssrc, int rel)
{
	char	*dst;
	char	*s;
	char	*d;

	dst = (char *)ft_calloc1(len + 1, sizeof(*dst));
	s = src;
	d = dst;
	if (dst)
	{
		while (*src && len--)
			*(dst++) = *(src++);
		if (rel)
		{
			if (ssrc)
				free (ssrc);
			else
				free(s);
		}
	}
	return (d);
}

char	*my_strchr(char	*s, char c)
{
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				return (s);
			s++;
		}
	}
	return (NULL);
}

void	*ft_calloc1(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p)
	{
		while (count--)
			((char *)p)[count] = 0;
	}
	return (p);
}

char	*ft_condret(size_t b8rd, char **tbp)
{
	char	*lin;

	if (b8rd && *tbp)
	{
		if (*(*tbp))
		{
			lin = *tbp;
			*tbp = NULL;
			return (lin);
		}
	}
	free(*tbp);
	return (*tbp = NULL);
}
