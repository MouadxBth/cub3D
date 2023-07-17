/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:24:28 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/10 11:54:25 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char *))
{
	unsigned int	inx;

	inx = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(inx++, (char *)s++);
}
