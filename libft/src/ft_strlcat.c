/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:29:24 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/05 16:31:32 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		src_len;
	int			i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = size - dst_len;
	if (i <= 0)
		return (src_len + size);
	while (*src && --i > 0)
	{
		dst[size - i - 1] = *src;
		src++;
	}
	dst[size - 1] = '\0';
	return (dst_len + src_len);
}
