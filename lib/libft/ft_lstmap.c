/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnadir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:34:56 by mnadir            #+#    #+#             */
/*   Updated: 2022/10/12 14:10:43 by mnadir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*olst;
	t_list	*nlst;

	olst = NULL;
	while (lst)
	{
		nlst = ft_lstnew(f(lst->content));
		if (!nlst)
		{
			ft_lstclear(&olst, del);
			return (NULL);
		}
		ft_lstadd_back(&olst, nlst);
		nlst->next = NULL;
		lst = lst->next;
	}
	return (olst);
}
