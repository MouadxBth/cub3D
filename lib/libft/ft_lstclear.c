/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:24:50 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/19 10:54:25 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*hlst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		hlst = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = hlst;
	}
}
