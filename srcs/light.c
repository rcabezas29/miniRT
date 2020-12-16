/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:23:33 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/16 21:13:46 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	apply_intensity(float intensity, t_color color)
{
	color.r *= intensity;
	color.g *= intensity;
	color.b *= intensity;
	return (color);
}

t_color	raytrace_light(t_minirt *r)
{
	t_color		color;
	t_ray		light_ray;
	t_list		*tmp_lights;
	t_object	*light;
	float		dot;

	tmp_lights = r->light_list;
	color = ambient_light(r);
	r->normal = get_normal(r);
	while (tmp_lights)
	{
		light = tmp_lights->content;
		light_ray.origin = light->position;
		light_ray.dir =
			normalize_vec(resta_vec(r->inter_point, light->position));
		dot = -1 * dot_product(r->normal, light_ray.dir);
		r->obj->id == 5 || r->obj->id == 4 ? dot = -dot : 0;
		if (dot <= 0)
		{
			tmp_lights = tmp_lights->next;
			continue ;
		}
		dot = shadows(r, dot, light_ray);
		color = suma_color(color, color_mix(r->color,
			apply_intensity(light->ratio * dot, light->color)));
		tmp_lights = tmp_lights->next;
	}
	return (color);
}

t_color	ambient_light(t_minirt *r)
{
	t_color color;

	if (r->ambient.intensity == 0)
		color = create_rgb(0, 0, 0);
	else
		color = color_mix(r->obj->color,
			apply_intensity(r->ambient.intensity, r->ambient.color));
	return (color);
}
