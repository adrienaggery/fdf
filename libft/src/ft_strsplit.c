/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 23:47:50 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/21 23:33:57 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strclen(char const *s, char c)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t		count_words(char const *s, char c)
{
	size_t		counter;

	if (!s)
		return (0);
	counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			counter++;
			s += ft_strclen(s, c);
		}
		else
			s++;
	}
	return (counter);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		array_size;
	size_t		word_size;
	size_t		i;
	char		**split_array;

	i = 0;
	array_size = count_words(s, c);
	split_array = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!split_array)
		return (NULL);
	while (i < array_size)
	{
		while (*s == c)
			s++;
		word_size = ft_strclen(s, c);
		split_array[i] = ft_strsub(s, 0, word_size);
		s += word_size;
		i++;
	}
	split_array[array_size] = NULL;
	return (split_array);
}
