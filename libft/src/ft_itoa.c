/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaggery <aaggery@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:38:36 by aaggery           #+#    #+#             */
/*   Updated: 2014/11/10 11:24:11 by aaggery          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		nb_asize(int nb)
{
	size_t		i;

	i = 0;
	if (nb < 0 || nb == 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char			*max_int(void)
{
	char	*s;

	if (!(s = ft_strnew(11)))
		return (NULL);
	s[0] = '-';
	s[1] = '2';
	s[2] = '1';
	s[3] = '4';
	s[4] = '7';
	s[5] = '4';
	s[6] = '8';
	s[7] = '3';
	s[8] = '6';
	s[9] = '4';
	s[10] = '8';
	return (s);
}

char				*ft_itoa(int n)
{
	char		*s;
	size_t		size;
	size_t		i;

	if (n == -2147483648)
		return (max_int());
	size = nb_asize(n);
	i = 0;
	if (!(s = ft_strnew(size)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
		i = 1;
	}
	while (size-- > i)
	{
		s[size] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}
