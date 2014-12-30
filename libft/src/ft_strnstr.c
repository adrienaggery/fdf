/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:11:01 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/05 20:14:13 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	int			max_n;

	s2_len = ft_strlen(s2);
	max_n = n - s2_len;
	while (*s1 && max_n >= 0)
	{
		if (!ft_memcmp(s1, s2, s2_len))
			return ((char *)s1);
		max_n--;
		s1++;
	}
	return (NULL);
}
