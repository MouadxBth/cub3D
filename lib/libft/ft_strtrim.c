/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:58:41 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/18 09:09:37 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* beware of line 29,  we add 2 instead of 1 because 
 * simply offest 6 minus offset 4 equals 2 instead of 3*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1e;
	char	*trs;

	if (!s1 || !set)
		return (NULL);
	s1e = (char *)s1 + (ft_strlen(s1) - 1);
	while (ft_strchr(set, *s1))
			s1++;
	while (ft_strchr(set, *s1e))
			s1e--;
	if (s1e < (char *)s1)
		return (ft_strdup(""));
	trs = ft_calloc((s1e - s1 + 2), sizeof(char));
	if (!trs)
		return (NULL);
	ft_memcpy(trs, s1, s1e - s1 + 1);
	return (trs);
}
