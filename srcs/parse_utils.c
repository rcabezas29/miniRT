/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 09:13:32 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/15 18:37:59 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
 		i++;
	}
	free(split);
	split = NULL;
}

t_color	split_rgb(char *rgb)
{
	t_color	c;
	char	**split;

	split = ft_split(rgb, ',');
	c.r = ft_atof(split[0]);
	c.g = ft_atof(split[1]);
	c.b = ft_atof(split[2]);
	free_split(split);
	return (c);
}

t_vec	split_vec(char *vec)
{
	t_vec	v;
	char	**split;

	split = ft_split(vec, ',');
	v.x = ft_atof(split[0]);
	v.y = ft_atof(split[1]);
	v.z = ft_atof(split[2]);
	free_split(split);
	return (v);
}
