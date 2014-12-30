/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 12:30:56 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/08 15:46:05 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	s = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (s && s1 && s2)
	{
		ft_strcat(s, s1);
		ft_strcat(s, s2);
		return (s);
	}
	return (NULL);
}
