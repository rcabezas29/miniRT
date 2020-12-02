/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:36:20 by rcabezas          #+#    #+#             */
/*   Updated: 2020/12/02 17:31:55 by rcabezas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	shadows(t_minirt *r, float dot, t_ray light_ray)
{
	t_list *tmp;

	tmp = r->object_list;
	r->b = 2147483647;
	while (tmp)
	{
		objs_intersect_light(r, tmp->content, light_ray);
		tmp = tmp->next;
	}
	if (r->b + 1 < vector_length(resta_vec(light_ray.origin, r->inter_point)))
		dot = 0.01;
	return (dot);
}

void	objs_intersect_light(t_minirt *r, t_object *obj, t_ray light_ray)
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
