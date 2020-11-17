/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:26:24 by rcabezas          #+#    #+#             */
/*   Updated: 2020/11/17 18:51:41 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color     suma_color(t_color color1, t_color color2)
{
    t_color color;
    
    color.r = color1.r + color2.r;
    if (color.r > 255)
        color.r = 255;
    color.g = color1.g + color2.g;
    if (color.g > 255)
        color.g = 255;
    color.b = color1.b + color2.b;
    if (color.b > 255)
        color.b = 255;
    return (color);
}

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
    c1.r = (c1.r / 255) * (c2.r / 255) * 255;
    c1.g = (c1.g / 255) * (c2.g / 255) * 255;
    c1.b = (c1.b / 255) * (c2.b / 255) * 255;
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
