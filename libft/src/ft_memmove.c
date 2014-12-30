/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:39:47 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/04 20:27:19 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_copy;
	char	*src_copy;

	dst_copy = (char *)dst;
	src_copy = (char *)src;
	if (src_copy <= dst_copy)
	{
		dst_copy += len - 1;
		src_copy += len - 1;
		while (len--)
			*dst_copy-- = *src_copy--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
