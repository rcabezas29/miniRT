/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:26:24 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/07 11:21:24 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		create_rgb(int r, int g, int b)
{
    t_color color;
    
    color.r = r;
    color.g = g;
    color.b = b;
	return (color);
}

t_color     color_mix(t_color c1, t_color c2)
{
    c1.r = (c1.r + c2.r) / 2;
    c1.g = (c1.g + c2.g) / 2;
    c1.b = (c1.b + c2.b) / 2;
    return (c1);
}

void        color_put(t_minirt *r, int x, int y)
{
    int i;

    i = y * r->camera->image.line_length + r->camera->image.bpp / 8 * x;
    r->camera->image.addr[i] = r->color.b;
    r->camera->image.addr[i + 1] = r->color.g;
    r->camera->image.addr[i + 2] = r->color.r;
}
