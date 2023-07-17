/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:43:28 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/06 14:44:30 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* printable characters are everything but the control characters in ascii */
int	ft_isprint(int c)
{
	return ((c > 31 && c < 127));
}
