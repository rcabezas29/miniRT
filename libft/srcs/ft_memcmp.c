/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:29:25 by rcabezas          #+#    #+#             */
/*   Updated: 2019/11/13 20:29:57 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*q;
	unsigned char	*p;
	size_t			i;

	q = (unsigned char *)str1;
	p = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (q[i] != p[i])
			return (q[i] - p[i]);
		i++;
	}
	return (0);
}
