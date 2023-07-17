/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:30:23 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/16 14:20:01 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	sze;

	sze = ft_lstsize(lst);
	if (sze == 0)
		return (NULL);
	while (--sze)
		lst = lst->next;
	return (lst);
}
