/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:34:01 by bavram            #+#    #+#             */
/*   Updated: 2017/12/02 14:43:23 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*list;
	t_list	*next;

	list = NULL;
	while (lst != NULL)
	{
		next = (*f)(lst);
		if (list == NULL)
		{
			head = next;
			list = next;
		}
		else
		{
			list->next = next;
			list = next;
		}
		lst = lst->next;
	}
	return (head);
}
