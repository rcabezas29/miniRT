/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:23:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/28 20:51:22 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color     apply_intensity(float intensity, t_color color)
{
    color.r *= intensity;
    color.g *= intensity;
    color.b *= intensity;
    return (color);
}

t_color     raytrace_light(t_minirt *r)
{
    t_vec   normal;
    t_color color;
    t_ray   light_ray;
    t_list  *tmp_lights;
    t_object *light;
    float   dot;
    
    
    tmp_lights = r->light_list;
    if (r->ambient.intensity == 0)
        color = create_rgb(0, 0, 0);
    else
        color = color_mix(r->obj->color, apply_intensity(r->ambient.intensity, r->ambient.color));
    normal = get_normal(r);
    while (tmp_lights)
    {
        light = tmp_lights->content;
        light_ray.origin = light->position;
        light_ray.dir = normalize_vec(resta_vec(r->inter_point, light->position));
        dot = dot_product(normal, light_ray.dir);
        if (r->obj->id == 1)
            dot = -dot;
        if (dot <= 0)
		{
			tmp_lights = tmp_lights->next;
			continue ;
		}
        color = suma_color(color, color_mix(r->color, apply_intensity(light->ratio * dot, light->color)));
		tmp_lights = tmp_lights->next;
    }
    return (color);
}
