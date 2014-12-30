/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 12:05:47 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/11 16:00:29 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*first;
	t_list		*elt;

	first = f(lst);
	lst = lst->next;
	while (lst)
	{
		elt = f(lst);
		ft_lstaddback(first, elt);
		lst = lst->next;
	}
	return (first);
}
