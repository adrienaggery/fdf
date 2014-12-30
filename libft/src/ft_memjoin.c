/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 16:18:45 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/16 19:17:35 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *block1, size_t size1, void *block2, size_t size2)
{
	char	*new_block;

	new_block = (char *)malloc(sizeof(char) * (size1 + size2));
	if (new_block == NULL)
		return (NULL);
	if (block1 == NULL && block2 == NULL)
		return ((void *)ft_strnew(0));
	else if (block1 == NULL)
		return (ft_memcpy(new_block, block2, size2));
	else if (block2 == NULL)
		return (ft_memcpy(new_block, block1, size1));
	else
	{
		ft_memcpy(new_block, block1, size1);
		ft_memcpy(&new_block[size1], block2, size2);
		return ((void *)new_block);
	}
}
