/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:03:47 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/05 14:17:15 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s1_copy;

	s1_copy = s1 + ft_strlen(s1);
	while (*s2 && n--)
		*s1_copy++ = *s2++;
	*s1_copy = '\0';
	return (s1);
}
