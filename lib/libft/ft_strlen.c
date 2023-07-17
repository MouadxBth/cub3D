/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:24:52 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/07 08:44:15 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* this time let's do it a lil bit (or byte) differently */
size_t	ft_strlen(const char *s)
{
	const char	*ss;

	ss = s;
	while (*s)
			s++;
	return (((size_t)(s - ss)));
}
