/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bavram <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:41:28 by bavram            #+#    #+#             */
/*   Updated: 2017/12/02 14:58:01 by bavram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*next;

	list = *alst;
	while (list != NULL)
	{
		(*del)(list->content, list->content_size);
		next = list->next;
		free(list);
		list = next;
	}
	*alst = NULL;
}
