/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:12:14 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/05 19:07:21 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		s2_len;

	s2_len = ft_strlen(s2);
	while (*s1)
	{
		if (!ft_memcmp(s1, s2, s2_len))
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
