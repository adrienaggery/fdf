/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:28:35 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/10 18:57:31 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*elt;

	elt = *alst;
	while (elt)
	{
		del(elt->content, elt->content_size);
		elt = elt->next;
	}
	free(*alst);
	*alst = NULL;
}
