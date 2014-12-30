/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:06:41 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/05 18:05:20 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_copy;

	s_copy = (char *)s + ft_strlen(s);
	while (s_copy >= s)
		if (*s_copy == (char)c)
			return (s_copy);
		else
			s_copy--;
	return (NULL);
}
