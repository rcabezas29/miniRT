/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:23:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 21:39:01 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	inten(float intensity, t_color color)
{
	color.r *= intensity;
	color.g *= intensity;
	color.b *= intensity;
	return (color);
}

t_color	raytrace_light(t_minirt *r)
{
	t_color		c;
	t_ray		light_ray;
	t_list		*tmp_lights;
	t_object	*l;
	float		dot;

	tmp_lights = r->light_list;
	c = ambient_light(r);
	r->normal = get_normal(r);
	while (tmp_lights)
	{
		l = tmp_lights->content;
		light_ray = init_light_ray(r, l);
		dot = -1 * dot_product(r->normal, light_ray.dir);
		r->obj->id == 5 ? dot = -dot : 0;
		if (dot <= 0)
		{
			tmp_lights = tmp_lights->next;
			continue ;
		}
		dot = shadows(r, dot, light_ray);
		c = suma_color(c, color_mix(r->color, inten(l->ratio * dot, l->color)));
		tmp_lights = tmp_lights->next;
	}
	return (c);
}

t_color	ambient_light(t_minirt *r)
{
	t_color color;

	if (r->ambient.intensity == 0)
		color = create_rgb(0, 0, 0);
	else
		color = color_mix(r->obj->color,
			inten(r->ambient.intensity, r->ambient.color));
	return (color);
}

t_ray	init_light_ray(t_minirt *r, t_object *light)
{
	t_ray	light_ray;

	light_ray.origin = light->position;
	light_ray.dir =
		normalize_vec(resta_vec(r->inter_point, light->position));
	return (light_ray);
}
