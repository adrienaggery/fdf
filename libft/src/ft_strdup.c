/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:38:26 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/04 22:30:55 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;
	char	*s1_copy_addr;

	s1_copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s1_copy)
		return (NULL);
	s1_copy_addr = s1_copy;
	while (*s1)
		*s1_copy++ = *s1++;
	*s1_copy = '\0';
	return (s1_copy_addr);
}
