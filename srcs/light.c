/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:23:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/10/15 12:16:32 by rcabezas         ###   ########.fr       */
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
    t_color color;
    t_list  *tmp_light;
    t_list  *tmp_obj;
    t_object    *light;
    t_ray       light_ray;

    r->b = 2147483647;
    tmp_light = malloc(sizeof(t_list));
    tmp_obj = malloc(sizeof(t_list));
    tmp_light = r->light_list;
    tmp_obj = r->object_list;
    if (r->ambient.intensity == 0)
        color = create_rgb(0, 0, 0);
    else
        color = color_mix(r->obj->color, apply_intensity(r->ambient.intensity, r->ambient.color));
    while (tmp_light)
    {
        light = tmp_light->content;
        light_ray.dir = normalize_vec(resta_vec(r->inter_point, light->position));
        light_ray.origin = light->position;
        while (tmp_obj)
        {
            light_intersect(r, tmp_obj->content, light_ray);
            color = apply_light(r, light_ray, tmp_light->content, tmp_obj->content, color);
            tmp_obj = tmp_obj->next;
        }
        tmp_light = tmp_light->next;
    }
    return (color);
}

void    light_intersect(t_minirt *r, t_object *obj, t_ray light_ray)
{
    if (obj->id == 1)
		sphere_s(r, obj, light_ray);
	else if (obj->id == 2)
		plane_s(r, obj, light_ray);
    else if (obj->id == 3)
		square_s(r, obj, light_ray);
	else if (obj->id == 4)
		cylinder_s(r, obj, light_ray);
	else if (obj->id == 5)
		triangle_s(r, obj, light_ray);
}

t_color    apply_light(t_minirt *r, t_ray light_ray, t_object *light, t_object *obj, t_color ori_color)
{
    float   light_ray_length;
    t_color color;
    t_color l_color;

    color = ori_color;
    light_ray_length = vector_length(resta_vec(r->inter_point, light_ray.origin));
    if (light_ray_length > r->b + 0.005)
        color =  ori_color;
    else if (r->b != 2147483647)
    {
        l_color = apply_intensity(light->ratio, light->color);
        color = color_mix(obj->color, l_color);
        color = apply_attenuation(r, color);
    }
    return (color);
}
