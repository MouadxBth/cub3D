/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:41:32 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/09 10:48:51 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cs;	
	size_t	tl;

	if (!s1 || !s2)
		return (NULL);
	tl = ft_strlen(s1) + ft_strlen(s2) + 1;
	cs = ft_calloc(tl, sizeof(char));
	if (!cs)
		return (NULL);
	ft_strlcpy(cs, s1, tl);
	ft_strlcat(cs, s2, tl);
	return (cs);
}
