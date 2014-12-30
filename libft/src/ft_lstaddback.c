/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:28:03 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/11 15:36:26 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstaddback(t_list *elt, t_list *new)
{
	if (!elt)
		return (NULL);
	while (elt->next)
		elt = elt->next;
	elt->next = new;
	return (elt);
}
