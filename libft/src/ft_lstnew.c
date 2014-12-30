/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:30:49 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/11 16:50:50 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elt;

	elt = (t_list *)malloc(sizeof(t_list));
	if (!elt)
		return (NULL);
	if (content)
	{
		elt->content = malloc(content_size);
		if (!(elt->content))
			return (NULL);
		ft_memcpy(elt->content, content, content_size);
		elt->content_size = content_size;
	}
	else
	{
		elt->content = NULL;
		elt->content_size = 0;
	}
	elt->next = NULL;
	return (elt);
}
