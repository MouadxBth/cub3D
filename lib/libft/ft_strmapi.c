/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:20:26 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/10 11:22:09 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	long long	l;
	char		*rs;

	if (!s || !f)
		return (NULL);
	l = (long long)ft_strlen(s);
	rs = ft_calloc(l-- + 1, sizeof(*rs));
	if (!rs)
		return (NULL);
	rs += l;
	while (l >= 0)
	{
		*(rs--) = f((unsigned int) l, s[l]);
		l--;
	}
	return (rs + 1);
}
